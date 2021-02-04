#include "../inc/api_db.h"


//char *insertUsersSQL(int id,char *login,char *password){
//    char *insertion = "INSERT or REPLACE INTO tes(ID, LOGIN) VALUES ( ";
//    char *res = mx_strjoin(insertion, mx_itoa(id));
//    char *a = mx_strjoin(res, " , '");
//    char *b = mx_strjoin(a, login);
//    char *c = mx_strjoin(b, "' )");
////    char *d = mx_strjoin(c, password);
////    char *e = mx_strjoin(d, "')");
//    return c;
////    INSERT INTO Users(ID, LOGIN, PASSWORD) VALUES (-1,'admin','arr')
//}


int main() {
//    sqlite3 *db;
    char *sql;
    User *user;
    user = create_user(3, "querty", "12");
    Message *msg;
    long lt = time(NULL);
    msg = create_message(0, 0, "Fuck oracle!", lt);
//    db = openDB("users");
//    if (db == NULL)
//        return 22;
//
//    sql = "CREATE TABLE Users("
//          "    id INTEGER PRIMARY KEY NOT NULL,"
//          "    login VARCHAR(20),"
//          "    password VARCHAR(40)"
//          ")";
//    int rc = dbRequest(db, sql);
//    if (rc == false)
//        return 23;

    sql = insertUsersSQL(user);
    mx_printstr(sql);
    mx_printchar('\n');
    sql = insertMessageSQL(msg);
    mx_printstr(sql);
    mx_printchar('\n');
    sql = updateMessage(0, "Fuck, I hate oracle");
    mx_printstr(sql);
    mx_printchar('\n');
    sql = updatePassword(2, "123456");
    mx_printstr(sql);
    mx_printchar('\n');
    sql = deleteMessage(0);
    mx_printstr(sql);
    mx_printchar('\n');

//    rc = dbRequest(db, sql);
//    if (rc == false)
//        return 23;
//
//    sqlite3_close(db);
    return 0;
}
