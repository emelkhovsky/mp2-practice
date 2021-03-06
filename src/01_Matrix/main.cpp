﻿#include <iostream>
#include <locale.h>

#include "exception.h"
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

void main() {
    /*-------------------------векторы--------------------------*/
    TVector<int> a(3);
    TVector<int> b(3);
    TVector<int> c(4);
    TVector<int> d(0);
    TVector<int> m(4, 3);
    TVector<int> rez;
    float rez_umnosh;
    TMatrix<int> am(3);
    TMatrix<int> bm(3);
    TMatrix<int> cm(3);
    TMatrix<int> dm(0);
    TMatrix<int> em(2);
    TMatrix<int> preobrm(3);
    int cc = 10;
    setlocale(LC_ALL, "Rus");

    //вывод стартового индекса
    cout << "старт индекс веткора m:" << endl;
    cout << m.StartIndex() << endl;

    //ввод векторов
    cout << "¬ведите вектор a" << endl;
    cin >> a;
    cout << a << endl;
    cout << "¬ведите вектор b" << endl;
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

    //операции сравнени¤
    if (a != b) {
        cout << "a не равно b" << endl;
    }
    cout << "приравн¤ем a = b:";
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
    }
    /*-------------------------матрицы--------------------------*/
    try {
    //ввод матриц
    cout << "¬ведите матрицу am" << endl;
    cin >> am;
    cout << am << endl;
    cout << "¬ведите матрицу bm" << endl;
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

    //конструктор преобразования
    cout << "конструктор преобразования" << endl;
    TVector <TVector<int> > vector(3);
    for (int i = 0; i < 3; i++)
    {
        TVector<int> t(3 - i);
        for (int j = i; j < 3; j++)
            t[j - i] = i + j + 1;
        vector[i] = t;
    }
    cout << vector << endl;
    preobrm = vector;
    cout << preobrm << endl;

    //неравенства
    if (am != bm) {
        cout << "am не равно bm" << endl;
    }
    cout << "приравн¤ем am = bm:";
    am = bm;
    if (am == bm) {
        cout << "am равно bm" << endl;
    }

    //сложение матриц разных размерностей
        cout << "сложение матриц разных размерностей am + em:";
        cm = am + em;

    }
    catch (matrixsizeerror e) {
        cout << e.what() << endl;
    }

    try {

    //операции с константами + конструктор копирования матрицы
    cout << "am + const" << endl;
    cm = am + cc;
    cout << cm;
    cout << "am - const" << endl;
    cm = am - cc;
    cout << cm;
    cout << "am * const" << endl;
    cm = am * cc;
    cout << cm;
    TMatrix<int> copycm(cm);//копирование матрицы
    cout << "копирую в copym матрицу cm. copycm равна:\n" << endl;
    cout << copycm;

    //вывод матрицы размера 0
        cout << "вывод нулевой матрицы dm(0):";
        cout << dm;

    }
    catch (matrixzerosizeerror e) {
        cout << e.what() << endl;
    }

    //умножение вектора на матрицы
    try {
        cout << "введите вектор a размерности 3" << endl;
        cin >> a;
        cout << "bm * a: " << bm * a << endl;
        cout << "введите вектор a размерности 4" << endl;
        cin >> c;
        cout << "умножение матрицы на вектор другой размерности: am * c: " << am * c <<endl;
    }
    catch (matrixvectorsizeerror e) {
        cout << e.what() << endl;
    }

    system("pause");
}

