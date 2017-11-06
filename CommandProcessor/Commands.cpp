//
// Created by Tema on 01.11.2017.
//

#include <cstddef>
#include <string>
#include <unordered_map>

const char *DUPLICATE = "DUP";
const char *DROP = "DROP";
const char *OVER = "OVER";
const char *ROTATE = "ROT";
const char *SWAP = "SWAP";
const char *PICK = "PICK";
const char *ROLL = "ROLL";

const char *OUT = ".";

const char *DECIMAL = "DECIMAL";
const char *HEXAL = "HEX";
const char *OCTAL = "OCTAL";

const char *ADD = "+";
const char *SUBSTRACT = "-";
const char *MULTIPLY = "*";
const char *DIVIDE = "/";
const char *MODULE = "MOD";
const char *NEGATE = "NEGATE";

const char *FETCH = "@";
const char *STORE = "!";

const char *HALT = "HALT";

std::unordered_map<std::string, size_t> commands = {

        {DUPLICATE, 0},
        {DROP, 1},
        {OVER, 2},
        {ROTATE, 3},
        {SWAP, 4},
        {PICK, 5},
        {ROLL, 6},

        {OUT, 7},

        {DECIMAL, 15},
        {HEXAL, 16},
        {OCTAL, 17},

        {ADD, 8},
        {SUBSTRACT, 9},
        {MULTIPLY, 10},
        {DIVIDE, 11},
        {MODULE, 12},
        {NEGATE, 13},

        {HALT, 14},

        {FETCH, 18},
        {STORE, 19}
};
