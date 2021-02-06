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

void  printArr1(char **arr){
        int i = 0;

        while(arr[i]) {
            printf("%s\n",arr[i]);
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
        char *login = NULL;
        char *password = NULL;
        scanf("%s", login);
        scanf("%s", password);
        send(socked, command, strlen(command), 0);
        send(socked, login, strlen(login), 0);
        send(socked, password, strlen(password), 0);
    } else {
        printf("Unknown command %s", parsCommand[0]);
    }
    print("fin");
}

bool isCommandExit(char *command) {
    if (strcmp(command, COMMAND_CLIENT_EXIT) == 0) return true;
    return false;
}
