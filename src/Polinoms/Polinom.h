#ifndef POLINOM_H
#define POLINOM_H
//#include "TNode.h"
//#include "TMonom.h"
#include "TSList.h"
#include <iostream>

using namespace std;

class Polinom
{
public:
    TList<double,unsigned int>* pol;
public:
    Polinom();
    Polinom(const string&);
    Polinom(TList<double, unsigned int>*);
    Polinom(const Polinom&);
    ~Polinom();

	/*TList<double, unsigned int>**/void Simple();
	TList<double, unsigned int>* StandartView();
    bool operator==(const Polinom&) const;
    const Polinom& operator=(const Polinom&);

    Polinom operator+(const Polinom&);
	Polinom& operator+=(const Polinom&);
    Polinom operator-(const Polinom&);
	Polinom& operator-=(const Polinom&);
    Polinom operator*(const Polinom&);

	Polinom operator+(const TNode<double, unsigned int>&);
	Polinom operator-(const TNode<double, unsigned int>&);
	Polinom operator*(const TNode<double, unsigned int>&);
	Polinom& operator+=(const TNode<double, unsigned int>&);
	Polinom& operator-=(const TNode<double, unsigned int>&);
	Polinom& operator*=(const TNode<double, unsigned int>&);

    Polinom operator-();

	friend ostream& operator<<(ostream& out, Polinom& tmp)
	{
		out << *tmp.pol;
		return out;
	}
};



Polinom::Polinom()
{
	pol = new TList<double, unsigned int>();
}

Polinom::Polinom(const string& str)
{
	pol = new TList<double, unsigned int>();
	int _key = 0;
	double pc = 1;
	int dx = 0, dy = 0, dz = 0;
	bool flag = false;
	char c = '+';
	for (int i = 0; i <= str.length(); i++)
	{
		int j = 0;
		char coef[10];
		if (((str[i] == '+') || (str[i] == '-')) && (flag == false))
		{
			flag = true;
			c = str[i];
			i++;
		}
		if (((str[i] == '+') || (str[i] == '-') || (i == str.length())) && (flag == true))
		{
			_key = dx * 100 + dy * 10 + dz;
			if (c == '-')
				pol->InsertEnd(_key, -pc);
			if (c == '+')
				pol->InsertEnd(_key, pc);
			if (!(i == str.length()))
				c = str[i];
			pc = 1;
			dx = 0, dy = 0, dz = 0;
		}
		if (isdigit(str[i]))
		{
			flag = true;
			while ((isdigit(str[i + j])) || (str[i + j] == '.'))
			{
				coef[j] = str[i + j];
				j++;
			}
			i += j;
			pc = (float)(atof(coef));
			memset(coef, 0, sizeof(coef));
		}
		if (str[i] == 'x')
		{
			flag = true;
			if (str[i + 1] == '^')
			{
				dx = static_cast<int>(str[i + 2]) - '0';
				i += 2;
			}
			else
				dx = 1;
		}
		if (str[i] == 'y')
		{
			flag = true;
			if (str[i + 1] == '^')
			{
				dy = static_cast<int>(str[i + 2]) - '0';
				i += 2;
			}
			else
				dy = 1;
		}
		if (str[i] == 'z')
		{
			flag = true;
			if (str[i + 1] == '^')
			{
				dz = static_cast<int>(str[i + 2]) - '0';
				i += 2;
			}
			else
				dz = 1;
		}
	}
	//Simple();
	pol = StandartView();
}

Polinom::Polinom(TList<double, unsigned int>* tmp)
{
	pol = new TList<double, unsigned int>(*tmp);
	pol = StandartView();
}

Polinom::Polinom(const Polinom& tmp)
{
	pol = new TList<double, unsigned int>(*tmp.pol);
}

Polinom::~Polinom()
{
	delete pol;
}

///*TList<double, unsigned int>**/ void Polinom::Simple()
//{
//	TNode<double, unsigned int>* tmp, *node = new TNode<double, unsigned int>();
//	TList<double, unsigned int>* res = new TList<double, unsigned int>();
//	pol->Reset();
//	tmp = pol->pCur;
//	pol->Next();
//	while (!res->IsEnded())
//	{
//		while(!pol->IsEnded())
//		node = tmp;
//		
//
//	}
//}
void Polinom::Simple()/// приведение подобных слагаемых//////////////
{
	TNode<double, unsigned int>* tmp = new TNode<double, unsigned int>();
	pol->Reset();
	while (!pol->IsEnded())
	{
		tmp = pol->pCur;
		
		tmp = pol->pCur;
		while ((tmp->key != pol->pCur->key))
			tmp = tmp->pNext;
		if ((tmp == pol->pCur) && (tmp->pNext == pol->pNext))
		{
			pol->Next();
			continue;
		}
		pol->pCur->pData += tmp->pData;
		pol->Remove(tmp->key);
		pol->Next();
	}
}

TList<double, unsigned int>* Polinom::StandartView()//// ключи по порядку
{
	if ((pol->pFirst == nullptr) || (pol->pFirst->pNext == nullptr))
		return pol;
	TList<double, unsigned int>* res = new TList<double, unsigned int>();
	bool flag = false;
	pol->Reset();
	res->InsertEnd(pol->pCur->key, pol->pCur->pData);
	pol->Next();
	while (!pol->IsEnded())
	{
		res->Reset();

		while ((!res->IsEnded()) && (flag == false))
		{
			if (pol->pCur->key > res->pCur->key)
			{
				res->InsertBefore(res->pCur->key, pol->pCur->pData, pol->pCur->key);
				flag = true;
			}
			res->Next();
		}
		if (pol->pCur->key < res->pPrev->key)
			res->InsertAfter(res->pPrev->key, pol->pCur->pData, pol->pCur->key);
		pol->Next();
		flag = false;
	}
	return res;
}

