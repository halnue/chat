//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/client.h"
#include "regex.h"

void loadAllMessages(int sockfd) {
    send(sockfd, COMMAND_CLIENT_LOAD_ALL_MESSAGES, strlen(COMMAND_CLIENT_LOAD_ALL_MESSAGES), 0);
}

void loadLastMessages(long time, int sockfd) {
    char *buffer = mx_strnew(strlen(COMMAND_CLIENT_LOAD_MESSAGES) + 10);
    sprintf(buffer, "%s|%ld", COMMAND_CLIENT_LOAD_MESSAGES, time);

    send(sockfd, buffer, strlen(buffer), 0);
}

void runCommandClientMessage(char *message, int socket) {
//    int i = mx_strlen(message);
//    FOR(0,i/SIZE_MESSAGE){
    char *buffer = mx_strnew( strlen(message) + 9);
    sprintf(buffer, "%s|%s", COMMAND_CLIENT_MESSAGE, message);
    printf("sending");
    send(socket, buffer, strlen(buffer), 0);
    printf("is send data");
    return;
//    }
}

void runCommandClient(char *command, int sockfd) {
    char *str = mx_strnew(mx_arrlen(&command));
    mx_strcpy(str, command);
    if (isEntry(command)) return;
    char **parsCommand = mx_strsplit(str, ' ');
//            toCommandWithArg1(str);
    if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
        send(sockfd, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
        send(sockfd, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_EDIT) == 0) {
        send(sockfd, command, strlen(command), 0);
    } else if (strcmp(parsCommand[0], COMMAND_CLIENT_DEL) == 0) {
        send(sockfd, command, strlen(command), 0);
    } else {
        printf("Unknown command %s\n", parsCommand[0]);
    }
//    print("fin");
}

bool isCommandExit(char *command) {
    if (strcmp(command, COMMAND_CLIENT_EXIT) == 0) return true;
    return false;
}

void runCommandServer(char *command) {
//    printf("runCommandServer0\n");
    if (isEntry(command)) return;

    char *str = mx_strnew(mx_arrlen(&command));
    mx_strcpy(str, command);
//    printf("runCommandServer00\n");
    char **parsCommand = mx_strsplit(str, ' ');
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
        char **parsCommandMessage = mx_strsplit(command, '|');
//        printf(" COMMAND_NOTIFY_SERVER_NEW_MESSAGE %s %s %s\n", parsCommandMessage[1], parsCommandMessage[2], parsCommandMessage[3]);
        time_t t = atol(parsCommandMessage[2]);
        char *sTime = mx_strnew(26);
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
        char **parsCommandMessage = mx_strsplit(command, '|');
//        printf(" COMMAND_NOTIFY_SERVER_NEW_MESSAGE %s %s %s\n", parsCommandMessage[1], parsCommandMessage[2], parsCommandMessage[3]);
        if (strcmp(parsCommandMessage[0], COMMAND_NOTIFY_SERVER_NEW_MESSAGE) == 0) {
            long l = atol(parsCommandMessage[2]);
            time_t t = l;
            char *sTime = mx_strnew( 26);
//            printf("code 100 = %s\n", parsCommandMessage[2]);
            ctime_r(&t, sTime);
            new_messageClient(parsCommandMessage[1], parsCommandMessage[3], sTime);
        } else if (strcmp(parsCommandMessage[0], COMMAND_RESPONSE_SERVER_MESSAGE_LOAD_MESSAGE) == 0){
            char *login = parsCommandMessage[1];
            long time = atol(parsCommandMessage[2]);
            bool edit = atoi(parsCommandMessage[3]);
            char *message = parsCommandMessage[4];
            char *sTime = mx_strnew( 26);
            ctime_r(&time, sTime);
            new_messageClient(login,message,sTime);
            mx_push_back(getListMessages(),mx_create_node(create_s_message(login,time,edit,message)));
            printf("\nmessage added\n");
        }else {}
//        printf("Unknown command %s\n", parsCommandMessage[0]);
    }
    str_overwrite_stdout();
}

void sendMessage(char *command, char *arg, int cSocket) {
    send(cSocket, command, strlen(command), 0);
    send(cSocket, arg, strlen(command), 0);


}
