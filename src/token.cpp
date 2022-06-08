#include "../headers/token.h"

Token* Token::init(tokenType type, char *value) {
    Token* token = (Token*) calloc(1, sizeof(Token));
    token->type = type;
    token->value = value;

    return token;
}