//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_EXECUTIONPROCESSOR_H
#define COFFEMACHINE_EXECUTIONPROCESSOR_H


#include <cstdint>

#include "../DataProcessor/DataProcessor.h"
#include "../Types.h"

class ExecutionProcessor {

public:
    ExecutionProcessor();

    //Stack commands
    ERROR_TYPE stackIN(WORD *data);     // Number
    ERROR_TYPE stackOut();              // .
    ERROR_TYPE duplicate();             // DUP
    ERROR_TYPE drop();                  // DROP
    ERROR_TYPE over();                  // OVER
    ERROR_TYPE rotate();                // ROT
    ERROR_TYPE swap();                  // SWAP
    ERROR_TYPE pick();                  // PICK
    ERROR_TYPE roll();                  // ROLL
    //Math commands
    ERROR_TYPE add();                   // +
    ERROR_TYPE substract();             // -
    ERROR_TYPE multiply();              // *
    ERROR_TYPE divide();                // /
    ERROR_TYPE module();                //MOD
    ERROR_TYPE negate();                //NEGATE

private:
    DataProccessor *dataProccesor;

};


#endif //COFFEMACHINE_EXECUTIONPROCESSOR_H