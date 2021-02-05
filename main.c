//#include <stdio.h>
//#include <zconf.h>
//#include "../inc/api_db.h"
//
//
////char *insertUsersSQL(int id,char *login,char *password){
////    char *insertion = "INSERT or REPLACE INTO tes(ID, LOGIN) VALUES ( ";
////    char *res = mx_strjoin(insertion, mx_itoa(id));
////    char *a = mx_strjoin(res, " , '");
////    char *b = mx_strjoin(a, login);
////    char *c = mx_strjoin(b, "' )");
//////    char *d = mx_strjoin(c, password);
//////    char *e = mx_strjoin(d, "')");
////    return c;
//////    INSERT INTO Users(ID, LOGIN, PASSWORD) VALUES (-1,'admin','arr')
////}
//char *insertUsersSQL(int id,char *login,char *password){
//    char* buff = (char*)malloc(sizeof(char)*131);
//    sprintf(buff, "%s %d %s %s %s %s %s","INSERT INTO Users(ID, LOGIN, PASSWORD) VALUES (", id, ",'", login, "','", password, "')");
//    return buff;
//}
//
//int main() {
//    sqlite3 *db;
//    char *sql;
//
//    db = openDB("users");
//    if (db == NULL)
//        return 22;
//
//    sql = "CREATE TABLE Users("
//          "    id INTEGER PRIMARY KEY NOT NULL,"
//          "    login VARCHAR(20),"
//          "    password VARCHAR(40)"
//          ")";
//
//sql = insertUsersSQL(3,"qwerty","12");
//mx_printstr(sql);
//mx_printchar('\n');
//
//    int rc = dbRequest(db,sql);
//    if (rc == false)
//        return 23;
//
//    sqlite3_close(db);
//    return 0;
//}

