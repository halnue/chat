//
// Created by Mykhailo Burenko on 2/4/21.
//

#ifndef OWN_UCHAT_API_H
#define OWN_UCHAT_API_H
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
#endif //OWN_UCHAT_API_H
