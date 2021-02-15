//
// Created by Mykhailo Burenko on 2/5/21.
//
#include "../inc/client.h"

void str_overwrite_stdout() {
    printf("%s", "> ");
    fflush(stdout);
}

void print(char *string){
    printf("%s\n", string);
//    scanf("%[^\n]%*c", login);
}

