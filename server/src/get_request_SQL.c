#include <stdio.h>
#include "../inc/api_db.h"

char *insertUsersSQL(char *login, char *password){
    char* buff = mx_strnew(30);;
    sprintf(buff, "%s%s%s%s%s","INSERT INTO Users(LOGIN, PASSWORD) VALUES ('", login, "','", password, "')");
    return buff;
}

char *insertMessageSQL(Message *msg) {
    char *buff = mx_strnew(1024);
    sprintf(buff, "%s %d %s%s%s %ld %c %d %c","INSERT INTO Messages(idUser, Message, time, edit) VALUES (", msg->idUser, ", '", msg->message, "',", msg->time, ',', msg->edit, ')');
    return buff;
}

char *getPasswordSQL(char *login) {
    char *buff = mx_strnew(50+LENGTH_LOGIN);
    sprintf(buff, "SELECT password, id FROM Users WHERE login = '%s'",login);
    return buff;
}

char *updateMessage(int id,char *newMessage) {
    char *buff = mx_strnew(1024);
    sprintf(buff, "%s %s %s %d", "UPDATE Messages set edit = true, Message = '",newMessage,"' where id =",  id);
    return buff;
}

char *updateMessageMaxId(char *newMessage) {
    char *buff = mx_strnew(1024);
    sprintf(buff, "%s%s%s", "UPDATE Messages set edit = true, Message = '",newMessage,"' WHERE id = (SELECT MAX(id) FROM Messages)");
    return buff;
}

char *updatePassword(int id,char *newPassword) {
    char *buff = mx_strnew( 41);
    sprintf(buff, "%s%s %s %d", "UPDATE Users set password = '", newPassword,"' where id =", id);
    return buff;
}

char *getLastMessage(char *time){
    char *buff = mx_strnew( 41);
    sprintf(buff, "SELECT  Messages.id,idUser,login, message, time, edit FROM Messages JOIN Users ON idUser=Users.id WHERE time > %s ORDER BY time", time);
    return buff;
}

char *deleteMessage(int id) {
    char *buff = mx_strnew( 40);
    sprintf(buff, "%s %d", "DELETE from Messages where id =", id);
    return buff;
}
