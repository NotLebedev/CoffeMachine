//
// Created by leog on 02.01.2018.
//

#include "UniversalModuleInterface.h"
#include "../CommandProcessor/CommandProcessor.h"

UniversalModuleInterface::UniversalModuleInterface(ExecutionProcessor *exec, InputProcessor* inpu, CommandProcessor *comm) {

    executionProcessor = exec;
    inputProcessor = inpu;
    commandProcessor = comm;

}

UniversalModuleInterface::~UniversalModuleInterface() = default;

ERROR_TYPE UniversalModuleInterface::executeCommand(std::string& command) {

    inputProcessor->stash();

    inputProcessor->push(command);
    commandProcessor->nextCommand();
    inputProcessor->unstash();

    return 0;
}

ERROR_TYPE UniversalModuleInterface::getStack(iWORD *data) {

    executionProcessor->stackOut(data);

    return 0;
}

ERROR_TYPE UniversalModuleInterface::getDictionary(iWORD *data, size_t startAdr, size_t size) {

    data = new iWORD[size];

    for (int i = 0; i < size; ++i) {

        auto t = iWORD(startAdr + i);

        executionProcessor->stackIN(&t);
        executionProcessor->fetch();
        executionProcessor->stackOut(&data[i - startAdr]);

    }

    return 0;
}

ERROR_TYPE UniversalModuleInterface::setStack(iWORD *data) {

    executionProcessor->stackIN(data);

    return 0;
}

ERROR_TYPE UniversalModuleInterface::setDictionary(iWORD *data, size_t startAdr, size_t size) {

    for (int i = 0; i < size; ++i) {

        auto t = iWORD(startAdr + i);

        executionProcessor->stackIN(&data[i]);
        executionProcessor->stackIN(&t);
        executionProcessor->store();

    }

    return 0;
}
