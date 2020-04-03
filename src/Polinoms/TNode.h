#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template<typename TData, typename TKey>
class TNode
{
public:
	TData* pData;
	TKey key;
	TNode* pNext;

	TNode();
	TNode(TKey, TData*, TNode* _pNext = nullptr);
	TNode(const TNode&);
	friend std::ostream& operator << (std::ostream& out, TNode<TData, TKey>& node)
	{
		out << node.key << " - " << node.pData;
		return out;
	}
};


template<typename TData, typename TKey>
TNode<TData, TKey>::TNode() : pData(nullptr), key(0), pNext(nullptr) {}

template<typename TData, typename TKey>
TNode<TData, TKey>::TNode(TKey _key, TData* _pData, TNode* _pNext) : key(_key), pData(_pData), pNext(_pNext) {}

template<typename TData, typename TKey>
TNode<TData, TKey>::TNode(const TNode<TData, TKey>& node) : key(node.key), pData(node->pData), pNext(node->pNext) {}

#endif