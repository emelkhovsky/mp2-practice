#ifndef _TVECTOR_H_
#define _TVECTOR_H_

#include <iostream>
#include <cmath>

#include "exception.h"

template <typename ValType>
class TVector {
protected:
	int size;
	int start_index;
	ValType* elements;
public:
	TVector(int _size = 5, int _start_index = 0);//с параметрами
	TVector(const TVector&);//копирования
	~TVector();

	bool operator == (const TVector& ) const;
	bool operator != (const TVector& ) const;

	TVector& operator = (const TVector& );
	TVector operator + (ValType);//с константами
	TVector operator - (ValType);
	TVector operator * (ValType);
	TVector operator + (const TVector&);//с векторами
	TVector operator - (const TVector&);
	ValType operator * (const TVector&);

	ValType Lenght() const;
	ValType Size() const;
	int StartIndex()const;
	ValType& operator [](int index);

	friend ostream& operator<<(ostream& out, const TVector& vector) {
		if (vector.size == 0) {
			throw vectorzerosizeerror();
		}
		for (int i = 0; i < vector.size; i++)
			out << vector.elements[i] << ", ";
		out << "\n";
		return out;

	};
	friend istream& operator>>(istream& in, TVector& vector) {
		for (int i = 0; i < vector.size; i++) {
			in >> vector.elements[i];
		}
		return in;
	};
};

template <typename ValType>//конструктор с параметрами
TVector<ValType>::TVector(int _size, int _start_index) {
	size = _size;
	elements = new ValType[size];
	start_index = _start_index;
}

template <typename ValType>//конструктор копирования
TVector<ValType>::TVector(const TVector& vector) {
	size = vector.size;
	elements = new ValType[size];
	start_index = vector.start_index;
	for (int i = 0; i < size; i++) 
		 elements[i] = vector.elements[i];
}

template <typename ValType>//деструктор
TVector<ValType>::~TVector() {
	size = 0;
	delete[]  elements;
}

template <typename ValType>//оператор равенства
bool TVector<ValType>::operator == (const TVector& vector) const {
	if (size != vector.size)
		return false;
	for (int i = 0; i < size; i++) 
		if ( elements[i] != vector.elements[i])
			return false;
	return true;
}

template <typename ValType>//оператор неравенства
bool TVector<ValType>::operator != (const TVector& vector) const {
	return !(vector == *this);
}

template<typename ValType>//присваивание
TVector<ValType>& TVector<ValType>:: operator = (const TVector& vector) {
	if (this == &vector)
		return *this;
	delete[]  elements;
	size = vector.size;
	start_index = vector.start_index;
	 elements = new ValType [size];
	for (int i = 0; i < size; i++) {
		 elements[i] = vector.elements[i];
	}
	return *this;
}

template<typename ValType>//сложение с const
TVector<ValType> TVector<ValType>:: operator + (ValType c) {
	TVector<ValType> dop(size);
	for (int i = 0; i < size; i++)
			dop.elements[i] =  elements[i] + c;
	return dop;
}

template<typename ValType>//вычитание с const
TVector<ValType> TVector<ValType>:: operator - (ValType c) {
	TVector<ValType> dop(size);
	for (int i = 0; i < size; i++)
		dop.elements[i] =  elements[i] - c;
	return dop;
}

template<typename ValType>//умножение с const
TVector<ValType> TVector<ValType>:: operator * (ValType c) {
	TVector<ValType> dop(size);
	for (int i = 0; i < size; i++)
		dop.elements[i] =  elements[i] * c;
	return dop;
}

template<typename ValType>//сложение 
TVector<ValType> TVector<ValType>:: operator + (const TVector& vector) {
	if (size != vector.size)
		throw vectorsizeerror();
	TVector<ValType> dop(size);
	for (int i = 0; i < size; i++) {
			dop.elements[i] =  elements[i] + vector.elements[i];
		}
	return dop;
}

template<typename ValType>//вычитание 
TVector<ValType> TVector<ValType>:: operator - (const TVector& vector) {
	if (size != vector.size)
		throw vectorsizeerror();
	TVector<ValType> dop(size);
	for (int i = 0; i < size; i++)
		dop.elements[i] =  elements[i] - vector.elements[i];
	return dop;
}

template<typename ValType>//умножение
ValType TVector<ValType>:: operator * (const TVector& vector) {
	if (size != vector.size)
		throw vectorsizeerror();
	ValType rez = 0;
	for (int i = 0; i < size; i++)
		rez = rez +  elements[i] * vector.elements[i];
	return rez;
}

template<typename ValType>//длина
ValType TVector<ValType>:: Lenght () const {
	ValType s = 0;
	for (int i = 0; i < size; i++)
		s = s +  elements[i] *  elements[i];
	s = sqrt(s);
	return s;
}

template<typename ValType>//размер
ValType TVector<ValType>::Size() const {
	return size;
}

template<typename ValType>//стартиндекс
int TVector<ValType>::StartIndex() const {
	return start_index;
}

template<typename ValType>//перегрузка []
ValType& TVector<ValType>:: operator [] (int index) {
	if((index < 0)||(index >= size))
		throw vectorincorrectindexerror();
	return  elements[index];
}

#endif