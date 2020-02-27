#ifndef _TPOLINOM_H_
#define _TPOLINOM_H_

#include <cstring>
#include <iostream>
#include "TListP.h"
#include "TNodeP.h"
#include "exceptions.h"

using namespace std;

class TPolinom{
private:
	TList<int, float>* monoms;
	void CastToDefault();
public:
	TPolinom();
	TPolinom(const string&);
	TPolinom(TList<int, float>*);
	TPolinom(const TPolinom&);
	~TPolinom();

	const TPolinom& operator=(const TPolinom&);
	TPolinom operator+(const TPolinom&);
	TPolinom operator-(const TPolinom&);
	TPolinom operator*(const TPolinom&);
	TPolinom operator-();
	bool operator==(const TPolinom&) const;
	bool operator!=(const TPolinom&) const;
	friend ostream& operator<<(ostream&, TPolinom&);
};

TPolinom::TPolinom(){//конструктор
	monoms = new TList<int, float>();
};

TPolinom::TPolinom(const string& st){
	if (!st.length())
		throw Exception("строка пуста");

	monoms = new TList<int, float>;
	int kol = 0;
	bool minus = false; 

	while (kol < st.length()){
		float cofficient = 0;
		int degree = 0;
		bool point = false; 
		bool degree_flag = false;
		bool cofficient_flag = true; 
		bool x_flag = false; 
		bool y_flag = false; 
		bool z_flag = false; 
		
		while (!((static_cast<char>(st[kol]) =='+')|| (static_cast<char>(st[kol]) == '-')) && (kol < st.length())){
			char symbol = static_cast<char>(st[kol]);
			if (symbol == ' '){
				kol++;
				continue;
			}
			if (symbol == '.'){
				point = true;
				kol++;
				continue;
			}
			if (isdigit(symbol) && cofficient_flag && !point && !degree_flag){
				cofficient = cofficient * 10 + static_cast<int>(symbol) - 48;
				kol++;
				continue;
			}
			if (isdigit(symbol) && cofficient_flag && point && !degree_flag){
				int cofficient_int = static_cast<int>(cofficient);
				float cofficient_float = cofficient;
				float ex = (static_cast<int>(symbol) - 48) / 10.;//берем десятичную часть
				while (cofficient_int != cofficient_float){
					ex /= 10.;
					cofficient_float *= 10.;
					cofficient_int = static_cast<int>(cofficient_float);
				}
				cofficient = cofficient + ex;
				kol++;
				continue;
			}

			if (symbol == 'x'){
				x_flag = true;
				y_flag = false;
				z_flag = false;
				degree_flag = false;
				cofficient_flag = false;
				point = false;
				kol++;
				continue;
			}
			if (symbol == 'y'){
				x_flag = false;
				y_flag = true;
				z_flag = false;
				degree_flag = false;
				cofficient_flag = false;
				point = false;
				kol++;
				continue;
			}
			if (symbol == 'z'){
				x_flag = false;
				y_flag = false;
				z_flag = true;
				degree_flag = false;
				cofficient_flag = false;
				point = false;
				kol++;
				continue;
			}

			if (symbol == '^'){
				if (!(x_flag || y_flag || z_flag)) {
					throw Exception("вы забыли ввести перменную x, y или z");
				}
				degree_flag = true;
				kol++;
				continue;
			}

			if (degree_flag){
				if (!(x_flag || y_flag || z_flag)) {
					throw Exception("вы забыли ввести перменную x, y или z");
				}
				if (x_flag) {
					degree = degree + (static_cast<int>(symbol) - 48) * 100;
				}
				if (y_flag) {
					degree = degree + (static_cast<int>(symbol) - 48) * 10;
				}
				if (z_flag) {
					degree = degree + (static_cast<int>(symbol) - 48);
				}
				x_flag = false;
				y_flag = false;
				z_flag = false;
				degree_flag = false;
				kol++;
				continue;
			}
			throw Exception("Некорректный ввод строки");
		}

		if (minus && (cofficient != 0))
			monoms->PushEnd(degree, -(cofficient));
		if (!minus && (cofficient != 0))
			monoms->PushEnd(degree, cofficient);
		if (static_cast<char>(st[kol]) == '-') {
			minus = true;
		}
		else {
			minus = false;
		}
		kol++;
	}

	this->CastToDefault();
};

TPolinom::TPolinom(TList<int, float>* monms){
	while (!monms->End()){
		if (monms->GetpCurrent()->key > 999)
			throw Exception("Степень слишком большая, введите поменьше:)");
		monms->Next();
	}
	monoms = new TList<int, float>(*monms);
	this->CastToDefault();
};

TPolinom::TPolinom(const TPolinom& cop){
	monoms = new TList<int, float>(*cop.monoms);
};

TPolinom::~TPolinom(){//деструктор
	delete monoms;
};


