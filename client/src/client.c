#include "../inc/client.h"

bool isLogin = false;
void setIsLogin(bool f){
    isLogin = f;
}
bool getIsLogin(){
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
char name[32];



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
void  printArr(char **arr){
    int i = 0;

    while(arr[i]) {
        printf("%s\n",arr[i]);
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
        printf("%s\n",res[size]);
        printf("%s\n",pch);
        size++;
        pch = strtok(NULL, sep);
    }
    res[size] = "\0";
    return res;
}

void *send_msg_handler() {
//    char buffer[LENGTH + 32];

//    char *tmp = "/login user 123";

//    send(sockfd, tmp, strlen(tmp), 0);

    while (1) {
        char *message = CREATE_SIZE(char ,LENGTH);

//        bzero(message, LENGTH);
        str_overwrite_stdout();
        fgets(message, LENGTH, stdin);
        str_trim_lf(message, LENGTH);

        if (isCommand(message)) {
            reconnect(sockfd);
//            printArr(toCommandWithArg(message));
            if (isCommandExit(message)) {
                break;
            } else runCommandClient(message,sockfd);
        } else {
            if (getIsLogin()) {
//                sprintf(buffer, "%s: %s\n", name, message);
                runCommandClientMessage(message,sockfd);
            }
        }

        free(message);
//        bzero(buffer, LENGTH + 32);
    }
    catch_ctrl_c_and_exit();
    return NULL;
}

void *recv_msg_handler() {
    char message[LENGTH];
    while (1) {
        int receive = recv(sockfd, message, LENGTH, 0);
//        printf("message :%s \n recv: %d", message,receive);
        if (receive > 0) {
            printf("recv_msg_handler = %s", message);
            str_overwrite_stdout();
            runCommandServer(message);
        } else if (receive == 0) {
            break;
        } else {
            // -1
        }
        memset(message, 0, sizeof(message));
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

    pthread_t recv_msg_thread;
    if (pthread_create(&recv_msg_thread, NULL, &recv_msg_handler, NULL) != 0) {
        printf("ERROR: pthread\n");
        return EXIT_FAILURE;
    }

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
    if (send(socketNum, "",  0, 0) == -1) {
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

