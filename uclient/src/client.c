#include <semaphore.h>
#include <curses.h>
#include "../inc/client.h"
#include "../../userver/inc/server.h"
//#include <stdio.h>
//#include <stdlib.h>
#include <readline/history.h>

t_list *listMessages;












// todo

t_list **getListMessages() {
    return &listMessages;
}

bool isLogin = false;
//t_list *list;

void setIsLogin(bool f) {
    isLogin = f;
}

bool getIsLogin() {
    return isLogin;
}

bool isCommand(char *string) {
    int i = 0;
    while (true) {
        if (mx_is_space(string[i]))string++;
        else if (string[i] == '/') return true;
        else return false;
    }
}


// Global variables
volatile sig_atomic_t flag = 0;
int sockfd = 0;
//char name[32];



void str_trim_lf(char *arr, int length) {
    int i;
    for (i = 0; i < length; i++) { // trim \n
        if (arr[i] == '\n') {
            arr[i] = '\0';
            break;
        }
    }
}

void catch_ctrl_c_and_exit() {
    flag = 1;
}

void printArr(char **arr) {
    int i = 0;

    while (arr[i]) {
        printf("%s\n", arr[i]);
        i++;
    }
    if (i > 0)
        mx_printstr("\n");

}

char **toCommandWithArg(char *command) {
    char **res = CREATE_SIZE(char *, 10)
    int size = 0;
    char *sep = " \n\t\v\r\f";
    char *pch = strtok(command, sep);
    while ((void *) pch != NULL) {
        res[size] = pch;
        printf("%s\n", res[size]);
        printf("%s\n", pch);
        size++;
        pch = strtok(NULL, sep);
    }
    res[size] = "\0";
    return res;
}

//void *send_getch_handler() {
//    char c = wgetch();
////    if (c == (char) KEY_UP) {
//        printf("key up%c\n",c);
////    }
//    return NULL;
//}

void *send_msg_handler() {
//    char buffer[LENGTH + 32];

//    char *tmp = "/login user 123";
    mx_print_unicode(0x128512);
    printf("\n");
//    send(sockfd, tmp, strlen(tmp), 0);
CREATE_SIZE()
    while (1) {
        char *message = mx_strnew(LENGTH);

//        bzero(message, LENGTH);
        str_overwrite_stdout();
        fgets(message, LENGTH, stdin);
        str_trim_lf(message, LENGTH);
//        mx_push_back(list, message);
//        add_history(message);
        if (isCommand(message)) {
//            reconnect(sockfd);
//            printArr(toCommandWithArg(message));
            if (isCommandExit(message)) {
                break;
            } else runCommandClient(message, sockfd);
        } else {
            if (getIsLogin()) {
//                sprintf(buffer, "%s: %s\n", name, message);
                runCommandClientMessage(message, sockfd);
            }
        }

        free(message);
//        bzero(buffer, LENGTH + 32);
    }
    catch_ctrl_c_and_exit();
    return NULL;
}

void *recv_msg_handler() {
    // char message[LENGTH];
    int p[2];
    pipe(p);
    while (1) {
        char *message = mx_strnew(LENGTH);
        int receive = recv(sockfd, message, LENGTH, 0);
        //write(p[1],"receive = ",mx_strlen("receive = "));
        //write(p[1],receive,mx_strlen(receive));
        //write(p[1],"\n",1);
//        write(p[1],"message :",mx_strlen("message :"));
//        write(p[1],message,mx_strlen(message));
//        write(p[1],"\n",1);
        //write(p[1],"recv: ",mx_strlen("recv: "));
        //write(p[1],receive,mx_strlen(receive));
//        printf("receive = %d\n", receive);
//        printf("message :%s \n recv: %d\n", message, receive);
        if (receive > 0) {
//            char **parsCommand = mx_strsplit(message, '\t');
//            printArr(parsCommand);
//            for (int i = 0; parsCommand[i] != NULL; i++) {
            if (isCommand(message)) {
//                printf("recv_msg_handler = \"%s\"\n", message);
//                printf("recv_msg_handler = %d\n", mx_strlen(parsCommand[i]));
                runCommandServer(message);

//                printf("\n%d\n", i);}
            } else {
                printf("%s", message);
                str_overwrite_stdout();
            }
//            }
        } else if (receive == 0) {
            break;
        } else {
            // -1
        }
        // memset(message, 0, sizeof(message));
        free(message);
    }

    return NULL;
}

