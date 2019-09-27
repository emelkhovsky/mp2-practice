#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class vectorsizeerror : public std::exception{
    const std::string what_Str = "размеры векторов не совпадают\n";
public:
    const char* what() const{
        return what_Str.c_str();
    }
};

class matrixsizeerror : public std::exception{
    const std::string what_Str = "размеры матриц не совпадают\n";
public:
    const char* what() const{
        return what_Str.c_str();
    }
};

class vectorincorrectindexerror : public std::exception{
    const std::string what_Str = "неккоректный номер индекса\n";
public:
    const char* what() const{
        return what_Str.c_str();
    }
};

class vectorzerosizeerror : public std::exception {
    const std::string what_Str = "вектор нулевого размера, не могу вывести\n";
public:
    const char* what() const {
        return what_Str.c_str();
    }
};

class matrixzerosizeerror : public std::exception {
    const std::string what_Str = "матрицы нулевого размера, не могу вывести\n";
public:
    const char* what() const {
        return what_Str.c_str();
    }
};

class matrixvectorsizeerror : public std::exception {
    const std::string what_Str = "размерность вектора и матрицы не совпадают, операция не возможна\n";
public:
    const char* what() const {
        return what_Str.c_str();
    }
};

#endif
