#include <stdio.h>
#include <zconf.h>
#include "../inc/mDb.h"


void mx_printint(int num);
void mx_printchar(char c);
//static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//    int i;
//    *(int *)NotUsed = 0;
//    for(i = 0; i<argc; i++) {
//        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }
//    printf("\n");
//    return 0;
//}




int main() {
    sqlite3 *db;
    char *sql;

    db = openDB("users");
    if (db == NULL)
        return 22;

    sql = "CREATE TABLE Users("
          "    id INTEGER PRIMARY KEY NOT NULL,"
          "    login VARCHAR(20),"
          "    password VARCHAR(40)"
          ")";



    int rc = dbRequest(db,sql);
    if (rc == false)
        return 23;

    sqlite3_close(db);
    return 0;
}
