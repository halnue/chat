//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/server.h"

static int callbackLogin(void *data, int argc, char **argv, char **azColName);

static int callbackMessage(void *data, int argc, char **argv, char **azColName);
//static int callbackMessageMaxIdDel(void *data, int argc, char **argv, char **azColName);
//static int callbackMessageMaxIdEdit(void *data, int argc, char **argv, char **azColName);

bool sqlTransaction(char *sql, pthread_mutex_t mutex) {
    bool result = false;
    pthread_mutex_lock(&mutex);

    sqlite3 *db;
    db = openDB(DB);
    if (db != NULL) {
        int rc = dbRequest(db, sql);
        if (rc == true) result = true;
    }
    sqlite3_close(db);
    pthread_mutex_unlock(&mutex);
    return !result;
}

void command_login(char *login, char *password, client_t *cli, pthread_mutex_t mutex) {
    char *sql = getPasswordSQL(login);
    void **data = CREATE_SIZE(void *, 3)
    data[0] = cli;
    data[1] = password;
    data[2] = login;
    cli->name = login;
    sqlTransactionCall(sql, mutex, callbackLogin, data);
}

void command_message(char *message, client_t *cli, pthread_mutex_t mutex) {
    long lTime = time(NULL);
    char *sql = insertMessageSQL(create_message(cli->uid, message, lTime));
//    sqlTransaction(sql, mutex);
    if (sqlTransaction(sql, mutex)) {
        send_command(new_message(COMMAND_RESPONSE_SERVER_MESSAGE, RESPONSE_406, "The message can't be saved"),
                     cli->sockfd);
    } else {
        send_command(new_message(COMMAND_RESPONSE_SERVER_MESSAGE, RESPONSE_200, ""), cli->sockfd);
        printf("message = %s ,user = %s ,time = %ld\n", message, cli->name, lTime);
        send_messages(notify_message(COMMAND_NOTIFY_SERVER_NEW_MESSAGE, cli->name, message, lTime), cli->sockfd);
    }
}

void command_edit(char *message, pthread_mutex_t mutex) {
    char *sql = updateMessageMaxId(message);
    sqlTransaction(sql, mutex);
}

void command_delete(pthread_mutex_t mutex) {
    sqlTransaction(DELETE_MESSAGE_MAX_ID, mutex);
}

void command_edit_u(char *message, pthread_mutex_t mutex,int i) {
    char *sql = updateMessageById(message,i);
    sqlTransaction(sql, mutex);
}

void command_delete_u(pthread_mutex_t mutex,int i) {
    char *sql = deleteMessageById(i);
    sqlTransaction(sql, mutex);
}

void command_send_all_message(int userSocket, pthread_mutex_t mutex) {
    void *data = &userSocket;
    sqlTransactionCall(GET_ALL_MESSAGE, mutex, callbackMessage, data);
}

void command_send_last_message(int userSocket, char *time, pthread_mutex_t mutex) {
    void *data = &userSocket;
    char *sql = getLastMessage(time);
    sqlTransactionCall(sql, mutex, callbackMessage, data);
}

void command_register(char *login, char *password, int userSocket, pthread_mutex_t mutex) {
    char *sql = insertUsersSQL(login, password);
    printf("%s\n", sql);
    if (sqlTransaction(sql, mutex)) {
        send_command(new_message(COMMAND_RESPONSE_SERVER_REGISTER, RESPONSE_406, "This login is used"), userSocket);
    } else {
        send_command(new_message(COMMAND_RESPONSE_SERVER_REGISTER, RESPONSE_200, login), userSocket);
    }
}

//void command_message(char *message, int uid, int userSocket, pthread_mutex_t mutex) {
//    char *sql = insertMessageSQL(create_message(uid,message,time(NULL)));
//    if (sqlTransaction(sql, mutex)){
//        send_command(message(COMMAND_RESPONSE_SERVER_MESSAGE, RESPONSE_406, "The message can't be saved"), userSocket);
//    } else{
//        send_command(message(COMMAND_RESPONSE_SERVER_MESSAGE, RESPONSE_200,""), userSocket);
//    }
//}

