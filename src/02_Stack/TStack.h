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
	TStack(int);//конструктор
	TStack(const TStack&);//конструктор копирования
	~TStack();//деструктор
	void Push(ValType);//кладет элемент на вершину стека
	ValType Pop();//удаляем и выводим удаленный элемент
	bool IsEmpty()const;//проверка на пустоту
	bool IsFull()const;//проверка на полноту
	int GettingMaxSize() const;//получаем максимальный размер стека
	ValType GettingTopElement() const;//получаем значение вершины
	int GettingTop() const;//получаем топ
};

template<typename ValType>//констркутор с параметром
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

template<typename ValType>//конструктор копирования
TStack<ValType>::TStack(const TStack& stack) {
	max_size = stack.max_size;
	top = stack.top;
	for (int i; i < max_size; i++) {
		elements[i] = stack.elements[i];
	}
}

template<typename ValType>//деструктор
TStack<ValType>::~TStack() {
	top = 0;
	max_size = 0;
	delete [] elements;
}

template<typename ValType>//добавление элемента на вершину стека
void TStack<ValType>::Push(ValType el) {
	if (IsFull()) {
		throw full();
	}
	elements[top] = el;
}

template<typename ValType>//удаление элемента и его вывод
ValType TStack<ValType>::Pop() {
	if (IsEmpty) {
		throw Empty();
	}
	ValType dop_value = dop_value + elements[top];
	return dop_value;
}

template<typename ValType>//проверка на пустоту
bool TStack<ValType>::IsEmpty()const{
	return (top == 0);
}

template<typename ValType>//проверка на полноту
bool TStack<ValType>::IsFull()const {
	return (max_size == top);
}

template<typename ValType>//получение максимального размера стека
int TStack<ValType>::GettingMaxSize()const {
	return max_size;
}

template<typename ValType>//получение значение вершины
ValType TStack<ValType>::GettingTopElement()const {
	return elements[top - 1];
}

template<typename ValType>//получение топа
int TStack<ValType>::GettingTop()const {
	return top;
}

#endif