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
#include "../../utils/api.h"

#define LENGTH 2048
#define COMMAND_REGISTER "/register"
#define COMMAND_LOGIN "/login"
#define COMMAND_EXIT "/exit"


// printer
void str_overwrite_stdout();
void print(char *string);
bool isCommandExit(char *command);

char *rm_first_spas(char *string);
bool isCommand(char *string);


void runCommandClient(int command,int socked);
int selectCommand(char *command);

#endif //OWN_UCHAT_CLIENT_H
