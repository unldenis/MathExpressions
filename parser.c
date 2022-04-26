#include "api/parser.h"

parser * initParser(scanner * sc) {
    parser * p = malloc(sizeof(parser));
    p->list = &sc->list;
    p->index = 0;
    return p;
}

void freeParser(parser * p) {
    if(p != NULL) {
        freeTokenList(p->list);
        free(p);
    }
}

struct token * parser_current(parser * p) {
    return &p->list->array[p->index];
}

struct token * parser_eat(parser * p) {
    struct token * t = parser_current(p);
    p->index++;
    return t;
}

double parser_parsePrimary(parser * p) {
    if(parser_current(p)->tokentype == TT_L_PAREN) {
        // L_PAREN
        parser_eat(p);
        double paren = parser_parseTerm(p);
        if(parser_current(p)->tokentype != TT_R_PAREN) {
            printf("Closing parenthesis expected at %d but found %s.", p->index - 1, parser_current(p)->tokentype);
            exit(1);
        }
        // R_PAREN
        parser_eat(p);
        return paren;
    }

    struct token * t = parser_eat(p);
    if(t->tokentype != TT_NUMBER) {
        printf("Number expected at %d but found %s.", p->index - 1, token_getTokenTypeName(t->tokentype));
        exit(1);
    }
    return (double) t->intvalue;
}


double parser_parseUnary(parser * p) {
    if(parser_current(p)->tokentype == TT_MINUS) { 
        // Minus
        parser_eat(p);
        double right = parser_parsePrimary(p);
        return -right;
    }
    return parser_parsePrimary(p);
}

double parser_parseFactor(parser * p) {
    double left = parser_parseUnary(p);
    while(p->index < p->list->used && (parser_current(p)->tokentype == TT_CROSS || parser_current(p)->tokentype == TT_DIVISION)) {
        struct token * operator = parser_eat(p);
        double right = parser_parseUnary(p);
        if(operator->tokentype == TT_CROSS) {
            left *= right;
        } else {
            left /= right;
        }
    }
    return left;
}

double parser_parseTerm(parser * p) {
    double left = parser_parseFactor(p);
    while(p->index < p->list->used && (parser_current(p)->tokentype == TT_PLUS || parser_current(p)->tokentype == TT_MINUS)) {
        struct token * operator = parser_eat(p);
        double right = parser_parseFactor(p);
        if(operator->tokentype == TT_PLUS) {
            left += right;
        } else {
            left -= right;
        }
    }
    return left;
}

double parser_parse(parser * p) {
    return parser_parseTerm(p);
}
