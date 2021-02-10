#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;
    int j = 0;


    while (src[i]) {
        if (!( src[i] >= 0 && src[i] <= 31 )){
            dst[i] = src[i];
            j++;
        }
        i++;
    }
    dst[i] = '\0';
    return dst;
}
