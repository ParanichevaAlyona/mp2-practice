#include <iostream>
#include "TList.h"

using namespace std;

void finsertend()
{
	cout << "InsertEnd function:" << endl;
	char* o = "one";
	char* t = "two";
	char* th = "three";
	char* f = "four";

	TList<char, int> list;
	list.InsertEnd(1, o);
	list.InsertEnd(2, t);
	list.InsertEnd(3, th);
	list.InsertEnd(4, f);
	cout << list << endl;
}

void finserfirst()
{
	cout << "InsertFirst function:" << endl;
	char* o = "one";
	char* t = "two";
	char* th = "three";
	char* f = "four";

	TList<char, int> list;
	list.InsertFirst(1, o);
	list.InsertFirst(2, t);
	list.InsertFirst(3, th);
	list.InsertFirst(4, f);
	cout << list << endl;
}

void finsafter()
{
	cout << "InsertAfter function:" << endl;
	char* o = "one";
	char* t = "two";
	char* th = "three";
	char* f = "four";

	TList<char, int> list;
	
	try
	{
		list.InsertFirst(1, o);
		list.InsertAfter(1, t, 2);
		list.InsertAfter(2, th, 3);
		list.InsertAfter(3, f, 4);
	}
	catch(int k)
	{
		if (k == -1)
			cout << "You reached the end" << endl;
		if (k == -2)
			cout << "The list is empty" << endl;
		else
			cout << "The list doesn't contain an elem with this key - " << k << endl;
	}
	cout << list << endl;
	try
	{
		list.InsertAfter(5, t, 2);

	}
	catch(int k)
	{
		if (k == -1)
			cout << "You reached the end" << endl;
		if (k == -2)
			cout << "The list is empty" << endl;
		else
			cout << "The list doesn't contain an elem with this key - " << k << endl;
	}
}
void finsbefore()
{
	cout << "InsertBefore function:" << endl;
	char* o = "one";
	char* t = "two";
	char* th = "three";
	char* f = "four";

	TList<char, int> list;
	
	
	try
	{
		list.InsertFirst(1, o);
		list.InsertBefore(1, t, 2);
		list.InsertBefore(2, th, 3);
		list.InsertBefore(3, f, 4);
	}
	catch(int k)
	{
		if (k == -1)
			cout << "You reached the end" << endl;
		if (k == -2)
			cout << "The list is empty" << endl;
		else
			cout << "The list doesn't contain an elem with this key - " << k << endl;
	}
	cout << list << endl;
	try
	{
		list.InsertBefore(5, t, 2);

	}
	catch(int k)
	{
		if (k == -1)
			cout << "You reached the end" << endl;
		if (k == -2)
			cout << "The list is empty" << endl;
		else
			cout << "The list doesn't contain an elem with this key - " << k << endl;
	}
}
void fremove()
{
	cout << "the list before remove:" << endl;
	char* o = "one";
	char* t = "two";
	char* th = "three";
	char* f = "four";

	TList<char, int> list;
	list.InsertEnd(1, o);
	list.InsertEnd(2, t);
	list.InsertEnd(3, th);
	list.InsertEnd(4, f);
	cout << list << endl;
	try
	{
		list.Remove(1); 
		list.Remove(3);
		list.Remove(4);
		list.Remove(5);
	}
	catch(int k)
	{
		if (k == -1)
			cout << "You reached the end" << endl;
		if (k == -2)
			cout << "The list is empty" << endl;
		else
			cout << "The list doesn't contain an elem with this key - " << k << endl;
	}	
	cout << "the list after remove:" << endl;
	cout << list << endl; 
}

void main()
{
	finsertend();
	finserfirst();
	finsafter();
	finsbefore();
	fremove();
}
