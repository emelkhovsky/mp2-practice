#include <iostream>
#include <locale.h>

#include "exception.h"
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

void main() {
	/*-------------------------�����_�_���������--------------------------*/
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
	//���� ��������
	cout << "������� ������ a" << endl;
	cin >> a;
	cout << a << endl;
	cout << "������� ������ b" << endl;
	cin >> b;
	cout << b << endl;
	
	//����� �������� �������
	try {
		cout << "������ d(0):";
		cout << d;

	}
	catch (vectorzerosizeerror e) {
		cout << e.what() << endl;
	}

	//�������� � ���������
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
	
	//�������� � �����������
	rez = a + cc;
	cout << "a + 10:\n" << rez << endl;
	rez = a - cc;
	cout << "a - 10:\n" << rez << endl;
	rez = a * cc;
	cout << "a * 10:\n" << rez << endl;

	//�������� ���������
	if (a != b) {
		cout << "a �� ����� b" << endl;
	}
	cout << "���������� a = b:";
	a = b;
	if (a == b) {
		cout << "a ����� b" << endl;
	}

	//����� �������
	cout << "����� ������� a:" << a.Lenght() << endl;

	//������ �������
	try {
		cout << "a[0]:" << a[0] << endl;
		cout << "a[-1]:" << endl;
		cout << a[-1] << endl;

	}
	catch (vectorincorrectindexerror e) {
		cout << e.what() << endl;
	}*/
	/*-------------------------�����_�_���������--------------------------*/

	//���� ������
	cout << "������� ������� am" << endl;
	cin >> am;
	cout << am << endl;
	cout << "������� ������� bm" << endl;
	cin >> bm;
	cout << bm << endl;

	//�������� � ���������
	cout << "am + bm" << endl;
	cm = am + bm;
	cout << cm;
	cout << "am - bm" << endl;
	cm = am - bm;
	cout << cm;
	cout << "am * bm" << endl;
	cm = am * bm;
	cout << cm;

	//����� �������� �������
	try {
		cout << "����� ������� ������� dm(0):";
		cout << dm;

	}
	catch (matrixzerosizeerror e) {
		cout << e.what() << endl;
	}





	system("pause");
}

