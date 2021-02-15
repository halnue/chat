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
#define BUFFER_SZ 3076



/* Client structure */
typedef struct{
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char *name;
} client_t;


void runCommand(char *command,int socked,pthread_mutex_t mutex,client_t *cli);

bool sqlTransaction(char *sql,pthread_mutex_t mutex);
bool sqlTransactionCall(char *sql,pthread_mutex_t mutex,int (*callback)(void*,int,char**,char**),void *data);
void command_login(char *login, char *password, client_t *cli, pthread_mutex_t mutex);
void command_register(char *login, char *password, int userSocket, pthread_mutex_t mutex);
void command_delete(pthread_mutex_t mutex);
void command_edit_u(char *message, pthread_mutex_t mutex,int i);
void command_delete_u(pthread_mutex_t mutex,int i);
void command_send_all_message(int userSocket, pthread_mutex_t mutex);
void command_send_last_message(int userSocket,char *time, pthread_mutex_t mutex);
void command_edit(char *message, pthread_mutex_t mutex);
void command_edit_u(char *message, pthread_mutex_t mutex,int i);
void command_message(char *message, client_t *cli, pthread_mutex_t mutex);

void send_message(char *s, int uid);// send message to authorization user with this uid
void send_messages(char *s, int uid);// send message to all authorization users without this uid
void send_command(char *s, int sockfd);// send message to user with this sockfd
void command_to_all(char *s, int sockfd);// send message to all users without this sockfd
#endif //OWN_UCHAT_SERVER_H
