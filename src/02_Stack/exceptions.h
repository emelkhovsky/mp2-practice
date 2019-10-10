#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class incorrect_max_size : public std::exception {
	const std::string what_Str = "������������ ������������ ������ �����\n";
public:
	const char* what() const {
		return what_Str.c_str();
	}
};

class empty : public std::exception {
	const std::string what_Str = "���� ����\n";
public:
	const char* what() const {
		return what_Str.c_str();
	}
};

class full : public std::exception {
	const std::string what_Str = "���� �����\n";
public:
	const char* what() const {
		return what_Str.c_str();
	}
};

class incorrectsign : public std::exception {
	const std::string what_Str = "������������ ����\n";
public:
	const char* what() const {
		return what_Str.c_str();
	}
};

class incorrectstr : public std::exception {
	const std::string what_Str = "����������� ��������� ������\n";
public:
	const char* what() const {
		return what_Str.c_str();
	}
};

#endif