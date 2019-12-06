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
	bool Comparison(char, TStack<char>&);//сравнение приоритетов+
	bool IsItOperation(const char);//определение операция это или нет+
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
	case '+': return 2;
	case '-': return 2;
	case '*': return 1;
	case '/': return 1;
	default: return 3;
	}
}

template<class ValType>
bool TCalculator<ValType>::Comparison(char exp, TStack<char>& pop_el) {//сравнение приоритетов  done
	return (Priority(pop_el.Pop_Get()) <= Priority(exp));

};
//определение операция это или нет done
template<class ValType>
bool TCalculator<ValType>::IsItOperation(const char sign) {
	return ((sign == '*') || (sign == '/') || (sign == '+') || (sign == '-'));
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
		throw Exception("Некорректно введенная строка\n");
	}
	for (int i = 0; i < exp.length(); i++) {
		char sign = static_cast<char>(exp[i]);
		if (sign == ' ') {
			continue;
		}
		if (IsItOperation(sign)) {
			if (this->Operations->IsEmpty()) {//если в стеке опраций еще ничего нет 
				Operations->Push(sign);
				continue;
			}
			if (Comparison(sign, *Operations)) {//битва за приоритет
				while (Comparison(sign, *Operations)) {
					Operands->Push(Operations->Pop_Get());
					Operations->Pop();
				}
				Operations->Push(sign);
			}
			else
				Operations->Push(sign);
		}

		if (sign == '(') {
			Operations->Push(sign);
		}
		if (isalpha(sign)) {
			Operands->Push(sign);
		}
		if (sign == ')') {
			int left_bracket_flag = 0;
			while (!Operations->IsEmpty()) {
				if (Operations->Pop_Get() != '(') {
					cout << Operations->Pop_Get() << endl;
					Operands->Push(Operations->Pop_Get());
					Operations->Pop();
					continue;
				}
				Operations->Pop();
				left_bracket_flag = 1;
				break;
			}
			if ((left_bracket_flag != 1) && (Operations->IsEmpty())) {
				throw Exception(" Кажется, вы забыли скобку (\n");
			}
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
				throw Exception("На 0 делить нельзя:(\n");
			result = second / first;
			break;
		}

		Values->Push(result);
	}
	return Values->Pop_Get();
};
