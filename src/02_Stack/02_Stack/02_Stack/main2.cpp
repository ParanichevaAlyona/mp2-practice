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
	ss = Calculator::Postfix(s);
	res = Calculator::Calculate(ss);
	cout << res << '\n';
}
