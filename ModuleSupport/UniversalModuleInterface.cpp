//
// Created by leog on 02.01.2018.
//

#include "UniversalModuleInterface.h"

UniversalModuleInterface::UniversalModuleInterface() {}

UniversalModuleInterface::~UniversalModuleInterface() {

}

ERROR_TYPE UniversalModuleInterface::executeCommand(std::string command) {
    return 0;
}

ERROR_TYPE UniversalModuleInterface::getStack(iWORD *data) {
    return 0;
}

ERROR_TYPE UniversalModuleInterface::getDictionary(iWORD *data, size_t startAdr, size_t endAdr) {
    return 0;
}
