#ifndef TMATRIX_H
#define TMATRIX_H

#include "TVector.h"

template <typename ValueType>
class TMatrix: public TVector<TVector <ValueType> >
{
public:
	explicit TMatrix(int);
	TMatrix(const TMatrix&);
	TMatrix(const TVector<TVector<ValueType> >&);
	~TMatrix();

	TMatrix operator = (const TMatrix&); 
	TMatrix operator + (const ValueType);
	TMatrix operator - (const ValueType);
	TMatrix operator * (const ValueType);
	TMatrix operator + (const TMatrix&);
	TMatrix operator - (const TMatrix&);
	TMatrix operator * (const TMatrix&);
	TVector<ValueType> operator * (const TVector<ValueType>&);

	bool operator == (const TMatrix&) const;
	bool operator != (const TMatrix&) const;

	friend istream& operator >> (istream& input, TMatrix& m)
	{
		for (int i = 0; i < m.size; i++)
			input >> m.x[i];
		return input;
	}

	friend ostream& operator << (ostream& output, const TMatrix& m)
	{
		for (int i = 0; i < m.size; i++)
		{
			output << m.x[i] << '\n';
		}
		return output;
	}

};

////////////////////////////////////////////////////////////////////
template <typename ValueType>
TMatrix<ValueType>::TMatrix(int _size):TVector<TVector<ValueType> >(_size)
{
	size = _size;
	for(int i = 0; i < size; i++)
		this->x[i] = TVector<ValueType>(size - i, i);
}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix<ValueType>& m):TVector<TVector<ValueType> >(m)
{}

template <typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> >& v):TVector<TVector<ValueType> >(v)
{}

template<typename T>
TMatrix<T>::~TMatrix()
{}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator = (const TMatrix& m)
{
	if (*this == m)
	{
		return *this; 
	}
	delete[] this->x;
	this->size = m.size;
	this->x = new TVector<ValueType>[m.size];
	for(int i = 0; i < size; i++)
	{
		this->x[i] = m.x[i];
	}
	return *this;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator + (const ValueType a)
{
	TMatrix res(*this);
	for(int i = 0; i < res.size; i++)
		res.x[i] = x[i] + a;
	return res;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator - (const ValueType a)
{
	TMatrix res(*this);
	for(int i = 0; i < res.size; i++)
		res.x[i] = x[i] - a;;
	return res;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator * (const ValueType a)
{
	TMatrix res(*this);
	for(int i = 0; i < size; i++)
		res.x[i] = x[i] * a;
	return res;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator + (const TMatrix<ValueType>& m)
{
	if (this->size != m.size)
		throw "Different size";
	TMatrix<ValueType> res(*this);
	for(int i = 0; i < res.size; i++)
		res.x[i] = this->x[i] + m.x[i];
	return res;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator - (const TMatrix<ValueType>& m)
{
	if (this->size != m.size)
		throw "Different size";
	TMatrix<ValueType> res(*this);
	for(int i = 0; i < size; i++)
		res.x[i] = this->x[i] - m.x[i];
	return res;
}

template <typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator * (const TMatrix<ValueType>& m)
{
	if (this->size != m.size)
		throw "Different size";
    TMatrix<ValueType> res(size);
    for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size - i; j++) 
		{
			res.x[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				res.x[i][j] = res.x[i][j] + this->x[i][k] * m.x[k + i][j - k];
			}
        }
    return res;
}

template <typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator * (const TVector<ValueType>& v)
{
	if (this->size != v.size)
		throw "Different size";
	TVector<ValueType> res(this->size);
	res = res * 0;
    for (int i = 0; i < this->size; i++) 
		{
        res[i] = 0;
        for (int j = 0; j < size - i; j++)
            res[i] += this->x[i][j] * v[i + j];
		}
	return res;
}
