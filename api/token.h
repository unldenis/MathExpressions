#ifndef MATH_TOKEN_H
#define MATH_TOKEN_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {

    TT_NUMBER,
    TT_PLUS,
    TT_MINUS,
    TT_CROSS,
    TT_DIVISION,

    TT_L_PAREN,
    TT_R_PAREN
} tokentype;

struct token {

    tokentype tokentype;
    double value;

};

struct token * initToken(tokentype type, double value);

tokentype token_type_from_char(char c);

void token_debug(struct token * t);

const char* token_getTokenTypeName(tokentype type);

#endif