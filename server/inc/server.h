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

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Client structure */
typedef struct{
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char name[32];
} client_t;


void runCommand(int command,int socked);

bool sqlTransaction(char *sql);

#endif //OWN_UCHAT_SERVER_H
