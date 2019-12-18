#include <iostream>
#include <string>
#include "TListstack.h"
#include "TArrayStack.h"
#include "TList.h"
#include "TStack.h"
#include "exceptions.h"
using namespace std;

template<class ValType>
class TCalculator {
private:
	TStack<char>* Operands;
	TStack<char>* Operations;
	TStack<ValType>* Values;
	int Priority(const char);//определение приоретета операций+
	bool IsItOperation(const char);//определение операци¤ это или нет+
public:
	TCalculator(TypeStack);
	string PostfixForm(string);//образование постфиксной формы
	double Calculate(double*, char*, string, int);//возвращает результат подсчета
	void GettingOperands(string, char*&, double*&, int&);
};

template<class ValType>//конструктор
TCalculator<ValType>::TCalculator(TypeStack type){
	Operands = TStack<char>::Create(type);
	Operations = TStack<char>::Create(type);
	Values = TStack<double>::Create(type);
}
//определение приоретета операций
template<class ValType>
int TCalculator<ValType>::Priority(const char sign) {//done
	switch (sign) {
	case '(':
		return 1;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		throw Exception("Некорректно введенный символ\n");
	}
}

//определение операци¤ это или нет done
template<class ValType>
bool TCalculator<ValType>::IsItOperation(const char sign) {
	return ((sign == '*') || (sign == '/') || (sign == '+') || (sign == '-') || (sign == ')') || (sign == '('));
}

template<class ValType>
void TCalculator<ValType>::GettingOperands(string p_f, char*& operands, double*& values, int& count) {
	int current_count_of_operands = 0;
	double value = 0;
	char* new_operands = new char[p_f.length()];
	double* new_values = new double[p_f.length()];
	for (int i = 0; i < p_f.length(); i++) {
		if (isalpha(p_f[i])) {
			int flag = 0;
			for (int j = 0; j < current_count_of_operands; j++) {
				if (new_operands[j] == p_f[i]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				new_operands[current_count_of_operands] = p_f[i];
				cout << "введите значение операнда " << p_f[i] << endl;
				cin >> value;
				new_values[current_count_of_operands] = value;
				current_count_of_operands++;
			}
		}
	}
	count = current_count_of_operands;
	memcpy(values, new_values, sizeof(double) * count);//скопировали 2ое в 1ое
	memcpy(operands, new_operands, sizeof(char) * count);//скопировали 2ое в 1ое
}


//образование постфиксной формы
template<class ValType>
string TCalculator<ValType>::PostfixForm(string exp) {
	if (exp.length() == 0) {
		throw Exception("Ќекорректно введенна¤ строка\n");
	}
	int countOfLeftBrackets = 0;
	int countOfRightBrackets = 0;
	for (int i = 0; i < exp.length(); i++) {
		char sign = static_cast<char>(exp[i]);
		cout << sign << endl;
		if (sign == ' ') {
			continue;
		}
		if (IsItOperation(sign)) {
			if (sign == '(') {
				Operations->Push(sign);
				countOfLeftBrackets++;
				continue;
			}
			if (sign == ')') {
				countOfRightBrackets++;
				while (!Operations->IsEmpty()) {
					if (Operations->Pop_Get() != '(') {
						Operands->Push(Operations->Pop_Get());
						Operations->Pop();
						continue;
					}
					Operations->Pop();
					break;
				}
				continue;
			}
			if ((Operations->IsEmpty()) || (Priority(sign) > Priority(Operations->Pop_Get()))) {
				Operations->Push(sign);
				continue;
			}

			while ((!Operations->IsEmpty()) && (Priority(sign) <= Priority(Operations->Pop_Get()))) {
				Operands->Push(Operations->Pop_Get());
				Operations->Pop();
			}
			Operations->Push(sign);
			continue;
		}
		if (isalpha(sign)) {
			Operands->Push(sign);
			continue;
		}
		throw Exception("некорректные символы");
	}

	if (countOfLeftBrackets != countOfRightBrackets) {
		if (countOfLeftBrackets < countOfRightBrackets) {
			throw Exception("вы забыли левую скобку");
		}
		else {
			throw Exception("вы забыли правую скобку");
		}
	}

	while (!Operations->IsEmpty()) {
		Operands->Push(Operations->Pop_Get());
		Operations->Pop();
	}
	string postfix_form;

	while (!Operands->IsEmpty()) {
		postfix_form += Operands->Pop_Get();
		Operands->Pop();
	}

	for (int i = 0; i < postfix_form.length() / 2; i++)
		swap(postfix_form[i], postfix_form[postfix_form.length() - 1 - i]);

	return postfix_form;
}

//подсчет
template<class ValType>
double TCalculator<ValType>::Calculate(double* values, char* operands, string p_f, int count){
	for (int i = 0; i < p_f.length(); i++) {
		char sign = static_cast<char>(p_f[i]);
		if (isalpha(sign)) {
			for (int j = 0; j < count; j++) {
				if (operands[j] == sign) {
					Values->Push(values[j]);
					break;
				}
			}
			continue;
		}

		double first = Values->Pop_Get();
		Values->Pop();
		double second = Values->Pop_Get();
		Values->Pop();
		double result;

		switch (sign) {
		case '+':
			result = second + first;
			break;
		case '-':
			result = second - first;
			break;
		case '*':
			result = second * first;
			break;
		case '/':
			if (first == 0)
				throw Exception("Ќа 0 делить нельз¤:(\n");
			result = second / first;
			break;
		}

		Values->Push(result);
	}
	return Values->Pop_Get();
};