int main() {
//    if (argc != 2) {
//        printf("Usage: %s <port>\n", argv[0]);
//        return EXIT_FAILURE;
//    }

    char *ip = "127.0.0.1";
    int port = PORT_SERVER;
//            atoi(argv[1]);

    signal(SIGINT, catch_ctrl_c_and_exit);

//    printf("Please enter your name: ");
//    fgets(name, 32, stdin);
//
//    str_trim_lf(name, strlen(name));
//
//
//    if (strlen(name) > 32 || strlen(name) < 2) {
//        printf("Name must be less than 30 and more than 2 characters.\n");
//        return EXIT_FAILURE;
//    }

    struct sockaddr_in server_addr;

    /* Socket settings */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    // Connect to Server
    int err = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (err == -1) {
        printf("ERROR: connect\n");
        return EXIT_FAILURE;
    }

    // Send name
//    send(sockfd, name, 32, 0);

//    printf("=== WELCOME TO THE CHATROOM ===\n");

    pthread_t send_msg_thread;
    if (pthread_create(&send_msg_thread, NULL, &send_msg_handler, NULL) != 0) {
        printf("ERROR: pthread\n");
        return EXIT_FAILURE;
    }
//    pthread_t send_getch_thread;
//    if (pthread_create(&send_getch_thread, NULL, &send_getch_handler, NULL) != 0) {
//        printf("ERROR: pthread\n");
//        return EXIT_FAILURE;
//    }

    pthread_t recv_msg_thread;
    if (pthread_create(&recv_msg_thread, NULL, &recv_msg_handler, NULL) != 0) {
        printf("ERROR: pthread\n");
        return EXIT_FAILURE;
    }
    loadAllMessages(sockfd);
    while (1) {
        if (flag) {
            printf("\nBye\n");
            break;
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}

void reconnect(int socketNum) {
    if (send(socketNum, "", 0, 0) == -1) {
        int sockfd = 0;
        char *ip = "127.0.0.1";
        int port = PORT_SERVER;

        struct sockaddr_in server_addr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(ip);
        server_addr.sin_port = htons(port);

        connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    }
}

//static char inbuf[BUFFER_SZ];
//static size_t inbuf_used = 0;
//void input_pump(struct read_msg_info_s *Info) {
//    size_t inbuf_remain = sizeof(inbuf) - inbuf_used;
//    if (inbuf_remain == 0) {
//        fprintf(stderr, "Line exceeded buffer length!\n");
//    }
//    ssize_t rv = recv(Info->uclient->sockfd, (void*)&inbuf[inbuf_used], inbuf_remain, MSG_DONTWAIT);
//    if (rv == 0) {
//        Info->uclient->is_connected = 0;
//        sem_post(sem_reconnect);
//        return;
//    }
//    if (rv < 0 && errno == EAGAIN) {
//        /* no data for now, call back when the socket is readable */
//        return;
//    }
//    if (rv < 0) {
//        printf("\r-- Disconnected from userver --\n");
//        return;
//    }
//    inbuf_used += rv;
//    /* Scan for newlines in the line buffer; we're careful here to deal with embedded \0s
//    * an evil userver may send, as well as only processing lines that are complete.
//    */
//    char *line_start = inbuf;
//    char *line_end;
//    while ( (line_end = (char*)memchr((void*)line_start, '\n', inbuf_used - (line_start - inbuf))))
//    {
//        *line_end = 0;
//        printf("  > input: %s\n", line_start);
//        to_msg_q(line_start, Info->msg_q_front, Info->lock);
//        sem_post(sem_msg_q);
//        line_start = line_end + 1;
//    }
//    /* Shift buffer down so the unprocessed data is at the start */
//    inbuf_used -= (line_start - inbuf);
//    memmove(inbuf, line_start, inbuf_used);
//}

