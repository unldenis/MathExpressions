#ifndef MATH_SCANNER_H
#define MATH_SCANNER_H

#include <stdlib.h>
#include "tokenlist.h"
#include <stdio.h>

typedef struct {
    char *data;   
    size_t current;
    tokenlist *tokenlist;
} scanner;

scanner *initScanner (char *source);

void scanner_parse(scanner *s);

void freeScanner (scanner *scanner);

char scanner_peek(scanner *s);

void scanner_addToken(scanner *s, tokentype type, char *v, int intval);

char* scanner_charToStr(char c);

#endif