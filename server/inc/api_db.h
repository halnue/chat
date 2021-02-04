//
// Created by Mykhailo Burenko on 2/4/21.
//

#ifndef OWN_UCHAT_API_DB_H
#define OWN_UCHAT_API_DB_H

#include <sqlite3.h>
#include "../../utils/libmx/inc/libmx.h"
#include "../../utils/api.h"
#include "string.h"
#include <stdio.h>
#include <zconf.h>
#include <time.h>

#define CREATE_TABLE_USERS "CREATE TABLE Users(id INTEGER PRIMARY KEY NOT NULL,login VARCHAR(20) NOT NULL,password VARCHAR(40) NOT NULL)"
#define CREATE_TABLE_MESSAGES "CREATE TABLE Messages(id INTEGER PRIMARY KEY NOT NULL,idUser  INTEGER             NOT NULL,Message VARCHAR(512)        NOT NULL,time    INTEGER(11)         NOT NULL,edit    BOOLEAN)"

sqlite3 *openDB(char *nameDB);

int dbRequest(sqlite3 *db, const char *sql);
User *create_user(int id, char *login, char *password);
Message *create_message(int id, int idUser, char *msg, long time);
char *insertUsersSQL(User *usr);
char *insertMessageSQL(Message *msg);//INSERT INTO Messages(id, idUser, Message, time, edit) VALUES (0,0,'Hello, Ucode!',1612451993,false)
char *updateMessage(int id,char *newMessage);//UPDATE Messages set edit = true,Message = 'Hello, Ucode! I can edit.'where id = 0
char *updatePassword(int id,char *newPassword);//UPDATE Users set password = '321' where id = 0
char *deleteMessage(int id); // DELETE from Messages where id = 0


#endif //OWN_UCHAT_API_DB_H
