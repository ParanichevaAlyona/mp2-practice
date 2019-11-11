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
	char tmp[20];


	cout << '\n';
	res = Calculator::Calculate(ss, tmp);
	cout << res << '\n';
}
