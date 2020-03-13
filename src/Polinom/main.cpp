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
		cout << "--------------------------ÑÎÇÄÀÍÈÅ--------------------------" << endl;
		TNode<int, float>* monom3 = new TNode<int, float>(123, 5);
		TNode<int, float>* monom2 = new TNode<int, float>(100, 10, monom3);
		TNode<int, float>* monom1 = new TNode<int, float>(30, 3, monom2);
		TList<int, float>* by_monom = new TList<int, float>(monom1);
		TPolinom create_by_monom(by_monom);
		cout << create_by_monom << endl;

		string str1 = "5x^3 + 12y^3 - 21z^3 + 10y^4z^1";
		TPolinom stringPolinom1(str1);
		cout << "ÊÎÏÈÐÎÂÀÍÈÅ 1: " << stringPolinom1 << endl;

		TPolinom copyPolinom(create_by_monom);
		cout << "ÊÎÏÈÐÎÂÀÍÈÅ 2: " << copyPolinom << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------ÏÐÈÐÀÂÍÈÂÀÍÈÅ--------------------------" << endl;
		TPolinom s1("5x^3 + 12x^2y^3 - 21x^1y^2z^3 - 7z^2x^1");
		cout << s1 << endl;
		cout << "Ïðèðàâíÿëè ïîëèíîì ê äðóãîìó:"<< endl;
		TPolinom new_pol = s1;
		cout << "Íîâûé ðàâåí:" << new_pol << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------ÑËÎÆÅÍÈÅ--------------------------" << endl;
		TPolinom polinom1("-2 +5x^2y + z -yz +x^2yz");
		TPolinom polinom2("2+y -2z +x^2y");
		cout << "ñêëàäûâàåì "<< polinom1 << " c " << polinom2 << endl;
		TPolinom sum = polinom1 + polinom2;
		cout << "ðåçóëüòàò:" << sum << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------ÂÛ×ÈÒÀÍÈÅ--------------------------" << endl;
		TPolinom polinom1("-2 +5x^2y + z -yz +x^2yz");
		TPolinom polinom2("2+y -2z +x^2y");
		cout << "âû÷èòàåì èç: " << polinom1 << " -> " << polinom2 << endl;
		TPolinom rez = polinom1 - polinom2;
		cout << "ðåçóëüòàò:" << rez << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------ÓÌÍÎÆÅÍÈÅ--------------------------" << endl;
		TPolinom polinom1("-2 +5x^2y + z -yz +x^2yz");
		TPolinom polinom2("2+y -2z +x^2y");
		cout << "óìíîæèì " << polinom1 << " íà " << polinom2 << endl;
		TPolinom rez2 = polinom1 * polinom2;
		cout << "ðåçóëüòàò:" << rez2 << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	try{
		cout << "--------------------------ÐÀÂÅÍÑÒÂÎ--------------------------" << endl;
		TPolinom polinom1("5x^2 + 15y^2z^3 + 6x^2y^2z^2");
		TPolinom polinom2("10z^2 - 8y^2z^4");
		TPolinom polinom3("10z^2 - 8y^2z^4");
		cout << "ðàâåíñòâî " << polinom1 << " è " << polinom2 << endl;
		cout << "ðåçóëüòàò:" << (polinom1 == polinom2) << endl;
		cout << "ðàâåíñòâî " << polinom3 << " è " << polinom2 << endl;
		cout << "ðåçóëüòàò:" << (polinom3 == polinom2) << endl;
	}
	catch (Exception ex){
		cout << ex.what() << endl << endl;
	}

	cout << "--------------------------ÑÎÇÄÀÍÈÅ ÂÀØÅÃÎ ÏÎËÈÍÎÌÀ--------------------------" << endl;
	string your_string1;
	string your_string2;
	cout << "Ââåäèòå 1ûé ïîëèíîì: " << endl;
	getline(cin, your_string1);
	cout << "Ââåäèòå 2îé ïîëèíîì: " << endl;
	getline(cin, your_string2);
	TPolinom your_polinom1(your_string1);
	TPolinom your_polinom2(your_string2);

	cout << "1ûé ïîëèíîì: " << your_polinom1 << endl;
	cout << "2îé ïîëèíîì: " << your_polinom2 << endl;

	try {
		cout << "--------------------------ÏÐÈÐÀÂÍÈÂÀÍÈÅ--------------------------" << endl;
		cout << your_polinom1 << endl;
		cout << "Ïðèðàâíÿëè ïîëèíîì ê äðóãîìó:" << endl;
		TPolinom new_pol = your_polinom1;
		cout << "Íîâûé ðàâåí:" << new_pol << endl;
	}
	catch (Exception ex) {
		cout << ex.what() << endl << endl;
	}

	try {
		cout << "--------------------------ÑËÎÆÅÍÈÅ--------------------------" << endl;
		cout << "ñêëàäûâàåì " << your_polinom1 << " c " << your_polinom2 << endl;
		TPolinom sum = your_polinom1 + your_polinom2;
		cout << "ðåçóëüòàò:" << sum << endl;
	}
	catch (Exception ex) {
		cout << ex.what() << endl << endl;
	}

	try {
		cout << "--------------------------ÂÛ×ÈÒÀÍÈÅ--------------------------" << endl;
		cout << "âû÷èòàåì èç: " << your_polinom1 << " -> " << your_polinom2 << endl;
		TPolinom rez = your_polinom1 - your_polinom2;
		cout << "ðåçóëüòàò:" << rez << endl;
	}
	catch (Exception ex) {
		cout << ex.what() << endl << endl;
	}

	try {
		cout << "--------------------------ÓÌÍÎÆÅÍÈÅ--------------------------" << endl;
		cout << "óìíîæèì " << your_polinom1 << " íà " << your_polinom2 << endl;
		TPolinom rez2 = your_polinom1 * your_polinom2;
		cout << "ðåçóëüòàò:" << rez2 << endl;
	}
	catch (Exception ex) {
		cout << ex.what() << endl << endl;
	}

	try {
		cout << "--------------------------ÐÀÂÅÍÑÒÂÎ--------------------------" << endl;
		cout << "ðàâåíñòâî " << your_polinom1 << " è " << your_polinom2 << endl;
		cout << "ðåçóëüòàò:" << (your_polinom1 == your_polinom2) << endl;
	}
	catch (Exception ex) {
		cout << ex.what() << endl << endl;
	}
	cin >> c;


}