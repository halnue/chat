//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/server.h"

bool sqlTransaction(char *sql) {
    bool result = false;
    pthread_mutex_lock(&clients_mutex);

    sqlite3 *db;
    db = openDB(DB);
    if (db != NULL) {
        int rc = dbRequest(db, sql);
        if (rc != false) result = true;
    }
    sqlite3_close(db);
    pthread_mutex_unlock(&clients_mutex);
    return result;
}