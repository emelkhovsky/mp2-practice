#ifndef _TMATRIX_H_
#define _TMATRIX_H_

#include <iostream>

#include "TVector.h"
#include "exception.h"


template <typename ValType>
class TMatrix: public TVector <TVector <ValType> > {
public:
    TMatrix(int _size = 10);//по умолчанию
    TMatrix(const TMatrix&);//копирования
    TMatrix(const TVector<TVector <ValType> >&);//преобразования вектора векторов в объект матрицы
    ~TMatrix();

    bool operator == (const TMatrix&)const;
    bool operator != (const TMatrix&)const;

    const TMatrix& operator = (const TMatrix&);
    TMatrix operator + (ValType);//с константами
    TMatrix operator - (ValType);
    TMatrix operator * (ValType);
    TMatrix operator + (const TMatrix&);//к матирице матрицу
    TMatrix operator - (const TMatrix&);
    TMatrix operator * (const TMatrix&);//матрицу на матрицу
    TVector<ValType> operator * (const TVector <ValType> &);//матрицу на вектор

    friend ostream& operator << (ostream& out, const TMatrix& matrix) {
        if (matrix.size == 0) {
            throw matrixzerosizeerror();
        }
        for (int i = 0; i < matrix.size; i++) {
			for (int j = 0; j < matrix.elements[i].StartIndex(); j++) {
				out << "0, ";
			}
            out << matrix.elements[i]<<"\n";
        
        }
        return out;
    };
    friend istream& operator >> (istream& in, TMatrix& matrix) {
        for (int i = 0; i < matrix.size; i++) {
            in >> matrix.elements[i];
        }
        return in;
    };
};

template <typename ValType>//конструктор с параметром
TMatrix<ValType>::TMatrix(int _size) :TVector<TVector<ValType> >(_size) {
    this->size = _size;
    for (int i = 0; i < _size; i++) {
        this->elements[i] = TVector<ValType> (_size - i, i);
    }
}

template <typename ValType>//конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix& matrix):TVector<TVector<ValType> >(matrix) {}

template <typename ValType>
TMatrix<ValType>::TMatrix(const TVector <TVector <ValType> >& matrix) : TVector<TVector<ValType> >(matrix) {}

template <typename ValType>
TMatrix<ValType>::~TMatrix() {}

template <typename ValType>//оператор равенства
bool TMatrix<ValType>::operator == (const TMatrix& matrix) const {
    if (this->size != matrix.size)
        return false;
    for (int i = 0; i < this->size; i++)
        if (this->elements[i] != matrix.elements[i])
            return false;
    return true;
}

template <typename ValType>//оператор неравенства
bool TMatrix<ValType>::operator != (const TMatrix& matrix) const {
    return (!(*this == matrix));
}

template<typename ValType>//присваивание ТУТ ОШИБКА
const TMatrix<ValType>& TMatrix<ValType>:: operator = (const TMatrix& matrix) {
    if (this != &matrix){
        if (this->size != matrix.size){
            this->size = matrix.size;
            delete this->elements;
            this->elements = new TVector<ValType>[matrix.size];
        }
        for (int i = 0; i < this->size; i++){
            this->elements[i] = matrix.elements[i];
        }
    }
    return *this;
}

template<typename ValType>//сложение с const
TMatrix<ValType> TMatrix<ValType>:: operator + (ValType c) {
    TMatrix<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++)
        dop.elements[i] = this->elements[i] + c;
    return dop;
}

template<typename ValType>//вычитание с const
TMatrix<ValType> TMatrix<ValType>:: operator - (ValType c) {
    TMatrix<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++)
        dop.elements[i] = this->elements[i] - c;
    return dop;
}

template<typename ValType>//умножение с const
TMatrix<ValType> TMatrix<ValType>:: operator * (ValType c) {
    TMatrix<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++)
        dop.elements[i] = this->elements[i] * c;
    return dop;
}

template<typename ValType>//сложение 
TMatrix<ValType> TMatrix<ValType>:: operator + (const TMatrix& matrix) {
    if (this->size != matrix.size)
        throw matrixsizeerror();
    TMatrix<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++) {
        dop.elements[i] = this->elements[i] + matrix.elements[i];
    }
	for (int j = 0; j < matrix.size; j++) {
		cout << "start: "<<matrix.elements[j].StartIndex()<<endl;
	}
    return dop;
}

template<typename ValType>//вычитание 
TMatrix<ValType> TMatrix<ValType>:: operator - (const TMatrix& matrix) {
    if (this->size != matrix.size)
        throw matrixsizeerror();
    TMatrix<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++)
        dop.elements[i] = this->elements[i] - matrix.elements[i];
    return dop;
}

template<typename ValType>//умножение матрицы на матрицу
TMatrix<ValType> TMatrix<ValType>:: operator * (const TMatrix& matrix) {
    if (this->size != matrix.size)
        throw matrixsizeerror();
    TMatrix<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++)
        for (int j = this->elements[i].StartIndex(); j < this->size; j++) {
            dop.elements[i][j - i] = 0;
            for (int k = i; k <= j; k++) {
                dop.elements[i][j - i] = dop.elements[i][j - i] + this->elements[i][k - i] * matrix.elements[k][j - k];
            }
        }

    return dop;
}

template<typename ValType>//умножение матрицы   на вектор
TVector<ValType> TMatrix<ValType>:: operator * (const TVector<ValType> & vector) {
    if (this->size != vector.Size())
        throw matrixvectorsizeerror();
    TVector<ValType> dop(this->size);
    for (int i = 0; i < this->size; i++) {
        dop[i] = 0;
        for (int j = 0; j < this->elements[i].Size(); j++)
            dop[i] += this->elements[i][j] * vector[i + j];
    }
    return dop;
}

#endif

