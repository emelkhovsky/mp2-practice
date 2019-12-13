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
	cout << "Введите выражение" << endl;
	getline(cin, expression);
	try {
		cout << "Введите 1, если хотите выбрать способ со списками, введите 0, если хотите выбрать способ с массивами" << endl;
		int choice;
		cin >> choice;
		if (choice == 0) {
			TCalculator<double> postfix(AStack);	
			string p_f = postfix.PostfixForm(expression);
			cout << "Постфиксная форма равна:" << endl;
			cout << p_f << endl;
			int count = 0;
			char* operands = new char[p_f.length()];
			double* values = new double[p_f.length()];
			postfix.GettingOperands(p_f, operands, values, count);
			cout << "Количество неповторяющихся операндов:" << count << endl;
			double result =postfix.Calculate(values, operands, p_f, count);
			cout << "Ваш результат: " << result << endl;
		}
		else {
			TCalculator<double> postfix(LStack);
			string p_f = postfix.PostfixForm(expression);
			cout << "Постфиксная форма равна:" << endl;
			cout << p_f << endl;
			int count = 0;
			char* operands = new char[p_f.length()];
			double* values = new double[p_f.length()];
			postfix.GettingOperands(p_f, operands, values, count);
			cout << "Количество неповторяющихся операндов:" << count << endl;
			double result = postfix.Calculate(values, operands, p_f, count);
			cout << "Ваш результат: " << result << endl;
		}

	}
	catch (const Exception& ex) {
		cout << ex.what() << endl << endl;
	}
	system("pause");
}