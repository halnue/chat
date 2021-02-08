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


// printer
void str_overwrite_stdout();
void print(char *string);
bool isCommandExit(char *command);

char *rm_first_spas(char *string);
//bool isCommand(char *string);


void runCommandClient(char *command,int socked);
void runCommandServer(char *command);

//  controller server response
void response_login_ok(char *login);
void response_login_error(char *code,char *message);
void response_register_ok(char *login);
void response_register_error(char *code,char *message);

#endif //OWN_UCHAT_CLIENT_H
