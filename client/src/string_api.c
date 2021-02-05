//
// Created by Mykhailo Burenko on 2/5/21.
//

#include "../inc/client.h"

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
