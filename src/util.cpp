#include "../headers/util.h"

char* readFileContent(char* path) {
    FILE* file = fopen(path, "r");
    if(!file) {
        std::cout << "Could not open file \n";
        return nullptr;
    }

    long size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    return buf;
}