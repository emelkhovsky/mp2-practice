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
        int count = TCalculator::GettingCount(p_f);
        cout << "Количество неповторяющихся операндов:" << count << endl;//(вот до этого момента все супер)
		double* values = new double[count];
		TCalculator::GettingValues(values, operands, p_f, count);
		double result = TCalculator::Calculate(values, operands, p_f);
		cout << "Ваш результат: " << result << endl;
    }
    catch (const Exception& ex){
        cout << ex.what() << endl << endl;
    }
    system("pause");
}
