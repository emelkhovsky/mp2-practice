#ifndef _TLISTSTACK_H_
#define _TLISTSTACK_H_

#include <iostream>
#include "exceptions.h"
#include "TList.h"
#include "TStack.h"
#include "TNode.h"
using namespace std;

template<typename ValType>
class TListStack : public TStack<ValType> {
private:
	TList<ValType, ValType>* elements;
public:
	TListStack();
	TListStack(const TListStack&);
	~TListStack();
	bool IsEmpty()const;
	bool IsFull() const;
	void Push(ValType);
	void Pop();
	ValType Pop_Get()const;
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

template<class ValType>
bool TListStack<ValType>::IsEmpty()const{
	return (elements->GetpFirst() == NULL);
};

template<typename ValType>
bool TListStack<ValType>::IsFull() const {
	try
	{
		TNode<ValType, ValType>* node = new TNode<ValType, ValType>();
		if (node == NULL)
			return true;
		delete node;		
	}
	catch (...)
	{
		return true;
	}
	return false;
};

template<typename ValType>
void TListStack<ValType>::Push(ValType els){
	if (IsFull())
		throw Exception("Стек полон:(");
	elements->PushBegin(els, NULL);
};

template<typename ValType>
void TListStack<ValType>::Pop(){
	if (IsEmpty())
		throw Exception("Стек пуст:(");
	elements->Delete(elements->GetpFirst()->key);
};

template<typename ValType>
ValType TListStack<ValType>::Pop_Get() const{
	if (IsEmpty())
		throw Exception("Стек пуст:(");
	return elements->GetpFirst()->key;
};

#endif