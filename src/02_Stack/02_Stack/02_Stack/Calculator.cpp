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
	cout << "Postfix form is: " << str << '\n';
    return str;
}

double Calculator::Calculate(std::string ss, char* tmp)
{
    TStack<char> stack(20);
    for (int i = 0;i < ss.length(); i++)
        stack.Push(ss[i]);

    TStack<double> res(20);
    double n, a = 0, b = 0, sum = 0;
    int k = stack.Top();
    for (int i = 0; i < k; i++)
    {
        if (isalpha(stack.Top()))
        {
            cout << stack.Top() << '\n';
            cin >> n;
            res.Push(n);
        }
        if (stack.Top() == '*')
        {
			b = res.Top();
			res.Pop();
			a = res.Top();
			res.Pop();
            sum = a * b;
            res.Push(sum);
        }
        if (stack.Top() == '+')
        {
			b = res.Top();
			res.Pop();
			a = res.Top();
			res.Pop();
            sum = a + b;
            res.Push(sum);
        }
        if (stack.Top() == '-')
        {
			b = res.Top();
			res.Pop();
			a = res.Top();
			res.Pop();
            sum = a - b;
            res.Push(sum);
        }
        if (stack.Top() == '/')
        {
            b = res.Top();
			res.Pop();
			a = res.Top();
			res.Pop();
            sum = a / b;
            res.Push(sum);
        }
        stack.Pop();
    }
    return sum;
}
