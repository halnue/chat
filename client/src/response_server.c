//
// Created by Mykhailo Burenko on 2/8/21.
//
#include "../inc/client.h"
void response_login_ok(char *login){
    printf("/uchat: authorization was successful for %s\n",login);
}
void response_login_error(char *code,char *message){
    code = message;
    printf("/uchat: authorization error: \"%s\"\n",message);
}
void response_register_ok(char *login){
    printf("/uchat: user registration was successful for %s\n",login);
}
void response_register_error(char *code,char *message){
    code = message;
    printf("/uchat: user registration was failed: \"%s\"\n",message);
}
