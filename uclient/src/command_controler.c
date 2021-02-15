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
    char *buffer = mx_strnew(strlen(message) + 9);
    sprintf(buffer, "%s|%s", COMMAND_CLIENT_MESSAGE, message);
    printf("sending");
    send(socket, buffer, strlen(buffer), 0);
    printf("is send data");
    return;
//    }
}

// /edit|12|vdfvjnk mjsgvjf ioesjflzkxcj ij osdjfcsd vv
void runCommandClient(char *command, int sockfd) {
    char *str = mx_strnew(mx_arrlen(&command));
    mx_strcpy(str, command);
    if (isEntry(command)) return;
    bool f = mx_strchr(command, '|');
    if (f) {
        char **parsCommand = mx_strsplit(str, '|');
        if (strcmp(parsCommand[0], COMMAND_CLIENT_EDIT) == 0) {
            char *buff = mx_strnew(3078);
            sprintf(buff, "%s|%s|%s", COMMAND_CLIENT_EDIT_U,parsCommand[1],parsCommand[2]);
            send(sockfd, buff, strlen(buff), 0);
            usleep(10000);
            loadAllMessages(sockfd);
        } else if (strcmp(parsCommand[0], COMMAND_CLIENT_DEL) == 0) {
            char *buff = mx_strnew(3078);
            sprintf(buff, "%s|%s", COMMAND_CLIENT_DEL_U,parsCommand[1]);
            send(sockfd, buff, strlen(buff), 0);
            usleep(10000);
            loadAllMessages(sockfd);
        }
    } else {
        char **parsCommand = mx_strsplit(str, ' ');
//            toCommandWithArg1(str);
        if (strcmp(parsCommand[0], COMMAND_CLIENT_REGISTER) == 0) {
            send(sockfd, command, strlen(command), 0);
        } else if (strcmp(parsCommand[0], COMMAND_CLIENT_LOGIN) == 0) {
            send(sockfd, command, strlen(command), 0);
        } else if (strcmp(parsCommand[0], COMMAND_CLIENT_EDIT) == 0) {
            send(sockfd, command, strlen(command), 0);
            usleep(10000);
            loadAllMessages(sockfd);
        } else if (strcmp(parsCommand[0], COMMAND_CLIENT_DEL) == 0) {
            send(sockfd, command, strlen(command), 0);
            usleep(10000);
            loadAllMessages(sockfd);
        } else {
            printf("Unknown command %s\n", parsCommand[0]);
        }
    }
//    print("fin");
}

bool isCommandExit(char *command) {
    if (strcmp(command, COMMAND_CLIENT_EXIT) == 0) return true;
    return false;
}

//bool findChar(char *str, char ch) {
//    sout("finding")
//    for (int i = 0; str[i] != '\0'; ++i) {
//        if (str[i] == ch) return true;
//    }
//    sout("finded")
//    return false;
//}

void runCommandServer(char *command) {
//    printf("runCommandServer0\n");
    if (isEntry(command)) return;

    char *str = mx_strnew(mx_arrlen(&command));
    mx_strcpy(str, command);
    sout("1");
    sout(command)
//    printf("runCommandServer00\n");
    bool f = mx_strchr(command, '|');
    printf("f = %d\n", f);
    if (!f) {
        char **parsCommand = mx_strsplit(str, ' ');
        sout("2");
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
            if (strcmp(parsCommand[1], RESPONSE_200) == 0) {
//            printf("code 200 = %s\n", parsCommand[2]);

                response_login_ok(parsCommand[2]);
            } else {
                response_login_error(parsCommand[1], parsCommand[2]);
            }
        } else if (strcmp(parsCommand[0], COMMAND_NOTIFY_SERVER_NEW_MESSAGE) == 0) {
            char **parsCommandMessage = mx_strsplit(command, '|');
            char *login = parsCommandMessage[1];
            long time = atol(parsCommandMessage[2]);
            bool edit = false;
            char *message = parsCommandMessage[3];
            char *sTime = mx_strnew(26);
            ctime_r(&time, sTime);
            new_messageClient(login, message, sTime, edit);
//        response_login_error(parsCommand[1], parsCommand[2]);
        } else if (strcmp(parsCommand[0], COMMAND_RESPONSE_SERVER_MESSAGE) == 0) {
        } else printf("Unknown command %s\n", parsCommand[0]);
    } else {
        printf("else mess = %s \n", str);
        char **parsCommandMessage = mx_strsplit(str, '|');
        printf("mess = %s \n", parsCommandMessage[4]);
        if (strcmp(parsCommandMessage[0], COMMAND_NOTIFY_SERVER_NEW_MESSAGE) == 0) {
            char *login = parsCommandMessage[1];
            long time = atol(parsCommandMessage[2]);
            bool edit = false;
            char *message = parsCommandMessage[3];
            printf("mess = %s \n", message);
            char *sTime = mx_strnew(26);
            ctime_r(&time, sTime);
            new_messageClient(login, message, sTime, edit);
//            free(login);
//            free(message);
        } else if (strcmp(parsCommandMessage[0], COMMAND_RESPONSE_SERVER_MESSAGE_LOAD_MESSAGE) == 0) {
            char *login = parsCommandMessage[1];
            long time = atol(parsCommandMessage[2]);
            bool edit = atoi(parsCommandMessage[3]);
            char *message = parsCommandMessage[4];
            char *sTime = mx_strnew(26);
            ctime_r(&time, sTime);
            new_messageClient(login, message, sTime, edit);
//            mx_push_back(getListMessages(), mx_create_node(create_s_message(login, time, edit, message)));
            printf("\nmessage added\n");

        } else
            printf("Unknown command %s\n", parsCommandMessage[0]);
//        free(parsCommandMessage);
    }
    str_overwrite_stdout();
}

//void sendMessage(char *command, char *arg, int cSocket) {
//    send(cSocket, comm


