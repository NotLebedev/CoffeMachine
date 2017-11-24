//
// Created by Tema on 13.11.2017.
//

#ifndef COFFEMACHINE_INPUTPROCESSOR_H
#define COFFEMACHINE_INPUTPROCESSOR_H


#include <queue>
#include <string>
#include "Globals.h"

class InputProcessor {

public:
    InputProcessor();

    virtual ~InputProcessor();

    ERROR_TYPE push(std::string input);

    ERROR_TYPE pop(std::string &word);

private:
    std::queue<std::string> *inputQueue;

};


#endif //COFFEMACHINE_INPUTPROCESSOR_H
