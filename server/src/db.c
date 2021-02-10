//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/server.h"

static int callbackLogin(void *data, int argc, char **argv, char **azColName);

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
    sqlTransactionCall(sql, mutex, callbackLogin, data);
}

void command_message(char *message, client_t *cli, pthread_mutex_t mutex) {
    long lTime = time(NULL);
    char *sql = insertMessageSQL(create_message(cli->uid,message,lTime));
    sqlTransaction(sql, mutex);
    if (sqlTransaction(sql, mutex)){
        send_command(new_message(COMMAND_RESPONSE_SERVER_MESSAGE, RESPONSE_406, "The message can't be saved"), cli->sockfd);
    } else{
        send_command(new_message(COMMAND_RESPONSE_SERVER_MESSAGE, RESPONSE_200, ""), cli->sockfd);
        send_messages(notify_message(COMMAND_NOTIFY_SERVER_NEW_MESSAGE,cli->name,message,lTime),cli->uid);
    }
}

void command_register(char *login, char *password, int userSocket, pthread_mutex_t mutex) {
    char *sql = insertUsersSQL(login,password);
    printf("%s\n",sql);
    if (sqlTransaction(sql, mutex)){
        send_command(new_message(COMMAND_RESPONSE_SERVER_REGISTER, RESPONSE_406, "This login is used"), userSocket);
    } else{
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

char * str_trim_lf1(char *arr) {
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
    printf("%s %s\n",login,password);
    printf("%s %s\n",login,password);
    printf("socket %d \n",cli->sockfd);
    if (mx_strlen(argv[0]) == 0) {
        send_command(new_message(COMMAND_RESPONSE_SERVER_LOGIN, RESPONSE_404, "Invalid login"), cli->sockfd);
    } else if (mx_strcmp(argv[0], password) == 0) {
        send_command(new_message(COMMAND_RESPONSE_SERVER_LOGIN, RESPONSE_200, login), cli->sockfd);
        cli->name = login;
        cli->uid = atoi(argv[1]);
    } else {
        send_command(new_message(COMMAND_RESPONSE_SERVER_LOGIN, RESPONSE_412, "Invalid password"), cli->sockfd);
    }
    return argc - argc + mx_strlen(azColName[0]?"":"0") - mx_strlen(azColName[0]?"":"0");
}



