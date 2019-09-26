#include <iostream>
#include <locale.h>

#include "exception.h"
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

void main() {
	/*-------------------------ЧАСТЬ_С_ВЕКТОРАМИ--------------------------*/
	/*TVector<int> a(3);
	TVector<int> b(3);
	TVector<int> c(4);
	TVector<int> d(0);
	TVector<int> rez;
	float rez_umnosh;*/
	TMatrix<int> am(3);
	TMatrix<int> bm(3);
	TMatrix<int> cm(3);
	TMatrix<int> dm(0);

	int cc = 10;
	setlocale(LC_ALL, "Rus");
	/*
	//ввод векторов
	cout << "Введите вектор a" << endl;
	cin >> a;
	cout << a << endl;
	cout << "Введите вектор b" << endl;
	cin >> b;
	cout << b << endl;
	
	//вывод нулевого вектора
	try {
		cout << "вектор d(0):";
		cout << d;

	}
	catch (vectorzerosizeerror e) {
		cout << e.what() << endl;
	}

	//операции с векторами
	try {
		rez = a - b;
		cout << "a - b:\n"<< rez << endl;
		rez = a + b;
		cout << "a + b:\n" << rez << endl;	
		cout << "a * c:\n" << endl;
		rez_umnosh = a * c;
		
	}
	catch (vectorsizeerror e){
		cout << e.what() << endl;
	}
	
	//операции с константами
	rez = a + cc;
	cout << "a + 10:\n" << rez << endl;
	rez = a - cc;
	cout << "a - 10:\n" << rez << endl;
	rez = a * cc;
	cout << "a * 10:\n" << rez << endl;

	//операции сравнения
	if (a != b) {
		cout << "a не равно b" << endl;
	}
	cout << "приравняем a = b:";
	a = b;
	if (a == b) {
		cout << "a равно b" << endl;
	}

	//длина вектора
	cout << "длина вектора a:" << a.Lenght() << endl;

	//индекс вектора
	try {
		cout << "a[0]:" << a[0] << endl;
		cout << "a[-1]:" << endl;
		cout << a[-1] << endl;

	}
	catch (vectorincorrectindexerror e) {
		cout << e.what() << endl;
	}*/
	/*-------------------------ЧАСТЬ_С_МАТРИЦАМИ--------------------------*/

	//ввод матриц
	cout << "Введите матрицу am" << endl;
	cin >> am;
	cout << am << endl;
	cout << "Введите матрицу bm" << endl;
	cin >> bm;
	cout << bm << endl;

	//операции с матрицами
	cout << "am + bm" << endl;
	cm = am + bm;
	cout << cm;
	cout << "am - bm" << endl;
	cm = am - bm;
	cout << cm;
	cout << "am * bm" << endl;
	cm = am * bm;
	cout << cm;

	//вывод нулевого вектора
	try {
		cout << "вывод нулевой матрицы dm(0):";
		cout << dm;

	}
	catch (matrixzerosizeerror e) {
		cout << e.what() << endl;
	}





	system("pause");
}

