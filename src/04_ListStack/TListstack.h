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
TListStack<ValType>::TListStack(){//�����������
	elements = new TList<ValType, ValType>;
};

template<typename ValType>
TListStack<ValType>::TListStack(const TListStack<ValType>& list){//����������� �����������
	elements = new TList<ValType>(list.elements);
};

template<typename ValType>
TListStack<ValType>::~TListStack(){//����������
	delete[] elements;
};

template<class ValType>
bool TListStack<ValType>::IsEmpty()const{
	return (elements->GetpFirst() == NULL);
};

template<typename ValType>
bool TListStack<ValType>::IsFull() const{
	TNode<ValType, ValType>* node = new TNode<ValType, ValType>();
	return !node;
};

template<typename ValType>
void TListStack<ValType>::Push(ValType els){
	if (IsFull())
		throw Exception("���� �����:(");
	elements->PopBegin(els, NULL);
	elements->Reset();
};

template<typename ValType>
void TListStack<ValType>::Pop(){
	if (IsEmpty())
		throw Exception("���� ����:(");
	elements->Delete(elements->GetpFirst()->key);
	elements->Reset();
};

template<typename ValType>
ValType TListStack<ValType>::Pop_Get() const{
	if (IsEmpty())
		throw Exception("���� ����:(");
	return elements->GetpFirst()->key;
};

#endif