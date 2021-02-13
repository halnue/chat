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
    char **parsCommand =mx_strsplit(str,' ');
//            toCommandWithArg1(str);
    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
        send(socked, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
        send(socked, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_EDIT) == 0) {
        send(socked, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_DEL) == 0) {
        send(socked, command, strlen(command), 0);
    } else {
        printf("Unknown command %s\n", parsCommand[0]);
    }
//    print("fin");
}

void runCommandClientMessage(char *message, int socket) {
//    int i = mx_strlen(message);
//    FOR(0,i/SIZE_MESSAGE){
    char *buffer = CREATE_SIZE(char, strlen(message) + 9);
    sprintf(buffer, "%s|%s", COMMAND_CLIENT_MESSAGE, message);
    printf("sending");
    send(socket, buffer, strlen(buffer), 0);
    printf("is send data");
    return;
//    }
}

bool isCommandExit(char *command) {
    if (strcmp(command, COMMAND_CLIENT_EXIT) == 0) return true;
    return false;
}

void runCommandServer(char *command) {
//    printf("runCommandServer0\n");
    char *str = CREATE_SIZE(char, mx_arrlen(&command));
    mx_strcpy(str, command);
//    printf("runCommandServer00\n");
    char **parsCommand = mx_strsplit(str,' ');
//    toCommandWithArg1(str);
//    printf("0 =  %s %s %s\n", parsCommand[1], parsCommand[2], parsCommand[3]);
//    printf("runCommandServer = %s\n", parsCommand[0]);
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
        char **parsCommandMessage = mx_strsplit(command,'|');
//        printf(" COMMAND_NOTIFY_SERVER_NEW_MESSAGE %s %s %s\n", parsCommandMessage[1], parsCommandMessage[2], parsCommandMessage[3]);
        time_t t = atol(parsCommandMessage[2]);
        char *sTime = CREATE_SIZE(char, 26)
//        printf("code 100 = %s\n", parsCommandMessage[2]);
        ctime_r(&t, sTime);
        new_messageClient(parsCommandMessage[1], parsCommandMessage[3], sTime);
//        response_login_error(parsCommand[1], parsCommand[2]);
    } else if (strcmp(parsCommand[0], COMMAND_RESPONSE_SERVER_MESSAGE) == 0) {
//        char **parsCommandMessage = mx_strsplit(command,'|');
//        printf(" COMMAND_NOTIFY_SERVER_NEW_MESSAGE %s %s %s\n", parsCommandMessage[1], parsCommandMessage[2], parsCommandMessage[3]);
//        time_t t = atol(parsCommandMessage[2]);
//        char *sTime = CREATE_SIZE(char, 26)
//        printf("code 100 = %s\n", parsCommandMessage[2]);
//        ctime_r(&t, sTime);
//        new_messageClient(parsCommandMessage[1], parsCommandMessage[3], sTime);
    } else {
        char **parsCommandMessage = mx_strsplit(command,'|');
//        printf(" COMMAND_NOTIFY_SERVER_NEW_MESSAGE %s %s %s\n", parsCommandMessage[1], parsCommandMessage[2], parsCommandMessage[3]);
        if (strcmp(parsCommandMessage[0], COMMAND_NOTIFY_SERVER_NEW_MESSAGE) == 0) {
             long l = atol(parsCommandMessage[2]);
            time_t t = l;
            char *sTime = CREATE_SIZE(char, 26)
//            printf("code 100 = %s\n", parsCommandMessage[2]);
            ctime_r(&t, sTime);
            new_messageClient(parsCommandMessage[1], parsCommandMessage[3], sTime);
        } else{}
//        printf("Unknown command %s\n", parsCommandMessage[0]);
    }
    str_overwrite_stdout();
}

void sendMessage(char *command,char *arg,int cSocket){
    send(cSocket, command, strlen(command), 0);
    send(cSocket, arg, strlen(command), 0);


}
