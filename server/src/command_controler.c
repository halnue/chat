//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/server.h"

void print(char *string) {
    printf("%s\n", string);
}


char **toCommandWithArg(char *command) {
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

char *recv_socked(int socked) {
    char *buff = NULL;
    int receive = recv(socked, buff, BUFFER_SZ, 0);
    if (receive > 0) {
        return buff;
    }
    buff = "";
    return buff;
}

//void runCommand(char *command, int socked,pthread_mutex_t mutex) {
//    char **parsCommand = toCommandWithArg(command);
//    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
//        printf("it's register %s\n", command);
//        printf("login %s\n", parsCommand[1]);
//        printf("password%s\n", parsCommand[2]);
//        char *insert = insertUsersSQL(create_user(parsCommand[1], parsCommand[2]));
//        sqlTransaction(insert, mutex);
//    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
////        char *login = recv_socked(socked);
////        char *password = recv_socked(socked);
//    } else {
//
//
//    }
//}
void runCommand(char *command, int socked,pthread_mutex_t mutex) {
    char *str = CREATE_SIZE(char, mx_arrlen(&command));
    mx_strcpy(str, command);
    char **parsCommand = toCommandWithArg(str);
    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
        send(socked, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
        login(parsCommand[1],parsCommand[2],socked,mutex);
    } else {
        printf("Unknown command %s", parsCommand[0]);
    }
    print("fin");
}



