#include "api/tokenlist.h"

void initTokenList(tokenlist *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(struct token));
  if(a->array == NULL) {
      printf("Cannot malloc tokenlist\n");
      exit(1);
  }
  a->used = 0;
  a->size = initialSize;
}

void insertTokenList(tokenlist *a, struct token *element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(struct token));
  }

  struct token *tmp = &a->array[a->used++];
  tmp->tokentype = element->tokentype;
  tmp->value = element->value;

  // Free token
  free(element);

}

void freeTokenList(tokenlist *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}