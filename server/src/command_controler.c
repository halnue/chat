//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/server.h"

void print(char *string) {
    printf("%s\n", string);
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

void runCommand(char *command, int socked ,pthread_mutex_t mutex) {
    printf("%s\n", command);
    REGISTER
        printf("it's register %s\n", command);
        char *login = recv_socked(socked);
        printf("%s\n", login);
        char *password = recv_socked(socked);
        printf("%s\n", password);
        char *insert = insertUsersSQL(create_user(login,password));
        sqlTransaction(insert,mutex);
    LOGIN
//        char *login = recv_socked(socked);
//        char *password = recv_socked(socked);
    EXIT

    } else {


    }
}

char **toCommandWithArg(char *command){
    char **res = CREATE_SIZE(char *,10)
            int size = 0;
    char *sep = " \n\t\v\r\f";
    char pch = strtok(command,sep);
    while (pch !=NULL){
        res[size] = pch;
        pch = strtok (NULL, sep);
    }
}
