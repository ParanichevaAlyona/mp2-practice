#ifndef TLIST_H
#define TLIST_H

template<typename TData,typename TKey>
class TNode
{
public:
	TData* pData;
	TKey key;
	TNode* pNext;

	TNode();
	TNode (TKey, TData*, TNode* _pNext = nullptr);
	TNode(const TNode&);
};

template<typename TData, typename TKey>
TNode<TData, TKey>::TNode() : pData(nullptr), key(0), pNext(nullptr) {}

template<typename TData,typename TKey>
TNode<TData, TKey>::TNode(TKey _key, TData* _pData, TNode* _pNext): key(_key), pData(_pData), pNext(_pNext){}

template<typename TData,typename TKey>
TNode<TData, TKey>::TNode(const TNode<TData, TKey>& node): key(node.key), pData(node->pData), pNext(node->pNext){}


////////////////////////////////////////////////

template<typename TData,typename TKey>
class TList
{
private:
	TNode<typename TData,typename TKey>* pFirst;
	TNode<typename TData,typename TKey>* pPrev;
	TNode<typename TData,typename TKey>* pCur;
	TNode<typename TData,typename TKey>* pNext;
public:
	TList();
	TList(const TNode<TData, TKey>*);
	TList(const TList&);
	~TList();

	bool IsEnded() const;
	void Next();
	void Reset();

	TNode<TData, TKey>* Search(TKey);
	void Back(TKey, TData*);
	void Push(TKey, TData*);
	void InsertAfter(TKey, TData*, TKey);
	void InsertBefore(TKey, TData*, TKey);
	void Remove(TKey);

	void Print();

	//friend ostream& operator << (ostream& out, const TList<TData, TKey>& list)
	//{
	//	list.Reset();
	//	while (!list.IsEnded())
	//	{
	//		out << list.pCur->key << "-" << *(list.pCur->pData) << endl;
	//		list.Next();
	//	}
	//	list.Reset();
	//	return out;
	//}
};

///////////////////////////////////////////////

template<typename TData,typename TKey>
TList<TData, TKey>::TList():pFirst(0), pPrev(0), pCur(0), pNext(0){}

template<typename TData,typename TKey>
TList<TData, TKey>::TList(const TNode<TData, TKey>* _node)
{
	TNode<TData, TKey> *node = _node;
	pFirst = new TNode<TData, TKey>(node->key, node->pData);
	pCur = pFirst;
	node = node->pNext;
	while (node != nullptr)
	{
		pCur->pNext = new TNode<TData, TKey>(node->key, node->pData);
		pCur = pCur->pNext;
		node = node->pNext;
	}	
	Reset();
}

template<typename TData,typename TKey>
TList<TData, TKey>::TList(const TList<TData, TKey>& list)
{
	TNode<TKey, TData> *node = list.pFirst;
	pFirst = new TNode<TData, TKey>(node->key, node->pData);
	pCur = pFirst;
	node = node->pNext;
	while (node != nullptr)
	{
		pCur->pNext = new TNode<TData, TKey>(node->key, node->pData);
		pCur = pCur->pNext;
		node = node->pNext;
	}
	Reset();
}

template<typename TData,typename TKey>
TList<TData, TKey>::~TList()
{
	Reset();
	while(pFirst != nullptr)
	{
		pNext = pFirst->pNext;
		delete (pFirst->pData);
		delete pFirst;
		pFirst = pNext;
	}
}

template<typename TData,typename TKey>
bool TList<TData, TKey>::IsEnded() const
{
	return(pCur == nullptr);
}

template<typename TData,typename TKey>
void TList<TData, TKey>::Reset()
{
	pPrev = nullptr;
	pCur = pFirst;
	if(pFirst != nullptr)
		pNext = pCur->pNext;
	else 
		pNext = nullptr;
}

template<typename TData,typename TKey>
void TList<TData, TKey>::Next()
{
	if (IsEnded())
		throw "You reached the end";
	pPrev = pCur;
	pCur = pNext;
	if(pCur != nullptr)
		pNext = pCur->pNext;
}

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey key)
{
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;
	while (!IsEnded())
	{
		if (pCur->key == key)
		{
			Reset();
			pPrev = fpPrev;
			pCur = fpCur;
			pNext = fpNext;
			return pCur;
		}
		Next();
	}
	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
	throw "The elem not found";
}

template<typename TData,typename TKey>
void TList<TData, TKey>::Back(TKey _key, TData* _pData) //v konec
{

	if (pFirst == nullptr)
	{
		pFirst = new TNode<TData, TKey>(_key, _pData);
		pCur = pFirst;
		return;
	}
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;
	Reset();
	while (!IsEnded())
		Next();
	pPrev->pNext = new TNode<TData, TKey>(_key, _pData);

	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
}

template<class TData, class TKey>
void TList<TData, TKey>::Push( TKey _key, TData* _pData)// v nachalo
{

	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;

	Reset();
	TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pFirst);
	pFirst = node;

	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey fkey, TData* _pData, TKey _key)
{
	
	if (pFirst == 0)
		throw "The list is empty";
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;

	if (pCur != pFirst)
		Reset();
	while (!IsEnded())
	{
		if(pCur->key == fkey)
		{
			TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pNext);
			pCur->pNext = node;

			pPrev = fpPrev;
			pCur = fpCur;
			pNext = fpNext;
			return;
		}
		Next();
	}
	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
	throw "The list doesn't contain an elem with this key";
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertBefore(TKey fkey, TData* _pData, TKey _key)
{
	if (pFirst == 0)
		throw "The list is empty";
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;

	Reset();
	if (pCur->key == fkey)
	{
		TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pCur);
		pFirst = node;

		pPrev = fpPrev;
		pCur = fpCur;
		pNext = fpNext;
		return;
	}
	while (pCur->pNext != nullptr)
	{
		if(pNext->key == fkey)
		{
			TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pNext);
			pCur->pNext = node;

			pPrev = fpPrev;
			pCur = fpCur;
			pNext = fpNext;
			return;
		}
		Next();
	}
	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
	throw "The list doesn't contain an elem with this key";
}

template<class TData, class TKey>
void TList<TData, TKey>::Remove(TKey fkey)
{
	if (pFirst == 0)
		throw "The list is empty";
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;

	if (pCur != pFirst)
		Reset();
	delete[] Search(fkey);

	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
}

template<class TData, class TKey>
void TList<TData, TKey>::Print()
{
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;

	if (pCur != pFirst)
		Reset();
	while (!IsEnded())
	{
		cout << pCur->key << '\n';
		cout << pCur->pData << '\n';
		Next();
	}
	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
}

#endif
