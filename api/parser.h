#ifndef MATH_PARSER_H
#define MATH_PARSER_H

#include <stdlib.h>
#include "scanner.h"
#include <stdio.h>


typedef struct {

    tokenlist * list;
    size_t index;
    
} parser;

parser * initParser(scanner * sc);

void freeParser(parser * p);

struct token * parser_current(parser * p);

struct token * parser_eat(parser * p);

double parser_parsePrimary(parser * p);

double parser_parseUnary(parser * p);

double parser_parseFactor(parser * p);

double parser_parseTerm(parser * p);

double parser_parse(parser * p);

#endif
