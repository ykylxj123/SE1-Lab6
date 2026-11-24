// Объявление класса комплексных чисел.
//
// Модуль получен в готовом виде от предыдущего разработчика и приведён
// к соглашению курса. Стадия А (правила 1-7): UTF-8 и LF, отступ 4 пробела,
// строки до 80 символов, скобки и имена по соглашению, защита заголовка
// и отсутствие using namespace. Стадия Б (правила 8-9): explicit у
// конструктора с одним параметром и у оператора преобразования, const у
// методов без изменения состояния, инициализация полей в списке.
#ifndef COMPLEX_GIT_LAB_MYCOMPLEX_H_
#define COMPLEX_GIT_LAB_MYCOMPLEX_H_

#include <iostream>

class Complex {
public:
    Complex() : re_(0.0), im_(0.0) {}
    explicit Complex(double re, double im = 0) : re_(re), im_(im) {}
    Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}
    ~Complex();

    void set(double re, double im = 0);
    explicit operator double() const;
    double abs() const;

    double re() const { return re_; }
    double im() const { return im_; }
    void print(std::ostream& out) const;

    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, const Complex&);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator+(double value) const;
    friend Complex operator+(double lhs, const Complex& rhs);
    Complex operator-(double value) const;
    friend Complex operator-(double lhs, const Complex& rhs);
    Complex operator*(const Complex& other) const;
    Complex operator*(double value) const;
    friend Complex operator*(double lhs, const Complex& rhs);
    Complex operator/(double value) const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator+=(double value);
    Complex& operator-=(double value);
    Complex& operator*=(double value);
    Complex& operator/=(double value);
    Complex& operator=(const Complex& other);
    Complex& operator=(double value);

private:
    double re_;
    double im_;
};

#endif
