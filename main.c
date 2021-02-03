//#include <stdio.h>
//#include <sqlite3.h>
//#include <zconf.h>
//
//
//void mx_printint(int num);
//void mx_printchar(char c);
//
//int main() {
//    sqlite3 *db;
//    int i = sqlite3_open("users",&db);
//    mx_printint(i);
//    if (i){
//        printf("error    ");
//        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//    } else
//        printf("Ok");
//
//    sqlite3_close(db);
//    return 0;
//}
//
//void mx_printint(int num) {
//    if (num == -2147483648) {
//        write(1, "-2147483648", 11);
//        return;
//    }
//    if (num < 0) {
//        mx_printchar('-');
//        num *= -1;
//    }
//    if (num > 9)
//        mx_printint(num / 10);
//    mx_printchar(num % 10 + 48);
//}
//
//void mx_printchar(char c) {
//    write(1, &c, 1);
//}
