//
// Created by Tema on 06.11.2017.
//

#ifndef COFFEMACHINE_DICTIONARY_H
#define COFFEMACHINE_DICTIONARY_H


#include <cstdint>
#include <cstddef>
#include "../Types.h"

#define MEMORY_SIZE 65536

#define CONTEXT_ADR 0
#define CURRENT_ADR 1
#define STATE_ADR   2

class Dictionary {

public:
    Dictionary();

    ERROR_TYPE fetch(size_t idx, WORD *data);
    ERROR_TYPE store(size_t idx, WORD *data);

private:
    WORD *dictionary;

};


#endif //COFFEMACHINE_DICTIONARY_H
