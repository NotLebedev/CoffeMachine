//
// Created by leog on 02.01.2018.
//

#ifndef COFFEMACHINE_UNIVERSALMODULEINTERFACE_H
#define COFFEMACHINE_UNIVERSALMODULEINTERFACE_H


#include <string>
#include "../Globals.h"

class UniversalModuleInterface {

public:
    UniversalModuleInterface();

    virtual ~UniversalModuleInterface();

    ERROR_TYPE executeCommand(std::string command);

    ERROR_TYPE getStack(iWORD *data);

    ERROR_TYPE getDictionary(iWORD *data, size_t startAdr, size_t endAdr);

};


#endif //COFFEMACHINE_UNIVERSALMODULEINTERFACE_H
