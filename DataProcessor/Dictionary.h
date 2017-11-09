//
// Created by Tema on 06.11.2017.
//

#ifndef COFFEMACHINE_DICTIONARY_H
#define COFFEMACHINE_DICTIONARY_H


#include <cstdint>
#include <cstddef>
#include "../Globals.h"

#define MEMORY_SIZE 65536

#define CONTEXT_ADR     0 // Top most word
#define STATE_ADR       2 // State : Compile / Execute
#define TOP_ADR         3 // First free block of dictionary

class Dictionary {

public:
    Dictionary();

    virtual ~Dictionary();

    ERROR_TYPE fetch(size_t idx, iWORD *data);

    ERROR_TYPE store(size_t idx, iWORD *data);

private:
    iWORD *dictionary;

};


#endif //COFFEMACHINE_DICTIONARY_H
