#ifndef TSTACK_H
#define TSTACK_H

template<typename ValueType>
class TStack {
public:
	int maxsize;
	ValueType* x;
	int top;
public:
	TStack(int);
	TStack(const TStack&);
	~TStack();

	void Push(ValueType);
	ValueType Pop();
	bool IsEmpty()const;
	bool IsFull()const;
	int Top()const;
	ValueType Getlast()const;
};
/////////////////////////////////////////
template<typename ValueType>
TStack<ValueType>::TStack(int _maxsize) 
{
	if (_maxsize <= 0) 
		throw "Incorrect max size";
	maxsize = _maxsize;
	x = new ValueType[maxsize];
	top = 0;
	for (int i = 0; i < maxsize; i++)
		x[i] = 0;
}

template<typename ValueType>
TStack<ValueType>::TStack(const TStack& s) 
{
	maxsize = s.maxsize;
	top = s.top;
	for (int i; i < maxsize; i++)
		x[i] = s.x[i];
}

template<typename ValueType>
TStack<ValueType>::~TStack() 
{
	top = 0;
	maxsize = 0;
	delete [] x;
}

template<typename ValueType>
void TStack<ValueType>::Push(ValueType a) {
	if (IsFull()) 
	{
		throw "The stack is full";
	}
	x[top++] = a;
}

template<typename ValueType>
ValueType TStack<ValueType>::Pop() {
	if (IsEmpty())
		throw "The stack is empty";
	return x[--top];
}

template<typename ValueType>
bool TStack<ValueType>::IsEmpty() const
{
	return (top == 0);
}

template<typename ValType>
bool TStack<ValType>::IsFull() const 
{
	return (maxsize == top);
}

template<class ValueType>
int TStack<ValueType>::Top()const
{
	return top;
};

template<class ValueType>
ValueType TStack<ValueType>::Getlast()const
{
	return x[top - 1];
}
#endif TSTACK_H