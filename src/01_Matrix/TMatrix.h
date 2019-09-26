#ifndef _TMATRIX_H_
#define _TMATRIX_H_

#include <iostream>

#include "TVector.h"
#include "exception.h"


template <typename ValType>
class TMatrix: public TVector <TVector <ValType> > {
public:
	TMatrix(int _size = 10);//�� ���������
	TMatrix(const TMatrix&);//�����������
	TMatrix(const TVector<TVector <ValType> >&);//�������������� ������� �������� � ������ �������
	~TMatrix();

	bool operator == (const TMatrix&)const;
	bool operator != (const TMatrix&)const;

	const TMatrix& operator = (const TMatrix&);
	TMatrix operator + (ValType);//� �����������
	TMatrix operator - (ValType);
	TMatrix operator * (ValType);
	TMatrix operator + (const TMatrix&);//� �������� �������
	TMatrix operator - (const TMatrix&);
	TMatrix operator * (const TMatrix&);//������� �� �������
	TVector<ValType> operator * (const TVector <ValType> &);//������� �� ������

	friend ostream& operator << (ostream& out, const TMatrix& matrix) {
		if (matrix.size == 0) {
			throw matrixzerosizeerror();
		}
		for (int i = 0; i < matrix.size; i++) {
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

template <typename ValType>//����������� � ����������
TMatrix<ValType>::TMatrix(int _size) :TVector<TVector<ValType> >(_size) {
	this->size = _size;
	for (int i = 0; i < _size; i++) {
		this->elements[i] = TVector<ValType> (_size - i, i);
	}
}

template <typename ValType>//����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix& matrix):TVector<TVector<ValType> >(matrix) {}

template <typename ValType>
TMatrix<ValType>::TMatrix(const TVector <TVector <ValType> >& matrix) : TVector<TVector<ValType> >(matrix) {}

template <typename ValType>
TMatrix<ValType>::~TMatrix() {}

template <typename ValType>//�������� ���������
bool TMatrix<ValType>::operator == (const TMatrix& matrix) const {
	if (this->size != matrix.size)
		return false;
	for (int i = 0; i < this->size; i++)
		if (this->elements[i] != matrix.elements[i])
			return false;
	return true;
}

template <typename ValType>//�������� �����������
bool TMatrix<ValType>::operator != (const TMatrix& matrix) const {
	return (!(*this == matrix));
}

template<typename ValType>//������������
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

template<typename ValType>//�������� � const
TMatrix<ValType> TMatrix<ValType>:: operator + (ValType c) {
	TMatrix<ValType> dop(this->size);
	for (int i = 0; i < this->size; i++)
		dop.elements[i] = this->elements[i] + c;
	return dop;
}

template<typename ValType>//��������� � const
TMatrix<ValType> TMatrix<ValType>:: operator - (ValType c) {
	TMatrix<ValType> dop(this->size);
	for (int i = 0; i < this->size; i++)
		dop.elements[i] = this->elements[i] - c;
	return dop;
}

template<typename ValType>//��������� � const
TMatrix<ValType> TMatrix<ValType>:: operator * (ValType c) {
	TMatrix<ValType> dop(this->size);
	for (int i = 0; i < this->size; i++)
		dop.elements[i] = this->elements[i] * c;
	return dop;
}

template<typename ValType>//�������� 
TMatrix<ValType> TMatrix<ValType>:: operator + (const TMatrix& matrix) {
	if (this->size != matrix.size)
		throw matrixsizeerror();
	TMatrix<ValType> dop(this->size);
	for (int i = 0; i < this->size; i++) {
		dop.elements[i] = this->elements[i] + matrix.elements[i];
		cout << dop.elements[i] << endl;
	}
	return dop;
}

template<typename ValType>//��������� 
TMatrix<ValType> TMatrix<ValType>:: operator - (const TMatrix& matrix) {
	if (this->size != matrix.size)
		throw matrixsizeerror();
	TMatrix<ValType> dop(this->size);
	for (int i = 0; i < this->size; i++)
		dop.elements[i] = this->elements[i] - matrix.elements[i];
	return dop;
}

template<typename ValType>//��������� ������� �� �������
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

template<typename ValType>//��������� �������   �� ������
TVector<ValType> TMatrix<ValType>:: operator * (const TVector<ValType> & vector) {
	if (this->size != vector.Size())
		throw matrixsizeerror();
	TVector<ValType> dop(this->size);
	for (int i = 0; i < this->size; i++) {
		dop[i] = 0;
		int start = this->elements[i].StartIndex();
		cout << "s1"<<start << endl;
		for (int j = 0; j < this->elements[i].Size(); j++) {
			cout << "j:" << j << endl;
			cout << dop[i] << "+" << this->elements[i][j] << "*"<<vector[j]<<endl;
			dop[i] = dop[i] + this->elements[i][j] * vector[j];
		}
	}
	return dop;
}

#endif

