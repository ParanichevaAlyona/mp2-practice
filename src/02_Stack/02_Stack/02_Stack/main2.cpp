#include <iostream>
#include <string>
#include "TStack.h"
#include "HCalculator.h"

using namespace std;

void main()
{
	std::string s, ss;
	double res;
	cout << "~~~~~ Welcome. This is a calculator with brackets ~~~~~" <<'\n';
	getline(cin, s);
	cout << s << '\n';
	try
	{
		ss = Calculator::Postfix(s);
	}
	catch(const char* sms)
	{
		cout << sms << endl;
	}
	char* let;
	double* val;
	int n;
	Calculator::GettingValues(ss, let, val, n);
	res = Calculator::Calculate(ss, let, val, n);
	
	cout << "The result is "<< res << '\n';
	delete[] let;
	delete[] val;
}
