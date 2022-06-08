#pragma once

#include <cstdlib>


class Token {
public:

    enum tokenType {
        keyword,
        returnKeyword,
        id,
        lParen,
        rParen,
        lbracket,
        rBracket,
        semicolon,
        plus,
        minus,
        assing,
        string
    };

    tokenType type;
    char* value;

    static Token* init(tokenType type, char* value);
};
