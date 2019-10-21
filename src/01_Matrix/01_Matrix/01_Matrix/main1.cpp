#include <iostream>
#include <iomanip>
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

void main()
{
	TVector<double> a(3, 0), b(3, 0), is(4, 0);
	TMatrix<double> c(3), d(3), iscl(4);
	////////////////////////////////// fill M, M, M
	cout << "Enter the elements of matrix 'c', size 3*3" << '\n';
	cin >> c;
	cout << "c" << '\n' << c << '\n';

	cout << "Enter the elements of matrix 'd', size 3*3" << '\n';
	cin >> d;
	cout << "d" << '\n' << d << '\n';

	cout << "Enter the elements of matrix 'iscl', size 4*4" << '\n';
	cin >> iscl;
	cout << "iscl" << '\n' << iscl << '\n';
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

	try
	{
		cout << "c + iscl = " << '\n';
		TMatrix<double> res = c + iscl;
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

	try
	{
		cout << "c - iscl = " << '\n';
		TMatrix<double> res = c - iscl;
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
		try
	{
		cout << "c * iscl = " << '\n';
		TMatrix<double> res = c * iscl;
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

	if (c == d)
		cout << "c = d" << '\n';
	if (c != d) 
		cout << "c != d" << '\n';
	//////////////////////////////////////// M(M)
	TMatrix<double> h(c);
	cout << "M(c)" << '\n' << h << '\n';

	//////////////////////////////////////// fill v
	cout << "Enter elements of vector 'a', size 3" << '\n'; 
	cin >> a;
	cout << "a" << a << '\n';
	
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

	try
	{
		cout << "c * is = ";
		TVector<double> res = c * is;
		cout << res << '\n';
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	//////////////////////////////////////// fill v, v
	cout << "Enter elements of vector 'b', size 3" << '\n'; 
	cin >> b;
	cout << "b" << b << '\n';
	cout << "Enter elements of vector 'is', size 4" << '\n'; 
	cin >> is;
	cout << "is" << is << '\n';
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

	try
	{
		cout << "a + is = ";
		TVector<double> res = a + is;
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

	try
	{
		cout << "a - is = ";
		TVector<double> res = a - is;
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

	try
	{
		cout << "a * is = ";
		size_t res = a * is;
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
	ress = a;
	cout << "ress = v " << ress << '\n';
	/////////////////////////////////////////v(v)
	TVector<double> v(a);
	cout << "v(a) " << '\n' << ress << '\n';
}