bool sqlTransactionCall(char *sql, pthread_mutex_t mutex, int (*callback)(void *, int, char **, char **), void *data) {
    bool result = false;
    pthread_mutex_lock(&mutex);

    sqlite3 *db;
    db = openDB(DB);
    if (db != NULL) {
        int rc = dbRequestCall(db, sql, callback, data);
        if (rc != false) result = true;
    }
    sqlite3_close(db);
    pthread_mutex_unlock(&mutex);
    return result;
}

char *str_trim_lf1(char *arr) {
    int i;
    for (i = 0; i < mx_strlen(arr); i++) { // trim \n
        if (arr[i] == '\n') {
            arr[i] = '\0';
            break;
        }
    }
    return arr;
}

static int callbackLogin(void *data, int argc, char **argv, char **azColName) {
    client_t *cli = (client_t *) ((void **) data)[0];
    char *password = str_trim_lf1((char *) ((void **) data)[1]);
    char *login = str_trim_lf1((char *) ((void **) data)[2]);
    printf("%s %s\n", login, password);
    printf("%s %s\n", login, password);
    printf("socket %d \n", cli->sockfd);
    if (mx_strlen(argv[0]) == 0) {
        send_command(new_message(COMMAND_RESPONSE_SERVER_LOGIN, RESPONSE_404, "Invalid login"), cli->sockfd);
        cli->name = "guest";
    } else if (mx_strcmp(argv[0], password) == 0) {
        send_command(new_message(COMMAND_RESPONSE_SERVER_LOGIN, RESPONSE_200, login), cli->sockfd);
        cli->uid = atoi(argv[1]);
        message_join_user(cli->name, cli->sockfd);
    } else {
        cli->name = "guest";
        send_command(new_message(COMMAND_RESPONSE_SERVER_LOGIN, RESPONSE_412, "Invalid password"), cli->sockfd);
    }
    return argc - argc + mx_strlen(azColName[0] ? "" : "0") - mx_strlen(azColName[0] ? "" : "0");
}

char *new_messageClient1(char *userName, char *message, char *time,bool edit);

static int callbackMessage(void *data, int argc, char **argv, char **azColName) {
    int *userSocket = data;
//    int size = 20 + 11 + 1 + 512;
//    char *buffer = mx_strnew(size);
    long time = atol(argv[1]);
    bool edit = atoi(argv[2]);
    char *sTime = mx_strnew(26);
    ctime_r(&time, sTime);
    char *buffer = new_messageClient1(argv[0], argv[3],sTime,edit);
//    sprintf(buffer, "%s|%s|%s|%s|%s\t", COMMAND_RESPONSE_SERVER_MESSAGE_LOAD_MESSAGE, argv[0], argv[1], argv[2], argv[3]);
    printf(" %s\n", buffer);
    usleep(10000);
    int receive = send(*userSocket, buffer, mx_strlen(buffer), 0);
    printf(" %s\n", buffer);
    printf("     %d     \n", receive);

    return argc - argc + mx_strlen(azColName[0] ? "" : "0") - mx_strlen(azColName[0] ? "" : "0");
}
//
//static int callbackMessageMaxIdEdit(void *data, int argc, char **argv, char **azColName) {
//    char *message = (char *)data;
//    pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
//    char *sql = updateMessage(atoi(argv[0]), message);
//    sqlTransaction(sql, clients_mutex);
//    return argc - argc + mx_strlen(azColName[0] ? "" : "0") - mx_strlen(azColName[0] ? "" : "0");
//}
//
//static int callbackMessageMaxIdDel(void *data, int argc, char **argv, char **azColName) {
//    pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
//    char *sql = deleteMessage(atoi(argv[0]));
//    sqlTransaction(sql, clients_mutex);
//    return (int *)data-(int *)data+argc - argc + mx_strlen(azColName[0] ? "" : "0") - mx_strlen(azColName[0] ? "" : "0");
//}

char *new_messageClient1(char *userName, char *message, char *time,bool edit) {
    char *buff = mx_strnew(600);
    if (edit)
        sprintf(buff,"%s (edit)> %s\n\033[34m   %s\033[0m", userName, message,time);
    else
        sprintf(buff,"%s > %s\n\033[34m   %s\033[0m", userName, message,time);
//        sprintf(buff,"%s > %s\n", userName, message);
//    sprintf("",time);
    return buff;
}
