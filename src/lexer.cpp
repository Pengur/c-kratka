#include "../headers/lexer.h"
#include "../headers/token.h"


Lexer *Lexer::init(char *content) {
    Lexer* lexer = (Lexer*) calloc(1, sizeof(Lexer));
    lexer->content = content;
    lexer-> i = 0;
    lexer->cc = content[lexer->i];
    lexer->keywords = {"int", "float"};

    return lexer;
}


void Lexer::next(Lexer *lexer) {
    if(lexer->cc != '\0' && lexer->i < strlen(lexer->content)) {
        lexer->i += 1;
        lexer->cc = lexer->content[lexer->i];
    }
}


Token* Lexer::getToken(Lexer *lexer) {
    while(lexer->cc != '\0' && lexer->i < strlen(lexer->content)) {
        if(lexer->cc == ' ' || lexer->cc == '\n') {
            lexer->skipEmpty(lexer);
        }
        switch(lexer->cc) {
//            TODO: Add more token types
//            case '=':
//                break;
//            case '+':
//                break;
//            case '-':
                break;
            case '(':
                lexer->next(lexer);
                return Token::init(Token::lParen, "(");
            case ')':
                lexer->next(lexer);
                return Token::init(Token::rParen, ")");
            case '{':
                lexer->next(lexer);
                return Token::init(Token::lbracket, "{");
            case '}':
                lexer->next(lexer);
                return Token::init(Token::rBracket, "}");
            case ';':
                lexer->next(lexer);
                return Token::init(Token::semicolon, ";");
        }
//      TODO: Think about better solution for disguising id from
        char* word = getWord(lexer);
        if(isInVector(word, &lexer->keywords)) { //  Is keyword
            lexer->next(lexer);
            return Token::init(Token::keyword, word);
        }
        return Token::init(Token::id, word);
    }
    return nullptr;
}


char* Lexer::getWord(Lexer* lexer) {
    char* value = (char*) calloc(1, sizeof(char));
    value[0] = '\0';

    while(lexer->cc != ' ' && lexer->cc != '\n' && lexer->cc != '(' && lexer->cc != ';') {
//        TODO: Add exception list for id's
        char* s = lexer->getCharAsString(lexer);
        value = (char*) realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        lexer->next(lexer);
    }
//    lexer->next(lexer); //??
    return value;
}


void Lexer::skipEmpty(Lexer* lexer) {
    while(lexer->cc == ' ' || lexer->cc == '\n') {
        lexer->next(lexer);
    }
}


void Lexer::skipLine(Lexer *lexer) {
//        TODO: implement commenting lines
}


char* Lexer::getCharAsString(Lexer* lexer) {
    char* str = (char*) calloc(2, sizeof(char));
    str[0] = lexer->cc;
    str[1] = '\0';

    return str;
}