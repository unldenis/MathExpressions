#include <stdio.h>
#include <stdlib.h>
#include "api/parser.h"

char *inputString(FILE* fp, size_t size);

int main() {

    printf("> ");

    char *m;
    m = inputString(stdin, 10);

    scanner* sc = initScanner(m);
    if(sc != NULL) {
        scanner_parse(sc);
        parser* pars = initParser(sc);

        /*
        Debug tokens
        for(int i=0; i < pars->list->used; i++) {
            token_debug(&pars->list->array[i]);
        }
        */

        double result = parser_parse(pars);
        printf("Result: %lf\n", result);


        // free char* string
        free(m);
        // free scanner
        free(sc);
        // free parser
        freeParser(pars);
    }
    
    // close
    printf("Press ENTER a few times to terminate the program");
    fflush(stdout);
    getchar(); getchar(); getchar(); getchar();
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