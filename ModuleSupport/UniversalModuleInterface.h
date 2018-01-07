//
// Created by leog on 02.01.2018.
//

#ifndef COFFEMACHINE_UNIVERSALMODULEINTERFACE_H
#define COFFEMACHINE_UNIVERSALMODULEINTERFACE_H


#include <string>
#include "../Globals.h"
#include "../ExecutionProcessor/ExecutionProcessor.h"
#include "../InputProcessor.h"

class CommandProcessor;

class UniversalModuleInterface {

public:

    virtual ERROR_TYPE executeCommand(char *command);

    virtual iWORD * getStack();

    virtual iWORD * getDictionary(size_t startAdr, size_t size);

    virtual void setStack(iWORD *data);

    virtual void setDictionary(iWORD *data, size_t startAdr, size_t size);

    virtual const char * getInputString();

    virtual const char * getInputChar();

    UniversalModuleInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm);

    virtual ~UniversalModuleInterface();

private:
    ExecutionProcessor *executionProcessor;
    InputProcessor *inputProcessor;
    CommandProcessor *commandProcessor;

};


#endif //COFFEMACHINE_UNIVERSALMODULEINTERFACE_H
