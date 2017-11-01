//
// Created by Tema on 01.11.2017.
//

#ifndef COFFEMACHINE_COMMANDS_H
#define COFFEMACHINE_COMMANDS_H

#include <cstddef>
#include <string>
#include <unordered_map>

extern const char *DUPLICATE;
extern const char *DROP;
extern const char *OVER;
extern const char *ROTATE;
extern const char *SWAP;
extern const char *PICK;
extern const char *ROLL;

extern const char *OUT;

extern const char *ADD;
extern const char *SUBSTRACT;
extern const char *MULTIPLY;
extern const char *DIVIDE;
extern const char *MODULE;
extern const char *NEGATE;

extern const char *HALT;

extern std::unordered_map<std::string, size_t> commands;

#endif //COFFEMACHINE_COMMANDS_H
