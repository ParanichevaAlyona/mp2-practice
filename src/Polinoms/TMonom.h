#ifndef TMONOM_H
#define TMONOM_H
#include "TNode.h"
#include <iostream>

using namespace std;

template<>
class TNode<double, unsigned int>
{
public:
    double pData;
    unsigned int key;
    TNode* pNext;

    TNode();
    TNode(unsigned int, double, TNode* _pNext = nullptr);
    TNode(const TNode&);

    TNode& operator=(const TNode&);
    TNode operator+(const TNode&);
    TNode operator-(const TNode&);
    TNode operator*(const TNode&);
    TNode& operator+=(const TNode<double, unsigned int>&);
    TNode& operator-=(const TNode<double, unsigned int>&);
    TNode& operator*=(const TNode<double, unsigned int>&);
    TNode& operator*=(double);
    TNode operator*(double);
    TNode operator-() const;

    bool operator==(const TNode&) const;
    bool operator!=(const TNode&) const;
    
    friend ostream& operator<<(ostream& out, TNode& node)
    {
        if (node.pData > 0)
            out << " +";
        else
            out << " ";
        out << node.pData;
        if (node.key / 100 != 0)
            out << "x^" << node.key / 100;
        if ((node.key / 10) % 10 != 0)
            out << "y^" << (node.key / 10) % 10;
        if (node.key % 10 != 0)
            out << "z^" << node.key % 10;
        return out;
    }
};

TNode<double, unsigned int>::TNode() : pData(0), key(0), pNext(nullptr) {}

TNode<double, unsigned int>::TNode(unsigned int _key, double _pData, TNode* _pNext) : key(_key), pData(_pData), pNext(_pNext) {}

TNode<double, unsigned int>::TNode(const TNode<double, unsigned int>& node) : key(node.key), pData(node.pData), pNext(node.pNext) {}

TNode<double, unsigned int>& TNode<double, unsigned int>::operator=(const TNode& mon)
{
    if (this == &mon)
        return *this;
    key = mon.key;
    pData = mon.pData;
    pNext = nullptr;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator+(const TNode<double, unsigned int>& mon)
{
    if (key != mon.key)
        throw -3;/// Monoms have diffrent degrees;
    TNode<double, unsigned int> res(mon);
    res.pData += pData;
    return res;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator-(const TNode<double, unsigned int>& mon)
{
    if (key != mon.key)
        throw -3;/// Monoms have diffrent degrees;
    TNode<double, unsigned int> res(mon);
    res.pData -= pData;
    return res;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator*(const TNode<double, unsigned int>& mon)
{
    if (((mon.key / 100) + (key / 100) > 9) || (((mon.key / 10) % 10) + ((key / 10) % 10) > 9) || ((mon.key % 10) + (key % 10) > 9))
        throw -4;/// Limit is exceeded
    TNode<double, unsigned int> res;
    res.pData = pData * mon.pData;
    res.key = key + mon.key;
    return res;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator*(double a)
{
    TNode<double, unsigned int> res(*this);
    res.pData *= a;
    return res;
}

TNode<double, unsigned int>& TNode<double, unsigned int>::operator+=(const TNode<double, unsigned int>& tmp)
{
    if (key != tmp.key)
        throw "!diff conv";
    pData += tmp.pData;
    return *this;
}
TNode<double, unsigned int>& TNode<double, unsigned int>::operator-=(const TNode<double, unsigned int>& tmp)
{
    if (key != tmp.key)
        throw "!diff conv";
    pData -= tmp.pData;
    return *this;
}
TNode<double, unsigned int>& TNode<double, unsigned int>::operator*=(const TNode<double, unsigned int>& tmp)
{
    if (((tmp.key / 100 + key / 100) > 9) || ((tmp.key / 10 + key / 10) > 90)
        || ((tmp.key % 10 + key % 10) > 9))
        throw -4;//////////limit is exceeded
    key += tmp.key;
    pData *= tmp.pData;
    return *this;
}
TNode<double, unsigned int>& TNode<double, unsigned int>::operator*=(double c)
{
    pData *= c;
    return *this;
}

bool TNode<double, unsigned int>::operator==(const TNode<double, unsigned int>& mon) const
{
    if ((key == mon.key) && (pData == mon.pData))
        return true;
    return false;
}

bool TNode<double, unsigned int>::operator!=(const TNode<double, unsigned int>& mon) const
{
    return (!(*this == mon));
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator-() const
{
    TNode<double, unsigned int> res(key, -pData);
    return res;
}
#endif