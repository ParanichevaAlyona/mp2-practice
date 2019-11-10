#ifndef TLIST_H
#define TLIST_H

template<typename TData,typename TKey>
class TNode
{
public:
	TData* pData;
	TKey key;
	TNode* pNext;

	TNode (TKey, TData*, TNode*);
	TNode(const TNode&);
};

template<typename TData,typename TKey>
TNode<typename TData,typename TKey>::TNode(TKey _key, TData* _pData, TNode* _pNext = 0)
{
	pData = _pData;
	key = _key;
	pNext = _pNext;
}

template<typename TData,typename TKey>
TNode<typename TData,typename TKey>::TNode(const TNode<TData, TKey>& node)
{
	pData = new TData;
	pData = node.pData;
	TKey = node.key;
	pNext = node->pNext;
}
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
	TList(TNode<TData, TKey>*);
	TList(const TList&);
	~TList();

	bool IsEnded() const;
	void Next();
	void Reset();

	TNode<TData, TKey>* Search(TKey);//
	void Back(TKey, TData*);//
	void Push(TKey, TData*);//
	void InsertAfter(TKey, TData*, TKey);//
	void InsertBefore(TKey, TData*, TKey);//
	void Remove(TKey);
	void Print() const;

};

///////////////////////////////////////////

template<typename TData,typename TKey>
TList<TData, TKey>::TList():pFirst(0), pPrev(0), pCur(0), pNext(0){}

template<typename TData,typename TKey>
TList<TData, TKey>::TList(const TList& list)
{
	pFirst = new TNode<TData, TKey>(list.pFirst);
	pCur = pFirst;
	pPrev = 0;
	list.Reset();
	list.Next();
	while (!list.IsEnded())
	{
		pCur = new TNode<TData, TKey>(list.pCur);
		pCur = pNext;
		list.Next();
	}
	this->Reset();
}

template<typename TData,typename TKey>
TList<TData, TKey>::TList(TNode<TData, TKey>* node)
{
	pFirst = node;
	pCur = pFirst;
	pPrev = 0;
	pNext = pFirst->pNext;
}

template<typename TData,typename TKey>
TList<TData, TKey>::~TList()
{
	Reset();
	while(!IsEnded())
		Remove(pFirst->key);
}

template<typename TData,typename TKey>
bool TList<TData, TKey>::IsEnded() const
{
	return(pCur == 0);
}

template<typename TData,typename TKey>
void TList<TData, TKey>::Reset()
{
	pPrev = 0;
	pCur = pFirst;
	if(pFirst != 0)
		pNext = pCur->pNext;
	else 
		pNext = 0;
}

template<typename TData,typename TKey>
void TList<TData, TKey>::Next()
{
	if (IsEnded())
		throw "You reached the end";
	pPrev = pCur;
	pCur = pNext;
	if(pCur != 0)
		pNext = pCur->pNext;
}

template<typename TData,typename TKey>
void TList<TData, TKey>::Back(TKey key, TData* _pData)
{
	if (pFirst == 0)
		throw "The list is empty";
	TNode<TData, TKey>* fpFirst = pFirst;
	TNode<TData, TKey>* fpPrev = pPrev;
	TNode<TData, TKey>* fpCur = pCur;
	TNode<TData, TKey>* fpNext = pNext;
	Reset();
	while (!IsEnded())
		Next();
	pPrev->pNext = new TNode<TData, TKey>(key, _pData, 0);
	pPrev = fpPrev;
	pCur = fpCur;
	pNext = fpNext;
}

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey key)
{
	while (!IsEnded())
	{
		if (pCur->key == key)
		{
			Reset();
			return pCur;
		}
		Next();
	}
	Reset();
	throw "The elem not found";
}

template<class TData, class TKey>
void TList<TData, TKey>::Push( TKey _key, TData* _pData)
{
	Reset();
	TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, 0);
	pNext = pFirst;
	pFirst = node;
	pCur = pFirst;
	Reset();
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey fkey, TData* _pData, TKey _key)
{
	if (pFirst == 0)
		throw "The list is empty";
	Reset();
	while (!IsEnded())
	{
		if(pCur->key == fkey)
		{
			TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, 0);
			node->pNext = pNext;
			node->key = _key;
			node->pData = _pData;
			pCur->pNext = node;
			break;
		}
		Next();
	}
	throw "The list doesn't contain an elem with this key";
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertBefore(TKey fkey, TData* _pData, TKey _key)
{
	if (pFirst == 0)
		throw "The list is empty";
	Reset();
	while (!IsEnded())
	{
		if(pNext->key == fkey)
		{
			TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, 0);
			node->pNext = pNext;
			node->key = _key;
			node->pData = _pData;
			pCur->pNext = node;
			break;
		}
		Next();
	}
	throw "The list doesn't contain an elem with this key";
}

template<class TData, class TKey>
void TList<TData, TKey>::Remove(TKey fkey)
{
	if (pFirst == 0)
		throw "The list is empty";
	Reset();
	delete[] Search(fkey);
}

template<class TData, class TKey>
void TList<TData, TKey>::Print() const
{
	if (pFirst == 0)
		throw "The list is empty";
	Reset();
	int* i = 1;
	while (!IsEnded())
	{
		cout << i << '. ' << pCur->pData << " " << pCur->key;
		i++;
		Next();
	}
}

#endif