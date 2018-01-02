//
// Created by leog on 02.01.2018.
//

#include "UniversalModuleInterface.h"

UniversalModuleInterface::UniversalModuleInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm) {

    executionProcessor = exec;
    inputProcessor = inpu;
    commandProcessor = comm;

}

UniversalModuleInterface::~UniversalModuleInterface() {

}

ERROR_TYPE UniversalModuleInterface::executeCommand(std::string& command) {

    inputProcessor->stash();

    inputProcessor->push(command);
    commandProcessor->nextCommand();
    inputProcessor->unstash();

    return 0;
}

ERROR_TYPE UniversalModuleInterface::getStack(iWORD *data) {
    return 0;
}

ERROR_TYPE UniversalModuleInterface::getDictionary(iWORD *data, size_t startAdr, size_t endAdr) {
    return 0;
}
