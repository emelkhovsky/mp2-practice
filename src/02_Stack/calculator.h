#include <iostream>
#include <string>
#include "tstack.h"
#include "exceptions.h"
using namespace std;

template <typename ValType>
class TCalculator {
public:
	static int Priority(const char);//определение приоретета операций
	static bool IsItOperation(const char);//определение операция это или нет
	static string PostfixForm(string);//образование постфиксной формы
	static char* GettingOperandsMas(string);//возвращает массив операндов
	static int GettingCount(string);//возвращает кол-во операндов
	static double Calculate(string, double, char, int);//возвращает результат подсчета
	static double* Gettingresulting_mass(string);//ввод значений
};

template<typename ValType>//возвращает кол-во неповторяющих операндов
static int TCalculator<ValType>::GettingCount(string postfix_form) {
	int count = 0;
	char* operands_mas = new char[postfix_form.length() + 1];
	for (int i = 0; i < postfix_form.length(); i++) {
		char sign = static_cast<char>(postfix_form[i]);
		if ((isalpha(sign))&&(strchr(operands_mas, sign) == NULL)) {
			operands_mas[count] = sign;
			count++;
		}
	}
	return count;
}


template <typename ValType>//возвращает массив операндов
static char* TCalculator<ValType>::GettingOperandsMas(string postfix_form) {
	int kol = 0;
	int count = GettingCount_CreateOperandMas(string postfix_form) + 1;
	char* operands_mas = new char[count];
	for (int i = 0; i < postfix_form.length(); i++) {
		char sign = static_cast<char>(postfix_form[i]);
		if ((isalpha(sign)) && (strchr(operands_mas, sign) == NULL)) {
			operand_mas[kol] = sign;
			kol++;
		}	
	}
	return operands_mas;
}

template<typename ValType>//возвращает кол-во неповторяющих операндов
static double* TCalculator<ValType>::Gettingresulting_mass(string operands_mas) {
	double* operands_resulting_mas = new double[operands_mas.length() + 1];
	for (int i = 0; i < operands_mas.length(); i++) {
		cout << "Введите значение операнда " << operands_mas[i] << ": " << endl;
		cin >> operands_resulting_mas[i];
	}
	return operands_resulting_mas;
}

template <typename ValType>//определение приоретета операций
static int TCalculator<ValType>:: Priority(const char sign) {
	switch (sign) {
	case '(': return 0;
	case ')': return 0;
	case '*': return 1;
	case '/': return 1;
	case '+': return 2;
	case '-': return 2;
	default: throw incorrectsign();
	}
}
template <typename ValType>//определение операция это или нет
static bool TCalculator<ValType>::IsItOperation(const char sign) {
	return ((sign == '(') || (sign == ')') || (sign == '*') || (sign == '/') || (sign == '+') || (sign == '-'));
}

template <typename ValType>//образование постфиксной формы
static string TCalculator<ValType>::PostfixForm(string exp) {
	if (exp.length() == 0) {
		throw incorrectstr();
	}
	TStack<char> stack1(exp.length() + 1);//для операций
	TStack<char> stack2(exp.length() + 1);//для операндов
	for (int i = 0; i < exp.length(); i++) {
		char sign = static_cast<char>(exp[i]);//приведение к чару
		if (sign != ' ') {//пропуск пробела
			if (IsItOperation(sign)) {//если операция

				if (sign == '(') {
					stack1.Push(sign);
					continue;
				}

				if (sign == ')') {
					while (stack1.GettingTopElement() != ')') {
						stack2.Push(stack1.Pop());
					}
					stack1.Pop();
					continue;
				}

				if ((stack1.IsEmpty()) || (Priority(sign) >= Priority(stack1.GettingTopElement()))){
					stack1.Push(sign);
					continue;
				}

				while ((!stack1.IsEmpty()) && (Priority(sign) <= Priority(stack1.GettingTopElement()))) {//ВРОДЕ БЫ СТРОГО <?
					stack2.Push(stack1.Pop());
				}
				stack1.Push(sign);
				continue;
			}
			else  if (isalpha(sign)){//если операнд
				stack2.Push(sign);
				continue;
			}
			else {
				throw incorrectsign();
			}
		}
	}
	while (!stack1.IsEmpty()){//перекидываем все во 2ой
		char pop_element = stack1.Pop();
		stack2.Push(pop_element);
	}
	string postfix_form(stack2.GettingMaxSize(), 0);//в эту строчку закидываем все

	while (!stack2.IsEmpty()){
		postfix_form[stack2.GettingTop() - 1] = stack2.GettingTopElement();
		stack2.Pop();
	}
	return postfix_form;
}

template<typename ValType>//ПЕРЕДЕЛАТЬ ВСЕ
double TCalculator<ValType>::Calculate(string postfix_form, double operands_values, char operands_mas, int count)
{
	double* resulting_mas = new double[postfix_form.length()];
	for (int i = 0; i < postfix_form.length(); i++){
		char sign = static_cast<char>(postfix_form[i]);
		if (!IsItOperation(sign)){
			for (int j = 0; j < count; j++){
				if (operands_mas[j] == sign){
					resulting_mas.Push(static_cast<double>(operands_value[j]);
					break;
				}
			}
			continue;
		}

		double first = resulting_mas.Pop();
		double second = resulting_mas.Pop();

		switch (sign){
		case '+':
			double result = second + first;
			break;
		case '-':
			double result = second - first;
			break;
		case '*':
			double result = second * first;
			break;
		case '/':
			if (first == 0)
				throw zeroerror();
			double result = second / first;
			break;
		}

		resulting_mas.Push(result);
	}
	return resulting_mas.Pop();
};

