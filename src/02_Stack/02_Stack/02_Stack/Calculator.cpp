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

std::string Calculator::Postfix(std::string s)
{
    TStack<char> post(20);
    TStack<char> stack(20);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            stack.Push(s[i]);
        if (isalpha(s[i]))
            post.Push(s[i]);
        if ((s[i] == '*') || (s[i] == '/') || (s[i] == '+') || (s[i] == '-'))
        {
            if (!stack.IsEmpty())
                if (Priority(stack.Getlast()) >= Priority(s[i]))
				{
                    post.Push(stack.Getlast());
					stack.Pop();
				}
            stack.Push(s[i]);
        }
        if (s[i] == ')')
        {
            while (stack.Getlast() != '(')
			{
				post.Push(stack.Getlast());
				stack.Pop();
			}
            stack.Pop();
        }
    }
    while (!stack.IsEmpty())
	{
		post.Push(stack.Getlast());
		stack.Pop();
	}
    int max = post.Top();

	char tmp[20];
    for (int i = 0; i < max; i++)
	{
		tmp[i] = post.Getlast();
		post.Pop();
	}
	for (int j = max; j < 20; j++)
		tmp[j] = '\0';

	std::string str = string(tmp);
	cout << "Postfix form is: " << str << '\n';
    return str;
}

double Calculator::Calculate(std::string ss)
{
    TStack<char> stack(20);
    for (int i = 0;i < ss.length(); i++)
        stack.Push(ss[i]);

    TStack<double> res(20);
    double n, a = 0, b = 0, sum = 0;
    int k = stack.Top();
    for (int i = 0; i < k; i++)
    {
        if (isalpha(stack.Getlast()))
        {
            cout << stack.Getlast() << '\n';
            cin >> n;
            res.Push(n);
        }
        if (stack.Getlast() == '*')
        {
			b = res.Getlast();
			res.Pop();
			a = res.Getlast();
			res.Pop();
            sum = a * b;
            res.Push(sum);
        }
        if (stack.Getlast() == '+')
        {
			b = res.Getlast();
			res.Pop();
			a = res.Getlast();
			res.Pop();
            sum = a + b;
            res.Push(sum);
        }
        if (stack.Getlast() == '-')
        {
			b = res.Getlast();
			res.Pop();
			a = res.Getlast();
			res.Pop();
            sum = a - b;
            res.Push(sum);
        }
        if (stack.Getlast() == '/')
        {
            b = res.Getlast();
			res.Pop();
			a = res.Getlast();
			res.Pop();
            sum = a / b;
            res.Push(sum);
        }
        stack.Pop();
    }
    return sum;
}
