#include <stdio.h>
#include "../inc/api_db.h"

char *insertUsersSQL(User *usr){
    char* buff = CREATE_SIZE(char ,130);;
    sprintf(buff, "%s%s%s%s%s","INSERT INTO Users(LOGIN, PASSWORD) VALUES ('", usr->login, "','", usr->password, "')");
    return buff;
}

char *insertMessageSQL(Message *msg) {
    char *buff = CREATE_SIZE(char ,1024);
    sprintf(buff, "%s %d %s%s%s %ld %c %d %c","INSERT INTO Messages(id, idUser, Message, time, edit) VALUES (", msg->idUser, ", '", msg->message, "',", msg->time, ',', msg->edit, ')');
    return buff;
}

char *getPasswordSQL(char *login) {
    char *buff = CREATE_SIZE(char ,50+LENGTH_LOGIN);
    sprintf(buff, "SELECT password FROM Users WHERE login = '%s'",login);
    return buff;
}

char *updateMessage(int id,char *newMessage) {
    char *buff = CREATE_SIZE(char ,1024);
    sprintf(buff, "%s %s %s %d", "UPDATE Messages set edit = true, Message = '",newMessage,"' where id =",  id);
    return buff;
}

char *updatePassword(int id,char *newPassword) {
    char *buff = CREATE_SIZE(char, 41);
    sprintf(buff, "%s%s %s %d", "UPDATE Users set password = '", newPassword,"' where id =", id);
    return buff;
}

char *deleteMessage(int id) {
    char *buff = CREATE_SIZE(char, 40);
    sprintf(buff, "%s %d", "DELETE from Messages where id =", id);
    return buff;
}
