//
// Created by Mykhailo Burenko on 03/02/2021.
//

#ifndef OWN_UCHAT_SERVER_H
#define OWN_UCHAT_SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>
#include "api_db.h"

#define MAX_CLIENTS 100
#define BUFFER_SZ 2048


/* Client structure */
typedef struct{
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char name[32];
} client_t;


void runCommand(char *command,int socked,pthread_mutex_t mutex);

bool sqlTransaction(char *sql,pthread_mutex_t mutex);
bool sqlTransactionCall(char *sql,pthread_mutex_t mutex,int (*callback)(void*,int,char**,char**),void *data);
void command_login(char *login, char *password, int userSocket, pthread_mutex_t mutex);
void command_register(char *login, char *password, int userSocket, pthread_mutex_t mutex);

void send_message(char *s, int uid);
#endif //OWN_UCHAT_SERVER_H
