#include <iostream>
#include "TStack.h"
#include "HCalculator.h"
using namespace std;

void main()
{

	char* s;
	s = new char[60];
	cin.getline(s, 60);
	cout << s << '\n';
	cout << "The result is " << Calculator :: Calculate(s) << '\n';
}