#ifndef _TARRAYSTACK_H_ 
#define _TARRAYSTACK_H_
#include "exceptions.h"
using namespace std;

template<typename ValType>
class TArrayStack: public TStack<ValType> {
private:
	int max_size;
	ValType* elements;
	int top;
public:
	TArrayStack(int);//�����������
	TArrayStack(const TArrayStack&);//����������� �����������
	~TArrayStack();//����������

	void Push(ValType);//������ ������� �� ������� �����
	ValType Pop_Get() const;//������� ������� � ���������� ���

	bool IsEmpty() const;//�������� �� �������
	bool IsFull() const;//�������� �� �������

	void Pop();//��������� ����
};

template<typename ValType>//����������� � ����������
TArrayStack<ValType>::TArrayStack(int _max_size):max_size(_max_size) {
	if (_max_size <= 0) {
		throw Exception("������������ ������������ ������ �����\n");
	}
	elements = new ValType[max_size];
	top = 0;
	for (int i = 0; i < max_size; i++) {
		elements[i] = 0;
	}
}

template<typename ValType>//����������� �����������
TArrayStack<ValType>::TArrayStack(const TArrayStack& stack):max_size(stack.max_size), top(stack.top) {
	max_size = stack.max_size;
	top = stack.top;
	for (int i; i < max_size; i++) {
		elements[i] = stack.elements[i];
	}
}

template<typename ValType>//����������(done)
TArrayStack<ValType>::~TArrayStack() {
	top = 0;
	max_size = 0;
	delete[] elements;
}

template<typename ValType>//���������� �������� �� ������� �����
void TArrayStack<ValType>::Push(ValType el) {
	if (IsFull()) {
		throw Exception("���� �����\n");
	}
	elements[top] = el;
	top++;
}

template<typename ValType>//�������� �������� � ��������� ����
ValType TArrayStack<ValType>::Pop_Get()const {
	if (IsEmpty()) {
		throw Exception("���� ����\n");
	}
	return elements[top - 1];
}

template<typename ValType>//�������� �� �������
bool TArrayStack<ValType>::IsEmpty() const {
	return (top == 0);
}

template<typename ValType>//�������� �� �������
bool TArrayStack<ValType>::IsFull()const {
	return (max_size == top);
}

template<typename ValType>//���������� �����
void TArrayStack<ValType>::Pop() {
	if (IsEmpty()) {
		throw Exception("���� ����\n");
	}
	top--;
}

#endif