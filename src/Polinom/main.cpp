#include "TPolinom.h"
#include "TListP.h"
#include "exceptions.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void main(){
    setlocale(LC_ALL, "Rus");
    char c;
    try{
        cout << "--------------------------СОЗДАНИЕ--------------------------" << endl;
        TNode<int, float>* monom3 = new TNode<int, float>(123, 5);
        TNode<int, float>* monom2 = new TNode<int, float>(100, 10, monom3);
        TNode<int, float>* monom1 = new TNode<int, float>(30, 3, monom2);
        TList<int, float>* by_monom = new TList<int, float>(monom1);
        TPolinom create_by_monom(by_monom);
        cout << create_by_monom << endl;

        string str1 = "5x^3 + 12y^3 - 21z^3 + 10y^4z^1";
        TPolinom stringPolinom1(str1);
        cout << "КОПИРОВАНИЕ 1: " << stringPolinom1 << endl;

        TPolinom copyPolinom(create_by_monom);
        cout << "КОПИРОВАНИЕ 2: " << copyPolinom << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }

    try{
        cout << "--------------------------ПРИРАВНИВАНИЕ--------------------------" << endl;
        TPolinom s1("5x^3 + 12x^2y^3 - 21x^1y^2z^3 - 7z^2x^1");
        cout << s1 << endl;
        cout << "Приравняли полином к другому:"<< endl;
        TPolinom new_pol = s1;
        cout << "Новый равен:" << new_pol << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }

    try{
        cout << "--------------------------СЛОЖЕНИЕ--------------------------" << endl;
        TPolinom polinom1("-2 +5x^2y + z -yz +x^2yz");
        TPolinom polinom2("2+y -2z +x^2y");
        cout << "складываем "<< polinom1 << " c " << polinom2 << endl;
        TPolinom sum = polinom1 + polinom2;
        cout << "результат:" << sum << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }

    try{
        cout << "--------------------------ВЫЧИТАНИЕ--------------------------" << endl;
        TPolinom polinom1("-2 +5x^2y + z -yz +x^2yz");
        TPolinom polinom2("2+y -2z +x^2y");
        cout << "вычитаем из: " << polinom1 << " -> " << polinom2 << endl;
        TPolinom rez = polinom1 - polinom2;
        cout << "результат:" << rez << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }

    try{
        cout << "--------------------------УМНОЖЕНИЕ--------------------------" << endl;
        TPolinom polinom1("-2 +5x^2y + z -yz +x^2yz");
        TPolinom polinom2("2+y -2z +x^2y");
        cout << "умножим " << polinom1 << " на " << polinom2 << endl;
        TPolinom rez2 = polinom1 * polinom2;
        cout << "результат:" << rez2 << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }

    try{
        cout << "--------------------------РАВЕНСТВО--------------------------" << endl;
        TPolinom polinom1("5x^2 + 15y^2z^3 + 6x^2y^2z^2");
        TPolinom polinom2("10z^2 - 8y^2z^4");
        TPolinom polinom3("10z^2 - 8y^2z^4");
        cout << "равенство " << polinom1 << " и " << polinom2 << endl;
        cout << "результат:" << (polinom1 == polinom2) << endl;
        cout << "равенство " << polinom3 << " и " << polinom2 << endl;
        cout << "результат:" << (polinom3 == polinom2) << endl;
    }
    catch (Exception ex){
        cout << ex.what() << endl << endl;
    }

    cout << "--------------------------СОЗДАНИЕ ВАШЕГО ПОЛИНОМА--------------------------" << endl;
    string your_string1;
    string your_string2;
    cout << "Введите 1ый полином: " << endl;
    getline(cin, your_string1);
    cout << "Введите 2ой полином: " << endl;
    getline(cin, your_string2);
    TPolinom your_polinom1(your_string1);
    TPolinom your_polinom2(your_string2);

    cout << "1ый полином: " << your_polinom1 << endl;
    cout << "2ой полином: " << your_polinom2 << endl;

    try {
        cout << "--------------------------ПРИРАВНИВАНИЕ--------------------------" << endl;
        cout << your_polinom1 << endl;
        cout << "Приравняли полином к другому:" << endl;
        TPolinom new_pol = your_polinom1;
        cout << "Новый равен:" << new_pol << endl;
    }
    catch (Exception ex) {
        cout << ex.what() << endl << endl;
    }

    try {
        cout << "--------------------------СЛОЖЕНИЕ--------------------------" << endl;
        cout << "складываем " << your_polinom1 << " c " << your_polinom2 << endl;
        TPolinom sum = your_polinom1 + your_polinom2;
        cout << "результат:" << sum << endl;
    }
    catch (Exception ex) {
        cout << ex.what() << endl << endl;
    }

    try {
        cout << "--------------------------ВЫЧИТАНИЕ--------------------------" << endl;
        cout << "вычитаем из: " << your_polinom1 << " -> " << your_polinom2 << endl;
        TPolinom rez = your_polinom1 - your_polinom2;
        cout << "результат:" << rez << endl;
    }
    catch (Exception ex) {
        cout << ex.what() << endl << endl;
    }

    try {
        cout << "--------------------------УМНОЖЕНИЕ--------------------------" << endl;
        cout << "умножим " << your_polinom1 << " на " << your_polinom2 << endl;
        TPolinom rez2 = your_polinom1 * your_polinom2;
        cout << "результат:" << rez2 << endl;
    }
    catch (Exception ex) {
        cout << ex.what() << endl << endl;
    }

    try {
        cout << "--------------------------РАВЕНСТВО--------------------------" << endl;
        cout << "равенство " << your_polinom1 << " и " << your_polinom2 << endl;
        cout << "результат:" << (your_polinom1 == your_polinom2) << endl;
    }
    catch (Exception ex) {
        cout << ex.what() << endl << endl;
    }
    cin >> c;


}