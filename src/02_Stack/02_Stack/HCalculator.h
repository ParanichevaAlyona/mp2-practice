#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "TStack.h"

class Calculator
{
private:
	static int Priority(char);
public:
	static double Calculate(char*);
};

#endif