#include <iostream>////-2 empty -3 Monoms have diffrent degrees; -4 degree exceeded
//#include "TNode.h"
//#include "TMonom.h"
//#include "TSList.h"
#include "Polinom.h"

using namespace std;


void main()
{
    TList<double, unsigned int>* l1 = new TList<double, unsigned int>();
    l1->InsertEnd(100, 25);
    //l1->InsertEnd(4, -50);
    //l1->InsertEnd(126, 1.5);

    TNode<double, unsigned int>* node = new TNode<double, unsigned int>(105, 5);
    Polinom p1(l1);
    Polinom p2("x^2 + 2x^4y^4 + 55z^4");
    cout << p1 << endl;
    cout << p2 << endl;


    cout << "Tests" << endl;

    cout << "1)  pol + pol" << endl;
    Polinom res = p1 + p2;
    cout << res << endl;

    //cout << "2)  pol - pol" << endl;
    //res = p1 - p2;
    //cout << res << endl;

    cout << "3)  pol * pol" << endl;
    res = p1 * p2;
    cout << res << endl;
    //
    //cout << "4)  pol += pol" << endl;
    //p1 += p2;
    //cout << p1 << endl;

    //cout << "5)  pol -= pol" << endl;
    //p1 -= p2;
    //cout << p1 << endl;

    //cout << "6)  pol + node"<< endl;
    //res = p2 + *node;
    //cout << res << endl;

    //cout << "7)  pol - node"<< endl;
    //res = p2 - *node;
    //cout << res << endl;

    cout << "8)  pol * node"<< endl;
    res = p2 * *node;
    cout << res << endl;

    //cout << "9)  pol += node"<< endl;
    //p1 += *node;
    //cout << res << endl;

    //cout << "10)  pol -= node"<< endl;
    //p1 -= *node;
    //cout << p1 << endl;

    //cout << "11)  pol *= node"<< endl;
    //p2 *= *node;
    //cout << p2 << endl;

    //cout << "12)  pol = -pol"<< endl;


    
    
}