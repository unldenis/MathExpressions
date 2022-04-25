#include <stdio.h>
#include <stdlib.h>
#include "api/scanner.h"

char *inputString(FILE* fp, size_t size);

int main() {

    char *m;

    printf("input string : ");
    m = inputString(stdin, 10);

    
    scanner* sc = initScanner(m);
    if(sc != NULL) {
        //printf("Data: %s\n", sc->data);

        scanner_parse(sc);

        freeScanner(sc);

    }
    
    // close
    printf("Program Ended\n");
    return 0;
}

char *inputString(FILE* fp, size_t size){
    //The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start saize
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}