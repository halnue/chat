//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/server.h"

void print(char *string) {
    printf("%s\n", string);
}


char **toCommandWithArg(char *command) {
printf("all = %s\n",command);
    char **res = CREATE_SIZE(char *, 10)
    int size = 0;
    char *sep = " \n\t\v\r\f";
    char *save_ptr1;
    char *pch = strtok_r(command, sep,&save_ptr1);
    while ( pch != NULL) {
        res[size] = pch;
//        printf("iter = %s\n",pch);//todo what? with out this line in db add void password
        size++;
        pch = strtok_r(NULL, sep,&save_ptr1);
    }
    res[size] = "\0";
    return res;
}
//char **toCommandWithArg(char *command) {
//    char **res = CREATE_SIZE(char *, 3)
//    int size = 0;
//// Разделители
//    char sep[10] = " \n\t\v\r\f";
//// Переменная, в которую будут заноситься начальные адреса частей
//// строки str
//    char *istr;
//
//// Выделение первой части строки
//    istr = strtok(command, sep);
//
//// Выделение последующих частей
//    while (istr != NULL) {
//// Вывод очередной выделенной части
//        res[size] = istr;
//        size++;
//// Выделение очередной части строки
//        istr = strtok(NULL, sep);
//    }
//    return res;
//}

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
void runCommand(char *command, int socked, pthread_mutex_t mutex, client_t *cli) {
    printf("%s\n",command);
    char *str = CREATE_SIZE(char, mx_arrlen(&command));
    mx_strcpy(str, command);
    char **parsCommand = toCommandWithArg(str);
    printf("command = %s, [1]= %s, [2]= %s\n", parsCommand[0], parsCommand[1], parsCommand[2]);
    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
        printf("COMMAND_CLIENT_REGISTER %s\n", command);
        command_register(parsCommand[1], parsCommand[2], socked, mutex);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
        printf("COMMAND_CLIENT_LOGIN %s\n", command);
        command_login(parsCommand[1], parsCommand[2], cli, mutex);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_MESSAGE) == 0) {
        printf("COMMAND_CLIENT_MESSAGE %s\n", command);
    } else {
        printf("Unknown command %s", parsCommand[0]);
    }
    print("fin");
}



