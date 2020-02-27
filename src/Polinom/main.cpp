#include "TPolinom.h"
#include "TListP.h"
#include "exceptions.h"
#include <iostream>
#include <conio.h>
using namespace std;

void main(){
	setlocale(LC_ALL, "Rus");
	char c;
	try{
		cout << "--------------------------��������--------------------------" << endl;
		TNode<int, float>* monom3 = new TNode<int, float>(123, 5);
		TNode<int, float>* monom2 = new TNode<int, float>(100, 10, monom3);
		TNode<int, float>* monom1 = new TNode<int, float>(30, 3, monom2);
		TList<int, float>* by_monom = new TList<int, float>(monom1);
		TPolinom create_by_monom(by_monom);
		cout << create_by_monom << endl;

		string str1 = "5x^3 + 12y^3 - 21z^3 + 10y^4z^1";
		TPolinom stringPolinom1(str1);
		cout << "����������� 1: " << stringPolinom1 << endl;

		TPolinom copyPolinom(create_by_monom);
		cout << "����������� 2: " << copyPolinom << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------�������������--------------------------" << endl;
		TPolinom s1("5x^3 + 12x^2y^3 - 21x^1y^2z^3 - 7z^2x^1");
		cout << s1 << endl;
		cout << "���������� ������� � �������:"<< endl;
		TPolinom new_pol = s1;
		cout << "����� �����:" << new_pol << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------��������--------------------------" << endl;
		TPolinom polinom1("5x^2 + 15y^2z^3");
		TPolinom polinom2("10z^2 - 8y^2z^3");
		cout << "���������� "<< polinom1 << " c " << polinom2 << endl;
		TPolinom sum = polinom1 + polinom2;
		cout << "���������:" << sum << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------���������--------------------------" << endl;
		TPolinom polinom1("5x^2 + 15y^2z^3");
		TPolinom polinom2("10z^2 - 8y^2z^3");
		cout << "�������� ��: " << polinom1 << " -> " << polinom2 << endl;
		TPolinom rez = polinom1 - polinom2;
		cout << "���������:" << rez << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------���������--------------------------" << endl;
		TPolinom polinom1("5x^2 + 15y^2z^3 + 6x^2y^2z^2");
		TPolinom polinom2("10z^2 - 8y^2z^4");
		cout << "������� " << polinom1 << " �� " << polinom2 << endl;
		TPolinom rez2 = polinom1 * polinom2;
		cout << "���������:" << rez2 << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------���������--------------------------" << endl;
		TPolinom polinom1("5x^2 + 15y^2z^3 + 6x^2y^2z^2");
		TPolinom polinom2("10z^2 - 8y^2z^4");
		TPolinom polinom3("10z^2 - 8y^2z^4");
		cout << "��������� " << polinom1 << " � " << polinom2 << endl;
		cout << "���������:" << (polinom1 == polinom2) << endl;
		cout << "��������� " << polinom3 << " � " << polinom2 << endl;
		cout << "���������:" << (polinom3 == polinom2) << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}
	cin >> c;


}