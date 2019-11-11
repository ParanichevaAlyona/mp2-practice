#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "TStack.h"
#include <string>

class Calculator
{
    static int Priority(char);
public:
    static std::string Postfix(std::string);
    static double Calculate(std::string, char*);
};

#endif
