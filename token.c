#include "api/token.h"

struct token *initToken (tokentype type, char *v, int intvalue) {
    struct token *t = malloc (sizeof (struct token));
    if (t == NULL) {
        printf("Cannot malloc {%s}", v);
        return NULL;
    }
    t->tokentype = type;
    t->value = v;
    t->intvalue = intvalue;
    return t;

}

void freeToken (struct token *token) {
    if (token != NULL) {
        free (token->value);
        free (token);
    }
}


tokentype token_type_from_char(char c) {
    switch (c) {
        case '+':
            return TT_PLUS;
        case '-':
            return TT_MINUS;
        case '*':
            return TT_CROSS;
        case '/':
            return TT_DIVISION;
        default:
            printf("Operator not available for the character %c", c);
            exit(1);
    }
}
