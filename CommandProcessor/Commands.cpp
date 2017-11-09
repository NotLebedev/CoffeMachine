//
// Created by Tema on 01.11.2017.
//

#include <cstddef>
#include <string>
#include <unordered_map>

const char *LITERAL = "LITERAL";

const char *PICK = "PICK";
const char *ROLL = "ROLL";

const char *OUT = ".";

const char *ADD = "+";
const char *MULTIPLY = "*";
const char *DIVIDE = "/";

const char *XOR = "XOR";
const char *AND = "AND";
const char *RSHIFT = "RSHIFT";
const char *LSHIFT = "LSHIFT";
const char *EQUALS0 = "0=";

const char *FETCH = "@";
const char *STORE = "!";

const char *HALT = "HALT";

std::unordered_map<std::string, size_t> commands = {

        {LITERAL,  0},

        {PICK,     1},
        {ROLL,     2},

        {OUT,      3},

        {ADD,      4},
        {MULTIPLY, 6},
        {DIVIDE,   7},

        {XOR,      5},
        {AND,      13},
        {RSHIFT,   11},
        {LSHIFT,   12},
        {EQUALS0,  14},

        {HALT,     8},

        {FETCH,    9},
        {STORE,    10}

};
