//
// Created by Mykhailo Burenko on 2/4/21.
//

#ifndef OWN_UCHAT_MDB_H
#define OWN_UCHAT_MDB_H

#include <sqlite3.h>
#include "../../utils/libmx/inc/libmx.h"
#include "../../utils/api.h"

#define INSERT_USER(id,login,password) "INSERT INTO Users(ID, LOGIN, PASSWORD) VALUES (id,login,password)"
#define quotes "
#define UPDATE_FIELD(table,fieldSet,wherePredicate) UPDATE table set fieldSet where wherePredicate

 sqlite3 *openDB(char *nameDB);
int dbRequest(sqlite3* db, const char *sql);

char *insertUsersSQL(int id,char *login,char *password){
    char *  s = quotes UPDATE_FIELD(User,password = "321",id = 0) quotes;
    return "INSERT INTO Users(ID, LOGIN, PASSWORD) VALUES ("id","login","password")";
}

//char *update

#endif //OWN_UCHAT_MDB_H
