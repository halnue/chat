//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/server.h"

void print(char *string) {
    printf("%s\n", string);
}

char *recv_cocked(int socked) {
    char *buff;
    int receive = recv(socked, buff, BUFFER_SZ, 0);
    if (receive > 0) {
        return buff;
    }
    buff = "";
    return buff;
}

void runCommand(int command, int socked) {
    REGISTER
        char *login = recv_cocked(socked);
        char *password = recv_cocked(setlogin(socked));
        char *insert = insertUsersSQL(create_user(login,password));
        sqlTransaction(insert);
    LOGIN
        char *login = recv_cocked(socked);
        char *password = recv_cocked(setlogin(socked));
    EXIT

    } else {


    }
}
