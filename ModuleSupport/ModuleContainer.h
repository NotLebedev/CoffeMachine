//
// Created by leog on 03.01.2018.
//

#ifndef COFFEMACHINE_MODULECONTAINER_H
#define COFFEMACHINE_MODULECONTAINER_H

#include <string>
#include "UniversalModuleInterface.h"

typedef std::string* (__stdcall *f_init)     (UniversalModuleInterface *universalModuleInterface);
typedef void         (__stdcall *f_delete)   ();
typedef void         (__stdcall *f_execWord) (std::string word);

struct ModuleContainer {

    f_init initFunction;
    f_delete deleteFunction;
    f_execWord execWordFunction;


};


#endif //COFFEMACHINE_MODULECONTAINER_H
