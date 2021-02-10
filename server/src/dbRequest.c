#include <stdio.h>
#include "../inc/api_db.h"


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    *(int *)NotUsed = 0;
    for(i = 0; i<argc; i++) {
        mx_printerr("%s = %s\n");
        mx_printerr(azColName[i]);
        mx_printerr( argv[i] ? argv[i] : "NULL");
    }
    mx_printerr("\n");
    return 0;
}

int dbRequest(sqlite3* db, const char *sql){
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc == SQLITE_OK) {
        return true;
    } else {
        printf("SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    }
}

int dbRequestCall(sqlite3* db, const char *sql,int (*own_callback)(void*,int,char**,char**),void *data){
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db, sql, own_callback, data, &zErrMsg);

    if( rc != SQLITE_OK ){
        printf( "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    } else {
        return true;
    }
}


