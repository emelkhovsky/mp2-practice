#include <iostream>
#include <string>
#include "tstack.h"
#include "exceptions.h"
using namespace std;

template <typename ValType>
class TCalculator {
public:
    static int Priority(const char);//определение приоретета операций
    static bool IsItOperation(const char);//определение операци¤ это или нет
    static string PostfixForm(string);//образование постфиксной формы
    static char* GettingOperandsMas(string);//возвращает массив операндов
    static int GettingCount(string);//возвращает кол-во операндов
    static double Calculate(string, double*, char*, int);//возвращает результат подсчета
    static double* Gettingresulting_mass(string, int);//ввод значений
};

template<typename ValType>//возвращает кол-во неповтор¤ющих операндов
 int TCalculator<ValType>::GettingCount(string postfix_form) {
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
 char* TCalculator<ValType>::GettingOperandsMas(string postfix_form) {
    int kol = 0;
    int count = GettingCount(postfix_form) + 1;
    char* operands_mas = new char[count];
    for (int i = 0; i < postfix_form.length(); i++) {
        char sign = static_cast<char>(postfix_form[i]);
        cout << sign << endl;
        if ((isalpha(sign)) && (strchr(operands_mas, sign) == NULL)) {
            operands_mas[kol] = sign;
            kol++;
        }    
    }
    return operands_mas;
}

template<typename ValType>//ввод значений
 double* TCalculator<ValType>::Gettingresulting_mass(string operands_mas, int count) {
    double* operands_resulting_mas = new double[count];
    for (int i = 0; i < count; i++) {
        cout << "введите значение операнда " << operands_mas[i] << ": " << endl;                
        cin >> operands_resulting_mas[i];
    }
    return operands_resulting_mas;
}

template <typename ValType>//определение приоретета операций(done)
 int TCalculator<ValType>:: Priority(const char sign) {
    switch (sign) {
    case '(': return 0;
    case ')': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    default: throw Exception("Ќекорректный знак\n");
    }
}
template <typename ValType>//определение операци¤ это или нет(done)
 bool TCalculator<ValType>::IsItOperation(const char sign) {
    return ((sign == '(') || (sign == ')') || (sign == '*') || (sign == '/') || (sign == '+') || (sign == '-'));
}

template <typename ValType>//образование постфиксной формы
 string TCalculator<ValType>::PostfixForm(string exp) {
    if (exp.length() == 0) {
        throw Exception("Ќекорректно введенна¤ строка\n");
    }
    TStack<char> stack1(exp.length() + 1);
    TStack<char> stack2(exp.length() + 1);
    int bracket_flag = 0;
    for (int i = 0; i < exp.length(); i++) {
        char sign = static_cast<char>(exp[i]);
        if (sign != ' ') {
            if (IsItOperation(sign)) {

                if (sign == '(') {
                    bracket_flag = 1;
                    stack1.Push(sign);
                    continue;
                }

                if (sign == ')') {
                    if (bracket_flag == 0) {
                        throw Exception(" ажетс¤, вы забыли скобку (\n");
                    }
                    while ((!stack1.IsEmpty())&&(stack1.GettingTopElement() != '(')) {
                        stack2.Push(stack1.GettingTopElement());
                        stack1.Pop();
                    }
                    if (stack1.GettingTopElement() == '(') {
                        stack1.Pop();
                    }    
                    else if(stack1.IsEmpty()){
                        throw Exception(" ажетс¤, вы забыли скобку )\n");
                    }
                    continue;
                }

                if ((stack1.IsEmpty()) || (Priority(sign) >= Priority(stack1.GettingTopElement()))){
                    stack1.Push(sign);
                    continue;
                }
                cout << sign << endl;
                while ((!stack1.IsEmpty()) && (Priority(sign) <= Priority(stack1.GettingTopElement()))) {
                    stack2.Push(stack1.GettingTopElement());
                    stack1.Pop();
                }
                stack1.Push(sign);
                continue;
            }
            else  if (isalpha(sign)){
                stack2.Push(sign);
                continue;
            }
            else {
                throw Exception("Ќекорректный знак\n");
            }
        }
    }
    while (!stack1.IsEmpty()){
        stack2.Push(stack1.GettingTopElement());
        stack1.Pop();
    }
    string postfix_form(stack2.GettingMaxSize(), 0);

    while (!stack2.IsEmpty()){
        postfix_form[stack2.GettingTop() - 1] = stack2.GettingTopElement();
        stack2.Pop();
    }
    return postfix_form;
}

template<typename ValType>//подсчет
double TCalculator<ValType>::Calculate(string postfix_form, double* operands_values, char* operands_mas, int count)
{    
    TStack<double> resulting_mas(postfix_form.length());
    for (int i = 0; i < postfix_form.length(); i++){
        char sign = static_cast<char>(postfix_form[i]);
        if (!IsItOperation(sign)){
            for (int j = 0; j < count; j++){
                if (operands_mas[j] == sign){
                    resulting_mas.Push(static_cast<double>(operands_values[j]));
                    break;
                }
            }
            continue;
        }

        double first = resulting_mas.GettingTopElement();
        resulting_mas.Pop();
        double second = resulting_mas.GettingTopElement();
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
                throw Exception("Ќа 0 делить нельз¤:(\n");
            result = second / first;
            break;
        }

        resulting_mas.Push(result);
    }
    return resulting_mas.GettingTopElement();
};


