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
        if (rc != false) result = true;
    }
    sqlite3_close(db);
    pthread_mutex_unlock(&mutex);
    return result;
}

void login(char *login, char *password, int userSocket, pthread_mutex_t mutex) {
    char *sql = getPasswordSQL(login);
    void **data = CREATE_SIZE(void *, 3)
    data[0] = &userSocket;
    data[1] = password;
    data[2] = login;
    sqlTransactionCall(sql, mutex, callbackLogin, data);
}

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
    int socket = *(int *) ((void **) data)[0];
    char *password = str_trim_lf1((char *) ((void **) data)[1]);
    char *login = str_trim_lf1((char *) ((void **) data)[2]);
    printf("%s %s",login,password);
    if (mx_strlen(argv[0]) == 0) {
        send_message(response(COMMAND_RESPONSE_SERVER_LOGIN, "404", "Invalid password"), socket);
    } else if (mx_strcmp(argv[0], password) == 0) {
        send_message(response(COMMAND_RESPONSE_SERVER_LOGIN, "200", login), socket);
    } else {
        send_message(response(COMMAND_RESPONSE_SERVER_LOGIN, "412", "Invalid password"), socket);
    }
    return argc - argc + mx_strlen(azColName[0]?"":"0") - mx_strlen(azColName[0]?"":"0");
}



