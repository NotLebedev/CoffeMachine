//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_TYPES_H
#define COFFEMACHINE_TYPES_H

#include <cstdint>

#define ERROR_TYPE std::int8_t
#define iWORD std::int32_t

#endif //COFFEMACHINE_TYPES_H

#ifndef COFFEMACHINE_ERROR_CODES_H
#define COFFEMACHINE_ERROR_CODES_H

#define SUCCES 0
#define STACK_OUT_OF_SIZE           (-1)
#define STACK_NO_ELEMENTS           (-2)
#define STACK_ELEMENT_NOT_CONTAINED (-3)
#define WORD_NOT_FOUND              (-10)
#define STANDART_COMMAND_NOT_FOUND  (-11)
#define END_OF_INPUT                (-21)
#define ERROR_LOADING_MODULES       (-31)

#endif //COFFEMACHINE_ERROR_CODES_H
