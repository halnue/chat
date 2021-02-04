//
// Created by Vladyslav Loza on 04/02/2021.
//
#include "../inc/api_db.h"
#include "../../utils/api.h"
User *create_user(int id, char *login, char *password) {
    User *user = CREATE(User);
    user->id = id;
    user->login = login;
    user->password = password;
    return user;
}

Message *create_message(int id, int idUser, char *msg, long time) {
    Message *message = CREATE(Message);
    message->id = id;
    message->idUser = idUser;
    message->message = msg;
    message->time = time;
    message->edit = false;
    return message;
}
