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

    int tokentype;
    char *value;
    int intvalue;

};

struct token *initToken (tokentype type, char *v, int intvalue);

void freeToken (struct token *token);

tokentype token_type_from_char(char c);

#endif