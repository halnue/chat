//
// Created by Mykhailo Burenko on 2/4/21.
//

#ifndef OWN_UCHAT_API_H
#define OWN_UCHAT_API_H

#include "utils_define.h"

#define LENGTH_MESSAGE 512

#define PORT_SERVER 8080

#define COMMAND_CLIENT_REGISTER "/register"
#define COMMAND_CLIENT_LOGIN "/login"
#define COMMAND_CLIENT_EXIT "/exit"
#define COMMAND_RESPONSE_SERVER_LOGIN "/login"
#define COMMAND_RESPONSE_SERVER_REGISTER "/register"


#define LOGIN }if (strcmp(command,COMMAND_CLIENT_LOGIN) == 0){
#define REGISTER if (strcmp(command,COMMAND_CLIENT_REGISTER) == 0){
#define EXIT }if (strcmp(command,COMMAND_CLIENT_EXIT) == 0){

typedef struct _User{
    int id;
    char *login;
    char *password;
} User;
typedef struct _message{
    int id;
    int idUser;
    char *message;
    long time;
    bool edit;
} Message;



#endif //OWN_UCHAT_API_H
