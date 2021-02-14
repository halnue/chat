//
// Created by Mykhailo Burenko on 2/8/21.
//
#include "../inc/client.h"

void response_login_ok(char *login) {

    printf("\033[32m /uchat: authorization was successful for %s\n\033[0m" , login);
    setIsLogin(true);
}

void response_login_error(char *code, char *message) {
    code = message;
    printf("\033[31m /uchat: authorization error: %s\n\033[0m", message);
}

void response_register_ok(char *login) {
    printf("\033[32m /uchat: user registration was successful for %s\n\033[0m", login);
}

void response_register_error(char *code, char *message) {
    code = message;
    printf("\033[31m /uchat: user registration was failed: %s\n\033[0m", message);
}

void new_messageClient(char *userName, char *message, char *time) {
    printf("%s > %s\n", userName, message);
    printf("\033[34m   %s\033[0m",time);
}
