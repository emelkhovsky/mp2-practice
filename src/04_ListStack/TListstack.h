#ifndef _TLISTSTACK_H_
#define _TLISTSTACK_H_

#include <iostream>
#include "exceptions.h"
#include "TList.h"
#include "TStack.h"
using namespace std;

template<typename ValType>
class TListStack : public TStack<ValType>{
private:
	TList<ValType, ValType>* elements;
public:
	TListStack();
	TListStack(const TListStack&);
	~TListStack();
	void Push(ValType);
	void Pop();
	ValType Pop_Get()const
	bool IsEmpty() const;
	bool IsFull() const;
};

template<typename ValType>
TListStack<ValType>::TListStack(){//конструктор
	elements = new TList<ValType, ValType>;
};

template<typename ValType>
TListStack<ValType>::TListStack(const TListStack<ValType>& list){//конструктор копирования
	elements = new TList<ValType>(list.elements);
};

template<typename ValType>
TListStack<ValType>::~TListStack(){//деструктор
	delete[] elements;
};

template<typename ValType>
bool TListStack<ValType>::IsEmpty() const {
	return (elements->GetpFirst() == NULL);
};

template<typename ValType>
bool TListStack<ValType>::IsFull() const{
	TNode<ValType, ValType>* node = new TNode<ValType, ValType>();
	return !node;
};

template<typename ValType>
void TListStack<ValType>::Push(ValType _elements)
{
	if (IsFull())
		throw Exception("Error: stack is full!");

	elements->PopBegin(_elements, NULL);
	elements->Reset();
};

template<typename ValType>
void TListStack<ValType>::Pop()
{
	if (IsEmpty())
		throw Exception("Error: stack is empty!");

	elements->Delete(elements->GetpFirst()->key);
	elements->Reset();
};

template<typename ValType>
ValType TListStack<ValType>::TopWatch() const
{
	if (IsEmpty())
		throw Exception("Error: stack is empty!");

	return elements->GetpFirst()->key;
};

#endif