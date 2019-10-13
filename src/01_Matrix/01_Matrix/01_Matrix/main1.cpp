#include <iostream>
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

void main()
{
	TVector<double> a(3, 0), b(3, 0);
	TMatrix<double> c(3), d(3);
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
		TMatrix<double> res = c + d;
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
		TMatrix<double> res = c - d;
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
		TMatrix<double> res = c * d;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// M + a
	TMatrix<double> res = c + 2;
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
		TVector<double> res = c * a;
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
		TVector<double> res = a + b;
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
		TVector<double> res = a - b;
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
	TVector<double> ress = a + 2;
	cout << "a + 2 = " << ress << '\n';
	//////////////////////////////////////// v - a
	ress = a - 2;
	cout << "a - 2 = " << ress << '\n';
	//////////////////////////////////////// v * a
	ress = a * 2;
	cout << "a * 2 = " << ress << '\n';
	//////////////////////////////////////// v == v
	if (a == b)
		cout << "a == b" << '\n';
	else cout << "a != b" << '\n';
}
