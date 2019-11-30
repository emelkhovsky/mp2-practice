#include <iostream>
#include <string>
#include "calculator.h"
#include "TStack.h"
#include "exceptions.h"
using namespace std;

void main() {
    string expression;
    string operands;
    setlocale(LC_ALL, "Rus");
    try {
        cout << "Введите выражение" << endl;
        getline(cin, expression);
        string p_f = TCalculator::PostfixForm(expression);
        cout << "Постфиксная форма равна:" << endl;
        cout << p_f << endl;
		int count = 0;
		char* operands = new char[p_f.length()];
		double* values = new double[p_f.length()];
		TCalculator::GettingOperands(p_f, operands, values, count);
		cout << "Количество неповторяющихся операндов:" << count << endl;//(вот до этого момента все супер)
		double result = TCalculator::Calculate(values, operands, p_f, count);
		cout << "Ваш результат: " << result << endl;
    }
    catch (const Exception& ex){
        cout << ex.what() << endl << endl;
    }
    system("pause");
}
