#include <iostream>
#include <string>
#include "TStack.h"
#include "HCalculator.h"

using namespace std;

int Calculator::Priority(char o)
{
    switch (o)
    {
    case '*':
        return 3;
    case '/':
        return 3;
    case '+':
        return 2;
    case '-':
        return 2;
    case '(':
        return 1;
    default:
        cout << "Wrong Operation!" << o;
        break;
    }
}

bool Calculator::Mistakes(std::string s)
{
	if (s.length() == 0)
		throw "The line is empty";
	if (s[0] == ')')
		throw "You cannot start with a bracket )";
	int r = 0, l = 0, a = 0, o = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			if (i != 0)
				if (s[i - 1] == ')')
					throw "Brackets together )(";
			r++;
		}
		if (s[i] == ')')
		{
			if (i != 0)
				if (s[i - 1] == '(')
					throw "Brackets together ()";
			l++;
		}
		if (isalpha(s[i]))
			a++;
		if ((s[i] == '*') || (s[i] == '/') || (s[i] == '+') || (s[i] == '-'))
			o++;
	}
	if ((r > l) || (l > r))
		throw "Different number of brackets";
	if (o >= a)
		throw "Not enough operands";
	if ((o + 1) != a)
		throw "Too mach operands";
	return true;
}

std::string Calculator::Postfix(std::string s)
{
	int n = 0;
    TStack<char> post(20);
    TStack<char> stack(20);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            stack.Push(s[i]);
        if (isalpha(s[i]))
		{
            post.Push(s[i]);
		}
        if ((s[i] == '*') || (s[i] == '/') || (s[i] == '+') || (s[i] == '-'))
        {
            if (!stack.IsEmpty())
                if (Priority(stack.Top()) >= Priority(s[i]))
				{
                    post.Push(stack.Top());
					stack.Pop();
				}
            stack.Push(s[i]);
        }
        if (s[i] == ')')
        {
            while (stack.Top() != '(')
			{
				post.Push(stack.Top());
				stack.Pop();
			}
            stack.Pop();
        }
    }
    while (!stack.IsEmpty())
	{
		post.Push(stack.Top());
		stack.Pop();
	}

	char tmp[20];
    int i = 0;
    while (!post.IsEmpty())
    {
        tmp[i] = post.Top();
        post.Pop();
        i++;
    }
	for (int j = i; j < 20; j++)
		tmp[j] = '\0';


	std::string str = string(tmp);
	for (int j = 0; j < i / 2; j++)
		swap(str[j], str[i - j - 1]);
	cout << "Postfix form is: " << str << '\n';
    return str;
}

void Calculator::GettingValues(std::string str, char*& let, double*& val, int& n)
{
	n = 0;
	for (int i = 0; i < str.length(); i++)
		if (isalpha(str[i]))
			n++;
	int f;
	let = new char[n];
	val = new double[n];
	n = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i]))
		{
			f = 0;
			for (int j = 0; j < n; j++)
				if (str[i] == let[j])
					f++;
			if (f == 0)
			{
				let[n] = str[i];
				n++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << let[i] << '\n';
		cin >> val[i];
	}
}

double Calculator::Calculate(std::string str, char* let, double* val, int n)
{
    TStack<double> stack(str.length());
	
	char tmp;
    double a = 0, b = 0, sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		tmp = str[i];
		if (isalpha(tmp))
        {
			for (int j = 0; j < n; j++)
				if (tmp == let[j])
				{
					stack.Push(val[j]);
					break; 
				}
        }
		if (tmp == '*')
        {
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
            sum = a * b;
			stack.Push(sum);
        }
        if (tmp == '+')
        {
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
            sum = a + b;
			stack.Push(sum);
        }
        if (tmp == '-')
        {
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
            sum = a - b;
			stack.Push(sum);
        }
        if (tmp == '/')
        {
            b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
            sum = a / b;
			stack.Push(sum);
		}
    }
    return sum;
}
