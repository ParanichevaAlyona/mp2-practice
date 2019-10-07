#include <iostream>
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

void main()
{
	TVector<int> a(3, 0), b(3, 0);
	TMatrix<int> c(3), d(3);
	////////////////////////////////// fill M, M
	try
	{
		cout << "Enter the elements of matrix 'c'" << '\n';
		cin >> c;
		cout << "c" << c << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	try
	{
		cout << "Enter the elements of matrix 'd'" << '\n';
		cin >> d;
		cout << "d" << d << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	/////////////////////////////////////////// M + M
	try
	{
		cout << "c + d = " << '\n';
		TMatrix<int> res = c + d;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	///////////////////////////////////////// M - M
	try
	{
		cout << "c - d = " << '\n';
		TMatrix<int> res = c - d;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	///////////////////////////////////////// M * M
	try
	{
		cout << "c * d = " << '\n';
		TMatrix<int> res = c * d;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// M + a
	TMatrix<int> res = c + 2;
	cout << "c + 2 = " << '\n' << res << '\n';
	//////////////////////////////////////// M - a
	res = c - 2;
	cout << "c - 2 = " << '\n' << res << '\n';
	//////////////////////////////////////// M * a
	res = c * 2;
	cout << "c * 2 = " << '\n' << res << '\n';
	//////////////////////////////////////// M == M
	try
	{
		if (c == d)
			cout << "c = d" << '\n';
		if (c != d) 
			cout << "c != d" << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// fill v, v
	try
	{
		cout << "Enter elements of vector 'a'" << '\n'; 
		cin >> a;
		cout << "a" << a << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	try
	{
		cout << "Enter elements of vector 'b'" << '\n'; 
		cin >> b;
		cout << "b" << b << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// M * v
	try
	{
		cout << "c * a = ";
		TVector<int> res = c * a;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// length of v
	size_t S;
	S = a.Len();
	cout << "Vector length =" << S <<'\n';
	//////////////////////////////////////// v + v
	try
	{
		cout << "a + b = ";
		TVector<int> res = a + b;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	///////////////////////////////////////// v - v
	try
	{
		cout << "a - b = ";
		TVector<int> res = a - b;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	///////////////////////////////////////// v * v
	try
	{
		cout << "a * b = ";
		size_t res = a * b;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// v + a
	TVector<int> ress = a + 2;
	cout << "a + 2 = " << ress << '\n';
	//////////////////////////////////////// v - a
	ress = a - 2;
	cout << "a - 2 = " << ress << '\n';
	//////////////////////////////////////// v * a
	ress = a * 2;
	cout << "a * 2 = " << ress << '\n';
}