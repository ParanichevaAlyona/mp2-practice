#include <iostream>
#include "TList.h"

using namespace std;

void main()
{
	char* p = "privet";
	char* k = "kak";
	char* d = "dela";
	char* m = "Masha";

	TNode<char, int>  a(1, p, 0);
	TNode<char, int>  b(2, k, 0);
	TNode<char, int>  c(3, d, 0);
	TNode<char, int>  e(4, m, 0);
	TList<char, int> list;

	list.Push(a.key, a.pData);
	list.Back(b.key, b.pData);
	list.InsertAfter(b.key, c.pData, c.key);
	list.InsertBefore(a.key, e.pData, e.key);
	list.Remove(4);
}