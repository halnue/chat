//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/client.h"

#define LOGIN }if (strcmp(command,COMMAND_LOGIN) == 0){
#define REGISTER if (strcmp(command,COMMAND_REGISTER) == 0){
#define EXIT }if (strcmp(command,COMMAND_EXIT) == 0){

void runCommandClient(int command,int socked) {
    REGISTER
        char *login;
        char *password;
        print("Creating new user");
        print("Enter login");
        scanf("%s", login);
        print("Enter password");
        scanf("%s", password);
        send(socked, command, strlen(command), 0);
        send(socked, login, strlen(login), 0);
        send(socked, password, strlen(password), 0);
    LOGIN
        char *login;
        char *password;
        print("Enter login");
        scanf("%s", login);
        print("Enter password");
        scanf("%s", password);
        send(socked, command, strlen(command), 0);
        send(socked, login, strlen(login), 0);
        send(socked, password, strlen(password), 0);
    EXIT

    } else {


    }
}

bool isCommandExit(char *command) {
    if (strcmp(command, COMMAND_EXIT) == 0) return true;
    return false;
}

int selectCommand(char *command) {
    if (strcmp(command, COMMAND_REGISTER)) return 1;
    else if (strcmp(command, COMMAND_LOGIN)) return 2;
    else if (strcmp(command, COMMAND_EXIT)) return 0;
    else return -1;

}
