#pragma once

#include <iostream>
#include <vector>
#include <cstring>

template <typename T>
bool isInArray(T* arr, T value);

template<typename T>
bool isInVector(T value, const std::vector<T>* keywords) {
    for(int i = 0; i < keywords->size(); i++) {
        if(!strcmp(value, (*keywords)[i])) {
            return true;
        }
    }
    return false;
}