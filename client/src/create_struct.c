//
// Created by Mykhailo Burenko on 2/14/21.
//
#include "../inc/client.h"

s_message *create_s_message(char *login, long time, bool edit, char *string_message) {
    s_message *message = CREATE(s_message)
    message->login = login;
    message->time = time;
    message->edit = edit;
    message->message = string_message;
    return message;
}
