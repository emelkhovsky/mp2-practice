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
	TArrayStack(int);//конструктор
	TArrayStack(const TArrayStack&);//конструктор копирования
	~TArrayStack();//деструктор

	void Push(ValType);//кладет элемент на вершину стека
	ValType Pop_Get() const;//удаляем элемент и возвращаем его

	bool IsEmpty() const;//проверка на пустоту
	bool IsFull() const;//проверка на полноту

	void Pop();//уменьшаем стек
};

template<typename ValType>//констркутор с параметром
TArrayStack<ValType>::TArrayStack(int _max_size):max_size(_max_size) {
	if (_max_size <= 0) {
		throw Exception("Некорректный максимальный размер стека\n");
	}
	elements = new ValType[max_size];
	top = 0;
	for (int i = 0; i < max_size; i++) {
		elements[i] = 0;
	}
}

template<typename ValType>//конструктор копирования
TArrayStack<ValType>::TArrayStack(const TArrayStack& stack):max_size(stack.max_size), top(stack.top) {
	max_size = stack.max_size;
	top = stack.top;
	for (int i; i < max_size; i++) {
		elements[i] = stack.elements[i];
	}
}

template<typename ValType>//деструктор(done)
TArrayStack<ValType>::~TArrayStack() {
	top = 0;
	max_size = 0;
	delete[] elements;
}

template<typename ValType>//добавление элемента на вершину стека
void TArrayStack<ValType>::Push(ValType el) {
	if (IsFull()) {
		throw Exception("Стек полон\n");
	}
	elements[top] = el;
	top++;
}

template<typename ValType>//удаление элемента и получение топа
ValType TArrayStack<ValType>::Pop_Get()const {
	if (IsEmpty()) {
		throw Exception("Стек пуст\n");
	}
	return elements[top - 1];
}

template<typename ValType>//проверка на пустоту
bool TArrayStack<ValType>::IsEmpty() const {
	return (top == 0);
}

template<typename ValType>//проверка на полноту
bool TArrayStack<ValType>::IsFull()const {
	return (max_size == top);
}

template<typename ValType>//уменьшение стека
void TArrayStack<ValType>::Pop() {
	if (IsEmpty()) {
		throw Exception("Стек пуст\n");
	}
	top--;
}

#endif