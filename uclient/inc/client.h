//
// Created by Mykhailo Burenko on 03/02/2021.
//

#ifndef OWN_UCHAT_CLIENT_H
#define OWN_UCHAT_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "../../utils/libmx/inc/libmx.h"
#include "../../utils/mUtils/inc/api.h"

#define LENGTH 2048
#define sout(text) printf("%s\n",text);
typedef struct saved_message{
    char *login;
    char *message;
    long time;
    bool edit;
}s_message;
s_message *create_s_message(char *login, long time, bool edit, char *string_message);
t_list **getListMessages();
void setIsLogin(bool f);
bool getIsLogin();

// printer
void str_overwrite_stdout();
void print(char *string);
bool isCommandExit(char *command);

char *rm_first_spas(char *string);
bool isEntry(char *str);
//bool isCommand(char *string);


void runCommandClient(char *command,int sockfd);
void reconnect(int socketNum);
void runCommandClientMessage(char *message, int socket);
void runCommandServer(char *command);
void loadLastMessages(long time, int sockfd);
void loadAllMessages(int sockfd);

//  controller userver message
void response_login_ok(char *login);
void response_login_error(char *code,char *message);
void response_register_ok(char *login);
void response_register_error(char *code,char *message);
void new_messageClient(char *userName, char *message, char *time,bool edit);

#endif //OWN_UCHAT_CLIENT_H
// todo system("clear")