void TPolinom::CastToDefault(){
	if (!monoms->GetpFirst())
		throw Exception("Полином пуст:(");
	monoms->Reset();
	monoms->Sort();
	while (!monoms->End()){
		TNode<int, float>* tmpPrev = monoms->GetpFirst();
		while (tmpPrev->key != monoms->GetpCurrent()->key) {
			tmpPrev = tmpPrev->pNext;		
		}
		if (tmpPrev == monoms->GetpCurrent()){
			monoms->Next();
			continue;
		}
		monoms->GetpCurrent()->data += tmpPrev->data;
		monoms->Remove(tmpPrev->key);
		monoms->Next();
	}

};

//-------------------------------------------ПЕРЕГРУЗКИ------------------------------------------//
const TPolinom& TPolinom::operator=(const TPolinom& cop){
	if (*this == cop)
		return *this;
	if (monoms->GetpFirst())
		delete monoms;
	monoms = new TList<int, float>(*cop.monoms);
	return *this;
};

TPolinom TPolinom::operator+(const TPolinom& cop){
	TPolinom tmp(*this);
	cop.monoms->Reset();

	while (!cop.monoms->End()){
		tmp.monoms->Reset();
		while (!(tmp.monoms->End()) && (tmp.monoms->GetpCurrent()->key <= cop.monoms->GetpCurrent()->key)) {
			tmp.monoms->Next();
		}

		if (!tmp.monoms->GetpCurrent()){//если мы не дошли до конца
			tmp.monoms->PushEnd(cop.monoms->GetpCurrent()->key, cop.monoms->GetpCurrent()->data);
			cop.monoms->Next();
			continue;
		}
		//
		if ((tmp.monoms->GetpCurrent()->data + cop.monoms->GetpCurrent()->data) != 0) {
				tmp.monoms->PushBefore(tmp.monoms->GetpCurrent()->key, cop.monoms->GetpCurrent()->key, cop.monoms->GetpCurrent()->data);
		}

		cop.monoms->Next();
	}

	return tmp;
};

TPolinom TPolinom::operator-(const TPolinom& cop){
	TPolinom tmp(cop);
	return *this + (-tmp);
};

TPolinom TPolinom::operator*(const TPolinom& tmp){
	TPolinom res;

	monoms->Reset();
	while (!monoms->End()){
		tmp.monoms->Reset();
		while (!tmp.monoms->End()){
			TNode<int, float>* _res;
			_res = *tmp.monoms->GetpCurrent() * *monoms->GetpCurrent();
			res.monoms->PushEnd(_res->key, _res->data);
			tmp.monoms->Next();
		}
		monoms->Next();
	}

	this->monoms->Reset();
	tmp.monoms->Reset();
	res.monoms->Reset();
	res.CastToDefault();
	return res;

};

TPolinom TPolinom::operator-(){
	TPolinom tmp(*this);
	while (!tmp.monoms->End()){
		*tmp.monoms->GetpCurrent() = - *tmp.monoms->GetpCurrent();
		tmp.monoms->Next();
	}

	tmp.monoms->Reset();
	return tmp;
};

bool TPolinom::operator==(const TPolinom& cop) const{
	return(*(this->monoms) == *(cop.monoms));
};

bool TPolinom::operator!=(const TPolinom& cop) const{
	return(*(this->monoms) != *(cop.monoms));
};

ostream& operator<<(ostream& _out, TPolinom& _p){
	_p.monoms->Reset();

	if (_p.monoms->End()){
		_out << "Полином пуст :(" << endl;
		return _out;
	}

	_out << _p.monoms->GetpCurrent()->data;

	if (_p.monoms->GetpCurrent()->key / 100 != 0)
		_out << "x^(" << int(_p.monoms->GetpCurrent()->key / 100) << ")";
	if (((int)_p.monoms->GetpCurrent()->key / 10) % 10 != 0)
		_out << "y^(" << int(((int)_p.monoms->GetpCurrent()->key / 10) % 10) << ")";
	if ((int)_p.monoms->GetpCurrent()->key % 10 != 0)
		_out << "z^(" << int((int)_p.monoms->GetpCurrent()->key % 10) << ")";

	_p.monoms->Next();

	while (!_p.monoms->End()){
		if (_p.monoms->GetpCurrent()->data > 0)
			_out << " + " << _p.monoms->GetpCurrent()->data;
		if (_p.monoms->GetpCurrent()->data < 0)
			_out << " - " << abs(_p.monoms->GetpCurrent()->data);

		if (_p.monoms->GetpCurrent()->key / 100 != 0)
			_out << "x^(" << int(_p.monoms->GetpCurrent()->key / 100) << ")";
		if (((int)_p.monoms->GetpCurrent()->key / 10) % 10 != 0)
			_out << "y^(" << int(((int)_p.monoms->GetpCurrent()->key / 10) % 10) << ")";
		if ((int)_p.monoms->GetpCurrent()->key % 10 != 0)
			_out << "z^(" << int((int)_p.monoms->GetpCurrent()->key % 10) << ")";

		_p.monoms->Next();
	}

	_out << endl;
	return _out;
};

#endif