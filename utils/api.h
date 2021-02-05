//
// Created by Mykhailo Burenko on 2/4/21.
//

#ifndef OWN_UCHAT_API_H
#define OWN_UCHAT_API_H

#define CREATE_STRUCT(type) (struct type *) malloc(sizeof (struct type));
#define CREATE(type) (type *) malloc(sizeof (type));
#define CREATE_SIZE(type,size) (type *) malloc(size * sizeof (type));
#define when(predicate, code) case predicate: code break;
#define FOR(start , finish) for(int i = start; i < finish; i++)
#define FOR_N(name,start , finish) for(int name = start; name < finish; name++)

#define LENGTH_MESSAGE 512

#define PORT_SERVER 8080

#define COMMAND_REGISTER "/register"
#define COMMAND_LOGIN "/login"
#define COMMAND_EXIT "/exit"
#define LOGIN }if (strcmp(command,COMMAND_LOGIN) == 0){
#define REGISTER if (strcmp(command,COMMAND_REGISTER) == 0){
#define EXIT }if (strcmp(command,COMMAND_EXIT) == 0){

typedef struct _User{
    int id;
    char *login;
    char *password;
} User;
typedef struct _message{
    int id;
    int idUser;
    char *message;
    long time;
    bool edit;
} Message;

bool isCommand(char *string) {
    int i = 0;
    while (true) {
        if (mx_is_space(string[i]))string++;
        else if (string[i] == '/') return true;
        else return false;
    }
}

#endif //OWN_UCHAT_API_H
