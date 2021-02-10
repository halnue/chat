//
// Created by Mykhailo Burenko on 2/6/21.
//
#include <stdio.h>
#include "../inc/api_db.h"

char *response(char *action,char *code,char *message){
    char *buff = CREATE_SIZE(char, mx_strlen(action) +mx_strlen(code) +mx_strlen(message))
    sprintf(buff, "%s %s %s", action,code ,message);
    printf("response code: %s\n",code);
    return buff;
}



