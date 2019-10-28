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
                    post.Push(stack.Pop());
            stack.Push(s[i]);
        }
        if (s[i] == ')')
        {
            while (stack.Getlast() != '(')
                post.Push(stack.Pop());
            stack.Pop();
        }
    }
    while (!stack.IsEmpty())
        post.Push(stack.Pop());
    int max = post.Top();
    char tmp[20];
    for (int i = 0; i < max; i++)
    {
        tmp[i] = post.Pop();
        i++;
    }
    cout << "Postfix form is: " << tmp << '\n';

    std::string str(tmp);
    return str;
}

double Calculator::Calculate(string ss)
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
            sum = res.Pop() * res.Pop();
            res.Push(sum);
        }
        if (stack.Getlast() == '+')
        {
            sum = res.Pop() + res.Pop();
            res.Push(sum);
        }
        if (stack.Getlast() == '-')
        {
            b = res.Pop();
            a = res.Pop();
            sum = a - b;
            res.Push(sum);
        }
        if (stack.Getlast() == '/')
        {
            b = res.Pop();
            a = res.Pop();
            sum = a / b;
            res.Push(sum);
        }
        stack.Pop();
    }
    return sum;
}
