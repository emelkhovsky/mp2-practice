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
    ValType Pop_Get();//удаляем элемент и возвращаем его

    bool IsEmpty()const;//проверка на пустоту
    bool IsFull()const;//проверка на полноту

    void Pop();//уменьшаем стек
};

template<typename ValType>//констркутор с параметром
TStack<ValType>::TStack(int _max_size) {
    if (_max_size <= 0) {
        throw Exception("Некорректный максимальный размер стека\n");
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

template<typename ValType>//деструктор(done)
TStack<ValType>::~TStack() {
    top = 0;
    max_size = 0;
    delete [] elements;
}

template<typename ValType>//добавление элемента на вершину стека
void TStack<ValType>::Push(ValType el) {
    if (IsFull()) {
        throw Exception("Стек полон\n");
    }
    elements[top] = el;
    top++;
}

template<typename ValType>//удаление элемента и получение топа
ValType TStack<ValType>::Pop_Get() {
    if (IsEmpty()) {
        throw Exception("Стек пуст\n");
    }
	return elements[top-1];
}

template<typename ValType>//проверка на пустоту
bool TStack<ValType>::IsEmpty()const{
    return (top == 0);
}

template<typename ValType>//проверка на полноту
bool TStack<ValType>::IsFull()const {
    return (max_size == top);
}

template<typename ValType>//уменьшение стека
void TStack<ValType>::Pop() {
	if (IsEmpty()) {
		throw Exception("Стек пуст\n");
	}
	top--;
}

#endif