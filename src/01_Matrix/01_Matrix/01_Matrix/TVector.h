#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include <iomanip>

using namespace std;

template<typename ValueType>
class TMatrix;

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
	
	friend istream& operator >> (istream& input, TVector& z)
	{
		for (int i = 0; i < z.size; i++)
            input >> z.x[i];
        return input;
	}

	friend ostream& operator << (ostream& output, const TVector& z)
	{
		for (int j = 0; j < z.StartIndex; j++)
			output << setw(5) << setprecision(2) << right << " ";
        for (int i = 0; i < z.size - 1; i++)
        {
            output << setw(5) << setprecision(2) << right << z[i];               
        }
        output << setw(5) << setprecision(2) << right << z[z.size - 1];
        return output;
		output << setw(z.StartIndex);
	}

	friend TMatrix<ValueType>;
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
    if (size != z.size)
    {
        delete[] x;
	    size = z.size;
	    x = new ValueType[z.size];
    }
    StartIndex = z.StartIndex;
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
	if((z.size != size) || (z.StartIndex != StartIndex))
		throw "Different size or startindex";
	TVector<ValueType> res(z);
	for (int i = 0; i < size; i++)
		res.x[i] = res.x[i] + x[i];
	return res;
}

template <typename ValueType>
TVector<ValueType> TVector<ValueType>::operator - (const TVector<ValueType>& z)
{
    if ((z.size != size) || (z.StartIndex != StartIndex))
		throw "Different size or startindex";
	TVector<ValueType> res(z);
	for (int i = 0; i < size; i++)
		res.x[i] = res.x[i] - x[i]; 
	return res;
}

template <typename ValueType>
ValueType TVector<ValueType>::operator * (const TVector<ValueType>& z)
{
    if ((z.size != size) || (z.StartIndex != StartIndex))
		throw "Different size or startindex";
	ValueType S = 0;
	for(int i = 0; i < size; i++)
		S += x[i] * z.x[i];
	return S;
}

template <typename ValueType>
bool TVector<ValueType>::operator == (const TVector<ValueType>& z) const
{
	if (size != z.size) return false;
	bool f = true;
	for (int i = 0; i < size; i++)
	{
		if (x[i] != z.x[i]) f = false;
	}
	return f;
}

template <typename ValueType>
bool TVector<ValueType>::operator != (const TVector<ValueType>& z) const
{
	return (!(*this == z));
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

#endif
