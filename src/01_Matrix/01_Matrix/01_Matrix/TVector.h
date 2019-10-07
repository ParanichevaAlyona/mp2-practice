#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
using namespace std;

template <typename ValueType>
class TVector
{
protected:
	int size;
	ValueType* x;
	int StartIndex;
public:
	explicit TVector(int size = 10, int startIndex = 0);
	TVector(const TVector&);
	~TVector();

	ValueType Len() const;
	TVector& operator = (const TVector&);
	TVector operator + (const ValueType);
	TVector operator - (const ValueType);
	TVector operator * (const ValueType);
	TVector operator + (const TVector&);
	TVector operator - (const TVector&);
	ValueType operator * (const TVector&);

	bool operator == (const TVector&) const;
	bool operator != (const TVector&) const;

	const ValueType& operator[] (int ind) const;
	ValueType& operator[] (int ind);

	ValueType Size() const;

	friend istream& operator >> (istream& input, TVector& z)
	{
		for (int i = 0; i < z.size; i++)
        input >> z.x[i];

    return input;
	}

	friend ostream& operator << (ostream& output, const TVector& z)
	{
		if (z.size == 0)
    {
        output << "Empty";
        return output;
    }
    output << "(";
    for (int i = 0; i < z.size; i++)
    {
        if (i != z.size - 1)
            output << z[i] << ", ";
        else
            output << z[i] << ")";
    }
    return output;
	}
};

//////////////////////////////////////////////////////////////
template <typename ValueType>
TVector<ValueType>::TVector(int _size, int _StartIndex)
{
	size = _size;
	StartIndex = _StartIndex;
	x = new ValueType[size];
}

template <typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType>& z)
{
	size = z.size;
	x = new ValueType[size];
	StartIndex = z.StartIndex;
	for (int i = 0; i < size; i++) 
         x[i] = z.x[i];
}

template <typename ValueType>
TVector<ValueType>::~TVector()
{
	delete[]x;
	size = 0;
	StartIndex = 0;
}

template <typename ValueType>
ValueType TVector<ValueType>::Len() const
{
	ValueType S = 0, res;
	for (int i = 0; i < size; i++)
		S += x[i] * x[i];
	res = sqrt(S);
	return res;
}

template <typename ValueType>
TVector<ValueType>& TVector<ValueType>::operator = (const TVector<ValueType>& z)
{
	if (*this == z)
	{
		return *this; 
	}
	delete[] x;
	size = z.size;
	x = new ValueType[z.size];
	for(int i = 0; i < z.size; i++)
		x[i] = z.x[i];
	return *this;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator + (const ValueType a)
{
	TVector<ValueType> res(*this);
	for (int i = 0; i < size; i++)
		res.x[i] += a;
	return res;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator - (const ValueType a)
{
	TVector<ValueType> res(*this);
	for (int i = 0; i < size; i++)
		res.x[i] -= a;
	return res;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator * (const ValueType a)
{
	TVector<ValueType> res(*this);
	for (int i = 0; i < size; i++)
		res.x[i] *= a;
	return res;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator + (const TVector<ValueType>& z)
{
	if(z.size != size)
		throw "Different size";
	TVector<ValueType> res(z);
	for (int i = 0; i < size; i++)
		res.x[i] += x[i];
	return res;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator - (const TVector<ValueType>& z)
{
	if(z.size != size)
		throw "Different size";
	TVector<ValueType> res(z);
	for (int i = 0; i < size; i++)
		res.x[i] -= x[i];
	return res;
}

template <typename ValueType>
ValueType TVector<ValueType>::operator * (const TVector<ValueType>& z)
{
	if(z.size != size)
		throw "Different size";
	ValueType S = 0;
	for(int i = 0; i < size; i++)
		S += x[i] * z.x[i];
	return S;
}

template <typename ValueType>
bool TVector<ValueType>::operator == (const TVector<ValueType>& z) const
{
	if (size != z.size) return false;
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (x[i] != z.x[i]) f = 1;
	}
	if (f == 1) return false;
	return true;
}

template <typename ValueType>
bool TVector<ValueType>::operator != (const TVector<ValueType>& z) const
{
	if (size != z.size) return true;
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (x[i] != z.x[i]) f = 1;
	}
	if (f == 1) return true;
	return false;
}

template <typename ValueType>
const ValueType& TVector<ValueType>::operator[] (int ind) const
{
	if ((ind < 0) || (ind >= size))
		throw "Wrong index";
	return x[ind];
}

template <typename ValueType>
ValueType& TVector<ValueType>::operator[] (int ind)
{
	if ((ind < 0) || (ind >= size))
		throw "Wrong index";
	return x[ind];
}

template<typename ValueType>
ValueType TVector<ValueType>::Size() const 
{
    return size;
}
#endif