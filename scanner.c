#include "api/scanner.h"
#include <ctype.h>  //isdigit

scanner *initScanner (char *source) {
    scanner *s = (scanner *) malloc (sizeof (scanner));
    if (s == NULL)
        return NULL;

    s->data = source;
    s->current = 0;
    initTokenList (&s->list, 10);
    return s;
}


void scanner_parse(scanner *s) {
    
    char peekChar;
    do {
        peekChar = scanner_peek(s);
        if(peekChar == '\0') {
            break;
        }
        //printf("%c\n", peekChar);    
        
        switch(peekChar) {
            case ' ':
            case '\n':
            case '\t':
            case '\r':
                s->current++;
                break;
            case '+':        
            case '-':           
            case '*':      
            case '/': 
            case '(': 
            case ')':
                scanner_addToken(s, token_type_from_char(peekChar), 0);
                s->current++;
                break;

            default:
                // if is a digit get number
                if(isdigit(peekChar)) {

                    int index = 0;
                    int number = 0;
                    while(isdigit(peekChar)) {
                        int tmp = peekChar - '0'; 
                        number = number * 10 + tmp;

                        //next
                        index++;
                        s->current++;
                        peekChar = scanner_peek(s);

                    }        
                    scanner_addToken(s, TT_NUMBER, number);           
                } else {
                    printf("Invalid character(%c) at index %d", peekChar, s->current);
                    exit(1);
                }
        }
        
    } while (1);

}


char scanner_peek(scanner *s) {
    return s->data[s->current];
}

void scanner_addToken(scanner *s, tokentype type, int intval) {
    struct token * tmp = initToken(type, intval);
    insertTokenList(&s->list, tmp);
}