#include "../headers/functions.h"

template<typename T>
bool isInArray(T* arr, T value) {
    for(int i = std::begin(arr); i < std::end(arr); ++i) {
        if(value == (*arr)[i]) {
            return true;
        }
    }
    return false;
}