#include <iostream>
#include <string>
#include "tstack.h"
#include "exceptions.h"
using namespace std;

class TCalculator {
private:
	static int Priority(const char);//определение приоретета операций
	static bool Comparison(char, TStack<char>&);//сравнение приоритетов
	static bool IsItOperation(const char);//определение операция это или нет
public: 
    static string PostfixForm(string);//образование постфиксной формы
	static double Calculate(double*, char*, string, int);//возвращает результат подсчета
	static void GettingOperands(string, char*&, double*&, int&);
};

//определение приоретета операций
 int TCalculator:: Priority(const char sign) {
    switch (sign) {
    case '+': return 2;
    case '-': return 2;
    case '*': return 1;
    case '/': return 1;
    default: return 3;
    }
}
 bool TCalculator::Comparison(char exp, TStack<char>& pop_el){//сравнение приоритетов 
	 return (Priority(pop_el.Pop_Get()) < Priority(exp));

 };
//определение операция это или нет
 bool TCalculator::IsItOperation(const char sign) {
    return ((sign == '*') || (sign == '/') || (sign == '+') || (sign == '-'));
}

 void TCalculator::GettingOperands(string p_f, char*& operands, double*& values, int& count) {
	 int current_count_of_operands = 0;
	 double value = 0;
	 char* new_operands = new char[count];
	 double* new_values = new double[count];
	 for (int i = 0; i < p_f.length(); i++) {
		 if (isalpha(p_f[i])) {
			 count++;
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
 string TCalculator::PostfixForm(string exp) {
    if (exp.length() == 0) {
        throw Exception("Некорректно введенная строка\n");
    }
    TStack<char> stack1(exp.length() + 1);//операции
    TStack<char> stack2(exp.length() + 1);//операнды
    for (int i = 0; i < exp.length(); i++) {
        char sign = static_cast<char>(exp[i]);
		if (sign == ' ') {
			continue;
		}
		if (IsItOperation(sign)) {
			if (stack1.IsEmpty()) {//если в стеке опраций еще ничего нет 
				stack1.Push(sign);
				continue;
			}
			if (Comparison(sign, stack1)) {//битва за приоритет
				while (!stack1.IsEmpty()) {
					stack2.Push(stack1.Pop_Get());
					stack1.Pop();
				}
				stack1.Push(sign);
			}
			else
				stack1.Push(sign);
		}

		if (sign == '(') {
			stack1.Push(sign);
		}
		if (isalpha(sign)) {
			stack2.Push(sign);
		}
		if (sign == ')') {
			int left_bracket_flag = 0;
			while (!stack1.IsEmpty()) {
				if (stack1.Pop_Get() != '(') {
					cout << stack1.Pop_Get() << endl;
					stack2.Push(stack1.Pop_Get());
					stack1.Pop();
					continue;
				}
				stack1.Pop();
				left_bracket_flag = 1;
				break;
			}
			if ((left_bracket_flag != 1) && (stack1.IsEmpty())) {
				throw Exception(" Кажется, вы забыли скобку (\n");
			}
		}

    }
    while (!stack1.IsEmpty()){
        stack2.Push(stack1.Pop_Get());
        stack1.Pop();
    }
    string postfix_form;

	while (!stack2.IsEmpty()){
		postfix_form += stack2.Pop_Get();
		stack2.Pop();
	}

	for (int i = 0; i < postfix_form.length() / 2; i++)
		swap(postfix_form[i], postfix_form[postfix_form.length() - 1 - i]);

    return postfix_form;
}

//подсчет
double TCalculator::Calculate(double* values, char* operands, string p_f, int count)
{    
    TStack<double> resulting_mas(p_f.length());
    for (int i = 0; i < p_f.length(); i++){
        char sign = static_cast<char>(p_f[i]);
        if (isalpha(sign)){
            for (int j = 0; j < count; j++){
                if (operands[j] == sign){
                    resulting_mas.Push(values[j]);
                    break;
                }
            }
            continue;
        }

        double first = resulting_mas.Pop_Get();
        resulting_mas.Pop();
        double second = resulting_mas.Pop_Get();
        resulting_mas.Pop();
        double result;

        switch (sign){
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

        resulting_mas.Push(result);
    }
    return resulting_mas.Pop_Get();
};


