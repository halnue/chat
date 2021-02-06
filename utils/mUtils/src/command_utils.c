//
// Created by Mykhailo Burenko on 2/6/21.
//


#include "../inc/command.h"
bool isCommand(char *string) {
    int i = 0;
    while (true) {
        if (mx_is_space(string[i]))string++;
        else if (string[i] == '/') return true;
        else return false;
    }
}


char **toCommandWithArg(char *command){
    char **res = CREATE_SIZE(char *,10)
    int size = 0;
    char *sep = " \n\t\v\r\f";
    char pch = strtok(command,sep);
    while (pch !=NULL){
        res[size] = pch;
        size++;
        pch = strtok (NULL, sep);
    }
}