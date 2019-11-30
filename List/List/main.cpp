#include <iostream>
#include "TList.h"

using namespace std;

void main()
{
	char* p = "privet";
	char* k = "kak";
	char* d = "dela";
	char* m = "Masha";

	TNode<char, int>  privet(1, p, 0);
	TNode<char, int>  kak(2, k, 0);
	TNode<char, int>  dela(3, d, 0);
	TNode<char, int>  Masha(4, m, 0);

	TList<char, int> list;
	//Back
	list.Back(kak.key, kak.pData);
	//Push
	list.Push(privet.key, privet.pData);
	//InsertAfter
	try
	{
		list.InsertAfter(kak.key, dela.pData, dela.key);
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	
	//InsertBefore
	try
	{
		list.InsertBefore(privet.key, Masha.pData, Masha.key);
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	list.Print();
	try/////catch the exception
	{
		list.InsertBefore(10, Masha.pData, Masha.key);
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	try/////catch the exception
	{
		list.InsertAfter(10, dela.pData, dela.key);
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
}
