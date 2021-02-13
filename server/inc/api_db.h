//
// Created by Mykhailo Burenko on 2/4/21.
//

#ifndef OWN_UCHAT_API_DB_H
#define OWN_UCHAT_API_DB_H

#include <sqlite3.h>
#include "../../utils/libmx/inc/libmx.h"
#include "../../utils/mUtils/inc/api.h"
#include "string.h"

#define LENGTH_LOGIN 20
#define LENGTH_PASSWORD 40

#define CREATE_TABLE_USERS "CREATE TABLE IF NOT EXISTS Users(id INTEGER PRIMARY KEY NOT NULL,login VARCHAR(20) NOT NULL UNIQUE,password VARCHAR(40) NOT NULL)"
#define CREATE_TABLE_MESSAGES "CREATE TABLE IF NOT EXISTS Messages(id INTEGER PRIMARY KEY NOT NULL,idUser  INTEGER             NOT NULL,message VARCHAR(512)        NOT NULL,time    INTEGER(11)         NOT NULL,edit    BOOLEAN)"
#define GET_MESSAGE_MAX_ID "SELECT message,max(id) FROM Messages"
#define DELETE_MESSAGE_MAX_ID "DELETE FROM Messages WHERE id = (SELECT MAX(id) FROM Messages)"
#define EDIT_MESSAGE_MAX_ID "DELETE FROM Messages WHERE id = (SELECT MAX(id) FROM Messages)"
#define DB "Massager"

sqlite3 *openDB(char *nameDB);

int dbRequest(sqlite3 *db, const char *sql);
int dbRequestCall(sqlite3* db, const char *sql,int (*own_callback)(void*,int,char**,char**),void *data);

char *insertUsersSQL(char *login, char *password);
char *insertMessageSQL(Message *msg);//INSERT INTO Messages(id, idUser, Message, time, edit) VALUES (0,0,'Hello, Ucode!',1612451993,false)
char *updateMessage(int id,char *newMessage);//UPDATE Messages set edit = true,Message = 'Hello, Ucode! I can edit.'where id = 0
char *updateMessageMaxId(char *newMessage);
char *updatePassword(int id,char *newPassword);//UPDATE Users set password = '321' where id = 0
char *deleteMessage(int id); // DELETE from Messages where id = 0
char *getPasswordSQL(char *login);

User *create_user(char *login, char *password);
Message *create_message(int idUser, char *msg, long time);

int createNewIdUser();
int createNewIdMassage();

// message server
char *new_message(char *action, char *code, char *message);
char *notify_message(char *action, char *userName, char *message,long time);
#endif //OWN_UCHAT_API_DB_H
