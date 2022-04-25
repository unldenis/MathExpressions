#ifndef MATH_TOKEN_LIST_H
#define MATH_TOKEN_LIST_H

#include <stdlib.h>
#include "token.h"
#include <stdio.h>

typedef struct {
  struct token **array;
  size_t used;
  size_t size;
} tokenlist;

tokenlist * initTokenList(size_t initialSize);

void insertToken(tokenlist *a, struct token *element);

void freeTokenList(tokenlist *a);

#endif