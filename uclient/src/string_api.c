//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/client.h"
bool isSpace(char ch) {
    char *arr = " \n\t\v\r\f";
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (ch == arr[i]) return true;
    }
    return false;
}
char *rm_first_spas(char *string) {
    char *tmp = string;
    while (true) {
        if (tmp[0] == ' ')
            tmp++;
        else break;
    }
    string = tmp;
    return tmp;
}

bool isEntry(char *str){
    for (int i = 0; str[i] !='\0';i++){
        if (!isSpace(str[i])){
            return false;
        }
    }
    return true;
}



