#include "api/token.h"

struct token * initToken(tokentype type, int value) {
    struct token * tmp = malloc (sizeof (struct token));
    tmp->tokentype = type;
    tmp->intvalue = value;
    return tmp;
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
        case '(':
            return TT_L_PAREN;
        case ')':
            return TT_R_PAREN;
        default:
            printf("Operator not available for the character %c", c);
            exit(1);
    }
}

void token_debug(struct token *t) {
    char szBuffer[50];
    if(t->tokentype == TT_NUMBER) {
        snprintf(szBuffer, sizeof(szBuffer), "Token {type='Number', value='%d'}", t->intvalue);
    } else {
        snprintf(szBuffer, sizeof(szBuffer), "Token {type='%s'}", token_getTokenTypeName(t->tokentype));
    }
    printf("%s\n", szBuffer);
}

const char* token_getTokenTypeName(tokentype type) {
   switch (type) {
      case TT_NUMBER: return "Number";
      case TT_PLUS: return "Plus";
      case TT_MINUS: return "Minus";
      case TT_CROSS: return "Cross";
      case TT_DIVISION: return "Division";
      case TT_L_PAREN: return "L_Parent";
      case TT_R_PAREN: return "R_Parent";
      default:
        printf("Token type name not available for type %d", type);
        exit(1);
   }
}