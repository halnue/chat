//
// Created by Mykhailo Burenko on 2/6/21.
//
#include <stdio.h>
#include "../inc/api_db.h"

char *new_message(char *action, char *code, char *message){
    char *buff = CREATE_SIZE(char, mx_strlen(action) +mx_strlen(code) +mx_strlen(message)+5)
    sprintf(buff, "%s %s %s", action,code ,message);
    printf("message code: %s\n",code);
    return buff;
}
char *notify_message(char *action, char *userName, char *message,long time){
    char *buff = CREATE_SIZE(char, mx_strlen(action) + mx_strlen(userName) + mx_strlen(message)+10);
    sprintf(buff, "%s|%s|%ld|%s", action, userName , time,message);
    printf("message userName: %s\n", userName);
    return buff;
}



