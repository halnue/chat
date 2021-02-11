//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/client.h"
#include "regex.h"

char **toCommandWithArg1(char *command) {
    char **res = CREATE_SIZE(char *, 10)
    int size = 0;
    char *sep = " \n\t\v\r\f";
    char *pch = strtok(command, sep);
    while ((void *) pch != NULL) {
        res[size] = pch;
        size++;
        pch = strtok(NULL, sep);
    }
    res[size] = "\0";
    return res;
}

void printArr1(char **arr) {
    int i = 0;

    while (arr[i]) {
        printf("printArr1 %d %s\n", i, arr[i]);
        i++;
    }
    if (i > 0)
        mx_printstr("\n");

}

void runCommandClient(char *command, int socked) {
    char *str = CREATE_SIZE(char, mx_arrlen(&command));
    mx_strcpy(str, command);
    char **parsCommand = toCommandWithArg1(str);
    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
        send(socked, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
        send(socked, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_EDIT) == 0) {
        send(socked, command, strlen(command), 0);
    } else {
        printf("Unknown command %s", parsCommand[0]);
    }
//    print("fin");
}

void runCommandClientMessage(char *message, int socket) {
//    int i = mx_strlen(message);
//    FOR(0,i/SIZE_MESSAGE){
    char *buffer = CREATE_SIZE(char, strlen(message) + 9);
    sprintf(buffer, "%s %s", COMMAND_CLIENT_MESSAGE, message);
    send(socket, buffer, strlen(buffer), 0);
//    }
}

bool isCommandExit(char *command) {
    if (strcmp(command, COMMAND_CLIENT_EXIT) == 0) return true;
    return false;
}

void runCommandServer(char *command) {
    printf("runCommandServer0\n");
    char *str = CREATE_SIZE(char, mx_arrlen(&command));
    mx_strcpy(str, command);
    printf("runCommandServer00\n");
    char **parsCommand = toCommandWithArg1(str);
    printf("0 =  %s %s %s\n", parsCommand[1], parsCommand[2], parsCommand[3]);
    printf("runCommandServer = %s\n", parsCommand[0]);
    if (strcmp(parsCommand[0], COMMAND_RESPONSE_SERVER_REGISTER) == 0) {
        if (strcmp(parsCommand[1], RESPONSE_200) == 0) {
            response_register_ok(parsCommand[2]);
        } else {
            response_register_error(parsCommand[1], parsCommand[2]);
        }
    } else if (strcmp(parsCommand[0], COMMAND_RESPONSE_SERVER_LOGIN) == 0) {
//        printf("else if = %s\n", parsCommand[1]);
        if (strcmp(parsCommand[1], RESPONSE_200) == 0) {
//            printf("code 200 = %s\n", parsCommand[2]);
            response_login_ok(parsCommand[2]);
        } else {
            response_login_error(parsCommand[1], parsCommand[2]);
        }
    } else if (strcmp(parsCommand[0], COMMAND_NOTIFY_SERVER_NEW_MESSAGE) == 0) {
        printf(" COMMAND_NOTIFY_SERVER_NEW_MESSAGE %s %s %s\n", parsCommand[1], parsCommand[2], parsCommand[3]);
        time_t t = atol(parsCommand[3]);
        char *sTime = CREATE_SIZE(char, 26)
        printf("code 100 = %s\n", parsCommand[2]);
        ctime_r(&t, sTime);
        new_messageClient(parsCommand[1], parsCommand[2], sTime);
//        response_login_error(parsCommand[1], parsCommand[2]);
    } else {
        printf("Unknown command %s\n", parsCommand[0]);
    }
    str_overwrite_stdout();
}

void sendMessage(char *command,char *arg,int cSocket){
    send(cSocket, command, strlen(command), 0);
    send(cSocket, arg, strlen(command), 0);


}
