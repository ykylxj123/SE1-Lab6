// Объявление класса комплексных чисел.
//
// Модуль получен в готовом виде от предыдущего разработчика; здесь
// изменено только оформление (правила 6-7: имена, защита заголовка,
// отсутствие using namespace в заголовке), логика не менялась.
#ifndef COMPLEX_GIT_LAB_MYCOMPLEX_H_
#define COMPLEX_GIT_LAB_MYCOMPLEX_H_

#include <iostream>

class Complex {
    double re_;
    double im_;

public:
    Complex(double re = 0, double im = 0);
    Complex(const Complex&);
    ~Complex();
    void set(double re, double im = 0);
    operator double();
    double abs();

    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, Complex&);

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator+(const double&);
    friend Complex operator+(const double&, const Complex&);
    Complex operator-(const double&);
    friend Complex operator-(const double&, const Complex&);
    Complex operator*(const Complex&);
    Complex operator*(const double&);
    friend Complex operator*(const double&, const Complex&);
    Complex operator/(const double&);

    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator+=(const double&);
    Complex& operator-=(const double&);
    Complex& operator*=(const double&);
    Complex& operator/=(const double&);
    Complex& operator=(const Complex&);
    Complex& operator=(const double&);
};

#endif
