#include "libmx.h"

char *mx_concatenation(char **inp) {
    char *result = "";
    for(int i=0; i<mx_arrlen(inp); i++) {
        mx_strcat(result,inp[i]);
    }
    return result;
}
