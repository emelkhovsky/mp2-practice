#include <iostream>
#include <string>
#include "calculator.h"
#include "TStack.h"
#include "exceptions.h"
using namespace std;

void main() {
    string expression;
    setlocale(LC_ALL, "Rus");
    try {
        cout << "Введите выражение" << endl;
        getline(cin, expression);
        string p_f = TCalculator<double>::PostfixForm(expression);
        cout << "Постфиксная форма равна:" << endl;
        cout << p_f << endl;
        int count = TCalculator<double>::GettingCount(p_f);
        cout << "Количество неповторяющихся операндов:" << count << endl;
        char* operands_mas = TCalculator<double>::GettingOperandsMas(p_f);//массив с операндами
        double* operands_values = TCalculator<double>::Gettingresulting_mass(operands_mas, count);//массив со значениями
        double result = TCalculator<double>::Calculate(p_f, operands_values, operands_mas, count);//результат
        cout << "Ваш результат: " << result << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }
    system("pause");
}
