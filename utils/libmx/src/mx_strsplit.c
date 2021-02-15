#include "../inc/libmx.h"
#include <stdio.h>
#include <stdlib.h>


char **mx_strsplit(const char *s, char c) {
//    printf("0");
    int i = 0;
//    printf("1");
    int begin = 0;
//    printf("2");
    int size = mx_count_words(s, c);
//    printf("3");
    char *tmp = mx_strtrim_char(s, c);
//    printf("4");
    char **result = (char **) malloc(sizeof(char *) * (size + 1));
//    printf("5");
    if (tmp)
//        printf("6");
    for (int k = 0; k < size; k++) {
//        printf("k = %d\n", k);
        while (tmp[i] && tmp[i] == c)
            i++;
        begin = i;
        while (tmp[i] && tmp[i] != c)
            i++;
//        printf("set\n");
//        printf("i = %d\n",i - begin);
//        printf("char = %s\n",&tmp[begin]);
        result[k] = mx_strndup(&tmp[begin], i - begin);
//        printf("seted\n");
    }
//    printf("7");
    result[size] = NULL;
//    printf("8");
    mx_strdel(&tmp);
//    printf("9");
    return result;
}
