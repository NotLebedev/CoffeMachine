//
// Created by leog on 02.01.2018.
//

#ifndef COFFEMACHINE_UNIVERSALMODULEINTERFACE_H
#define COFFEMACHINE_UNIVERSALMODULEINTERFACE_H


#include <string>
#include "../Globals.h"
#include "../ExecutionProcessor/ExecutionProcessor.h"
#include "../InputProcessor.h"
#include "../CommandProcessor/CommandProcessor.h"

class UniversalModuleInterface {

public:

    virtual ERROR_TYPE executeCommand(std::string& command);

    virtual ERROR_TYPE getStack(iWORD *data);

    virtual ERROR_TYPE getDictionary(iWORD *data, size_t startAdr, size_t endAdr);

    UniversalModuleInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm);

    virtual ~UniversalModuleInterface();

private:
    ExecutionProcessor *executionProcessor;
    InputProcessor *inputProcessor;
    CommandProcessor *commandProcessor;

};


#endif //COFFEMACHINE_UNIVERSALMODULEINTERFACE_H
