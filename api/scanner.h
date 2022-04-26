#ifndef MATH_SCANNER_H
#define MATH_SCANNER_H

#include <stdlib.h>
#include "tokenlist.h"
#include <stdio.h>

typedef struct {
    char *data;   
    size_t current;
    tokenlist list;
} scanner;

scanner *initScanner (char *source);

void scanner_parse(scanner *s);

char scanner_peek(scanner *s);

void scanner_addToken(scanner *s, tokentype type, int intval);

#endif