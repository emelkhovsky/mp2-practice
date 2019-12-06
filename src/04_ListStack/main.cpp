#include <iostream>
#include <string>
#include "TCalculator.h"
#include "TList.h"
#include "exceptions.h"
using namespace std;

void main() {
	string expression;
	string operands;
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������" << endl;
	getline(cin, expression);
	try {
		cout << "������� 1, ���� ������ ������� ������ �� ��������, ������� 0, ���� ������ ������� ������ � ���������" << endl;
		int choice;
		cin >> choice;
		if (choice == 0) {
			TCalculator<double> postfix(AStack);	
			string p_f = postfix.PostfixForm(expression);
			cout << "����������� ����� �����:" << endl;
			cout << p_f << endl;
			int count = 0;
			char* operands = new char[p_f.length()];
			double* values = new double[p_f.length()];
			postfix.GettingOperands(p_f, operands, values, count);
			cout << "���������� ��������������� ���������:" << count << endl;//(��� �� ����� ������� ��� �����)
			double result =postfix.Calculate(values, operands, p_f, count);
			cout << "��� ���������: " << result << endl;
		}
		else {
			TCalculator<double> postfix(LStack);
			string p_f = postfix.PostfixForm(expression);
			cout << "����������� ����� �����:" << endl;
			cout << p_f << endl;
			int count = 0;
			char* operands = new char[p_f.length()];
			double* values = new double[p_f.length()];
			postfix.GettingOperands(p_f, operands, values, count);
			cout << "���������� ��������������� ���������:" << count << endl;//(��� �� ����� ������� ��� �����)
			double result = postfix.Calculate(values, operands, p_f, count);
			cout << "��� ���������: " << result << endl;
		}

	}
	catch (const Exception& ex) {
		cout << ex.what() << endl << endl;
	}
	system("pause");
}