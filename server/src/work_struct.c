//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/api_db.h"
#include "../../utils/api.h"

User *create_user(char *login, char *password) {
    User *user = CREATE(User);
    user->id = createNewIdUser();
    user->login = login;
    user->password = password;
    return user;
}

Message *create_message(int idUser, char *msg, long time) {
    Message *message = CREATE(Message);
    message->id = createNewIdMassage();
    message->idUser = idUser;
    message->message = msg;
    message->time = time;
    message->edit = false;
    return message;
}

int createNewIdUser() {
    static int idUser = 0;
    idUser++;
    return idUser;
}

int createNewIdMassage() {
    static int idMassage = 0;
    idMassage++;
    return idMassage;
}