bool Polinom::operator==(const Polinom& tmp) const
{
	if (*this->pol == *tmp.pol)
		return this;
}

const Polinom& Polinom::operator=(const Polinom& tmp)
{
	if (*this == tmp)
		return *this;

	pol = new TList<double, unsigned int>(*tmp.pol);
	return *this;
}

Polinom Polinom::operator+(const Polinom& p)////////////
{

	Polinom res;
	TNode<double, unsigned int>* tmp1 = pol->pFirst;
	TNode<double, unsigned int>* tmp2 = p.pol->pFirst;
	while ((tmp1 != nullptr) && (tmp2 != nullptr))
	{

		if (tmp1->key > tmp2->key)
		{
			res.pol->InsertEnd(tmp1->key, tmp1->pData);
			tmp1 = tmp1->pNext;
		}
		else if (tmp1->key < tmp2->key)
		{
			res.pol->InsertEnd(tmp2->key, tmp2->pData);
			tmp2 = tmp2->pNext;
		}
		else
		{
			if (tmp1->pData != -tmp2->pData)
			{
				res.pol->InsertEnd(tmp1->key, tmp1->pData + tmp2->pData);
			}
			tmp1 = tmp1->pNext;
			tmp2 = tmp2->pNext;
		}

		if (tmp1 == nullptr)
		{
			while (tmp2 != nullptr)
			{
				res.pol->InsertEnd(tmp2->key, tmp2->pData);
				tmp2 = tmp2->pNext;
			}

		}
		else if (tmp2 == nullptr)
		{
			while (tmp2 != nullptr)
			{
				res.pol->InsertEnd(tmp1->key, tmp1->pData);
				tmp1 = tmp1->pNext;
			}

		}
	}

	return res;
}

Polinom& Polinom::operator+=(const Polinom& tmp)
{
	Polinom p = *this;
	*this = p + tmp;
	return *this;
}

Polinom Polinom::operator-(const Polinom& tmp)////////////
{
	Polinom res(tmp);
	res = -res;
	return (*this + (res));
}

Polinom& Polinom::operator-=(const Polinom& tmp)
{
	Polinom p = *this;
	*this = p - tmp;
	return *this;
}
Polinom Polinom::operator*(const Polinom& p)/////////////////
{
	Polinom tmp1(p);
	Polinom tmp2(*this);
	tmp1.pol->Reset();
	tmp2.pol->Reset();
	Polinom res;
	while (!tmp1.pol->IsEnded())
	{
		tmp2 *= *tmp1.pol->pCur;
		res += tmp2;
		tmp1.pol->Next();
	}
	return res;
}

Polinom Polinom::operator+(const TNode<double, unsigned int>& node)
{
	
	if (node.pData == 0)
		return *this;
	pol->InsertAfter(pol->pFirst->key, node.pData, node.key);
	//pol = Simple();
	pol = StandartView();
	return *this;

	//Polinom res;

	//TNode<double, unsigned int>* tmp = pol->pFirst;
	//bool isInserted = false;
	//while ((tmp != nullptr) && (!isInserted))
	//{

	//	if (tmp->key > node.key)
	//	{
	//		res.pol->InsertEnd(tmp->key, tmp->pData);
	//		tmp = tmp->pNext;
	//	}
	//	else if (tmp->key < node.key)
	//	{
	//		res.pol->InsertEnd(node.key, node.pData);
	//		isInserted = true;
	//	}
	//}

	//if (tmp == nullptr)
	//{
	//	res.pol->InsertEnd(node.key, node.pData);
	//}

	//if (isInserted)
	//{
	//	while (tmp != nullptr)
	//	{
	//		res.pol->InsertEnd(tmp->key, tmp->pData);
	//		tmp = tmp->pNext;
	//	}
	//}

	//return res;
}


Polinom Polinom::operator-(const TNode<double, unsigned int>& node)
{
	Polinom res = *this + (-node);
	return res;
}

Polinom Polinom::operator*(const TNode<double, unsigned int>& node)
{
	if (node.pData == 0)
		return *this;
	Polinom res(*this);
	res.pol->Reset();
	while (!res.pol->IsEnded())
	{
		*res.pol->pCur *= node;
		res.pol->Next();
	}
	return res;
}

Polinom& Polinom::operator+=(const TNode<double, unsigned int>& node)
{
	Polinom tmp = (*this) + node;
	*this = tmp;
	return *this;
}

Polinom& Polinom::operator-=(const TNode<double, unsigned int>& node)
{
	Polinom tmp = (*this) - node;
	*this = tmp;
	return *this;
}

Polinom& Polinom::operator*=(const TNode<double, unsigned int>& node)
{
	Polinom tmp = (*this) * node;
	*this = tmp;
	return *this;
}

Polinom Polinom::operator-()////////////
{
	Polinom tmp(*this);

	while (!tmp.pol->IsEnded())
	{
		tmp.pol->pCur->pData *= (-1);
		tmp.pol->Next();
	};

	tmp.pol->Reset();
	return tmp;
}

#endif