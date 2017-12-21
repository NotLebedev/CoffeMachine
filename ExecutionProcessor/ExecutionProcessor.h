//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_EXECUTIONPROCESSOR_H
#define COFFEMACHINE_EXECUTIONPROCESSOR_H

#include "../DataProcessor/DataProcessor.h"
#include "../Globals.h"

class ExecutionProcessor {

public:
    ExecutionProcessor();

    virtual ~ExecutionProcessor();

    //Stack commands
    ERROR_TYPE stackIN(iWORD *data);     // Number
    ERROR_TYPE emit();                  // EMIT
    ERROR_TYPE pick();                  // PICK
    ERROR_TYPE roll();                  // ROLL
    //Math commands
    ERROR_TYPE add();                   // +
    ERROR_TYPE multiply();              // *
    ERROR_TYPE divide();                // /
    ERROR_TYPE xorr();                  // XOR
    ERROR_TYPE andd();                  // AND
    ERROR_TYPE rshift();                // RSHIFT
    ERROR_TYPE lshift();                // LSHIFT
    ERROR_TYPE eqaulsZero();            // =0
    //Dictionary commands
    ERROR_TYPE fetch();                 // @
    ERROR_TYPE store();                 // !

    //Machine commands
    ERROR_TYPE stackOut(iWORD *data);

private:
    DataProcessor *dataProccesor;

};


#endif //COFFEMACHINE_EXECUTIONPROCESSOR_H
