#include <iostream>

#include "../headers/util.h"
#include "../headers/lexer.h"


int main(int argc, char **argv) {
    char* buf = readFileContent(argv[1]);
    Lexer* lexer = Lexer::init(buf);
    Token* token;
    while ((token = lexer->getToken(lexer)) != nullptr) {
        std::cout << "TOKEN(" << token->type << ", " << token->value << ")" << std::endl;
    }

    return 0;
}
