//
// Created by Mykhailo Burenko on 2/6/21.
//
#include <stdio.h>
#include "../inc/api_db.h"
#include "../inc/server.h"

char *new_message(char *action, char *code, char *message){
    char *buff = mx_strnew( mx_strlen(action) +mx_strlen(code) +mx_strlen(message)+5);
    sprintf(buff, "%s %s %s", action,code ,message);
    printf("message code: %s\n",code);
    return buff;
}
char *notify_message(char *action, char *userName, char *message,long time){
    char *buff = mx_strnew( mx_strlen(action) + mx_strlen(userName) + mx_strlen(message)+10);
    sprintf(buff, "%s|%s|%ld|%s", action, userName , time,message);
    printf("message userName: %s\n", userName);
    return buff;
}

void message_join_user(char *name,int sockfd){
    char *buff_out = mx_strnew(BUFFER_SZ);
    sprintf(buff_out, "%s has joined\n", name);
    printf("%s", buff_out);
    send_messages(buff_out, sockfd);
}

