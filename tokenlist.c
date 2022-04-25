#include "api/tokenlist.h"

/*
void initTokenList(tokenlist *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(token *));
  printf("2\n");
  a->used = 0;
  printf("3\n");
  a->size = initialSize;
  printf("4\n");
}
*/

tokenlist * initTokenList(size_t initialSize) {
  tokenlist* tlist = malloc(initialSize * sizeof(struct token *) + sizeof(size_t) + sizeof(size_t));
  tlist -> used = 0;
  tlist -> size = initialSize;
  return tlist;
}

void insertToken(tokenlist *a, struct token *element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(struct token *));
  }
  a->array[a->used++] = element;
}

void freeTokenList(tokenlist *a) {
  for(unsigned i = 0; i < a->used; i++) {
      freeToken(a->array[i]);
  }
  //free(a->array); doesn't delete the string value
  a->array = NULL;
  a->used = a->size = 0;
}