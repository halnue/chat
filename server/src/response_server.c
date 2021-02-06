//
// Created by Mykhailo Burenko on 2/6/21.
//
#include <stdio.h>
#include "../inc/api_db.h"

char *response_login(char *message) {
    char *buff = CREATE_SIZE(char, 10 + LENGTH_LOGIN)
    sprintf(buff, "%s %s", COMMAND_RESPONSE_SERVER_LOGIN ,message);
    return buff;
}

char *response(char *action,char *code,char *message){
    char *buff = CREATE_SIZE(char, mx_strlen(action) +mx_strlen(code) +mx_strlen(message))
    sprintf(buff, "%s %s %s", action,code ,message);
    return buff;
}



