#pragma once

#include <vector>
#include <iostream>
#include <cstring>

#include "../headers/functions.h"
#include "../headers/token.h"

class Lexer {
public:
    char cc; // Current char
    int i;  // Current index
    int line;
    char* content;

    std::vector<Token*> tokens;
    std::vector<char*> keywords;

    static Lexer* init(char* content);
    void next(Lexer* lexer);
    Token* getToken(Lexer* lexer);
    char* getWord(Lexer* lexer);
    char* getString(Lexer* lexer);
    char* getCharAsString(Lexer* lexer);
    void skipEmpty(Lexer* lexer);
    void skipLine(Lexer* lexer);
};
