//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/server.h"

void print(char *string) {
    printf("%s\n", string);
}

bool isSpace(char ch) {
    char *arr = " \n\t\v\r\f";
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (ch == arr[i]) return true;
    }
    return false;
}

//char **toCommandWithArgWithoutStrtok(char *command) {
//    char *fullString = command;
//    int size = 0;
//    char **res = CREATE_SIZE(char *, 10)
//    while (fullString[0] != '\0') {
//        if (!isSpace(fullString[0])) {
//            int i = 0;
//            for (; !isSpace(fullString[i]); ++i) {}
//            char *tmp = CREATE_SIZE(char, i)
//            mx_strncpy(tmp, fullString, i);
//            res[size] = tmp;
//            size++;
//            fullString = fullString + i;
//        }
//        fullString++;
//    }
//    res[size] = NULL;
//    return res;
//}

char **toCommandWithArg(char *command) {
    printf("all = %s\n", command);
    char **res = CREATE_SIZE(char *, 10)
    int size = 0;
    char *sep = " \n\t\v\r\f";
    char *save_ptr1;
    char *pch = strtok_r(command, sep, &save_ptr1);
    while (pch != NULL) {
        res[size] = pch;
//        printf("iter = %s\n",pch);//todo what? with out this line in db add void password
        size++;
        pch = strtok_r(NULL, sep, &save_ptr1);
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

void runCommand(char *command, int socked, pthread_mutex_t mutex, client_t *cli) {
    printf("%s\n", command);
    char *str = CREATE_SIZE(char, mx_arrlen(&command));
    mx_strcpy(str, command);

    char **parsCommand = mx_strsplit(str,' ');
//            toCommandWithArg(str);
//    printf("command = %s, [1]= %s, [2]= %s\n", parsCommand[0], parsCommand[1], parsCommand[2]);
    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
        printf("COMMAND_CLIENT_REGISTER %s\n", command);
        command_register(parsCommand[1], parsCommand[2], socked, mutex);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
        printf("COMMAND_CLIENT_LOGIN %s\n", command);
        command_login(parsCommand[1], parsCommand[2], cli, mutex);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_EDIT) == 0) {
        printf("command_edit");
        command_edit(parsCommand[1],mutex);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_DEL) == 0) {
        printf("command_delete");
        command_delete(mutex);
    } else if (strcmp(parsCommand[0], "/message") == 0) {
        char **parsCommandMessage = mx_strsplit(str,'|');
        printf("\n2\n");
        command_message(parsCommandMessage[1], cli, mutex);
        printf("COMMAND_CLIENT_MESSAGE %s\n", command);
    } else {
        char **parsCommandMessage = mx_strsplit(str,'|');
        printf("\n2\n");
        if (strcmp(parsCommand[0], COMMAND_CLIENT_MESSAGE) == 0){
            command_message(parsCommandMessage[1], cli, mutex);
            printf("else COMMAND_CLIENT_MESSAGE %s\n", command);
        } else
        printf("Unknown command %s", parsCommand[0]);
    }
    print("fin");
}
