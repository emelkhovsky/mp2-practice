#ifndef _TSTACK_H_ 
#define _TSTACK_H_
#include "exceptions.h"
using namespace std;

template<typename ValType>
class TStack {
private:
	int max_size;
	ValType* elements;
	int top;
public:
	TStack(int);//�����������
	TStack(const TStack&);//����������� �����������
	~TStack();//����������
	void Push(ValType);//������ ������� �� ������� �����
	ValType Pop();//������� � ������� ��������� �������
	bool IsEmpty()const;//�������� �� �������
	bool IsFull()const;//�������� �� �������
	int GettingMaxSize() const;//�������� ������������ ������ �����
	ValType GettingTopElement() const;//�������� �������� �������
	int GettingTop() const;//�������� ���
};

template<typename ValType>//����������� � ����������
TStack<ValType>::TStack(int _max_size) {
	if (_max_size <= 0) {
		throw incorrect_max_size();
	}
	max_size = _max_size;
	elements = new ValType[max_size];
	top = 0;
	for (int i = 0; i < max_size; i++) {
		elements[i] = 0;
	}
}

template<typename ValType>//����������� �����������
TStack<ValType>::TStack(const TStack& stack) {
	max_size = stack.max_size;
	top = stack.top;
	for (int i; i < max_size; i++) {
		elements[i] = stack.elements[i];
	}
}

template<typename ValType>//����������
TStack<ValType>::~TStack() {
	top = 0;
	max_size = 0;
	delete [] elements;
}

template<typename ValType>//���������� �������� �� ������� �����
void TStack<ValType>::Push(ValType el) {
	if (IsFull()) {
		throw full();
	}
	elements[top] = el;
}

template<typename ValType>//�������� �������� � ��� �����
ValType TStack<ValType>::Pop() {
	if (IsEmpty) {
		throw Empty();
	}
	ValType dop_value = dop_value + elements[top];
	return dop_value;
}

template<typename ValType>//�������� �� �������
bool TStack<ValType>::IsEmpty()const{
	return (top == 0);
}

template<typename ValType>//�������� �� �������
bool TStack<ValType>::IsFull()const {
	return (max_size == top);
}

template<typename ValType>//��������� ������������� ������� �����
int TStack<ValType>::GettingMaxSize()const {
	return max_size;
}

template<typename ValType>//��������� �������� �������
ValType TStack<ValType>::GettingTopElement()const {
	return elements[top - 1];
}

template<typename ValType>//��������� ����
int TStack<ValType>::GettingTop()const {
	return top;
}

#endif