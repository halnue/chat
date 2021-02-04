//
// Created by Mykhailo Burenko on 2/4/21.
//
#include "../inc/mDb.h"

sqlite3 *openDB(char *nameDB) {
    sqlite3 *db;
    int rc = sqlite3_open(nameDB, &db);
    if (rc) {
        mx_printerr("Can't open database: \n");
        mx_printerr(sqlite3_errmsg(db));
        return NULL;
    } else {
        return db;
    }
}
