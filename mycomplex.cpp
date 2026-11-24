#include <cmath>
#include <iostream>
#include <string>

#include "mycomplex.h"

Complex::~Complex()
{
}

void Complex::set(double re, double im)
{
    re_ = re;
    im_ = im;
}

Complex::operator double() const
{
    return abs();
}

double Complex::abs() const
{
    return std::sqrt(re_ * re_ + im_ * im_);
}

void Complex::print(std::ostream& out) const
{
    out << re_;
    if (!(im_ < 0)) {
        out << '+';
    }
    out << im_ << 'i';
}

Complex Complex::operator+(const Complex& other) const
{
    return Complex(re_ + other.re_, im_ + other.im_);
}

Complex Complex::operator-(const Complex& other) const
{
    return Complex(re_ - other.re_, im_ - other.im_);
}

Complex Complex::operator+(double value) const
{
    return Complex(re_ + value, im_);
}

Complex Complex::operator-(double value) const
{
    return Complex(re_ - value, im_);
}

Complex Complex::operator*(const Complex& other) const
{
    return Complex(re_ * other.re_ - im_ * other.im_,
                   re_ * other.im_ + im_ * other.re_);
}

Complex Complex::operator*(double value) const
{
    return Complex(re_ * value, im_ * value);
}

Complex Complex::operator/(double value) const
{
    return Complex(re_ / value, im_ / value);
}

Complex& Complex::operator+=(const Complex& other)
{
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    double re = re_;
    re_ = re_ * other.re_ - im_ * other.im_;
    im_ = im_ * other.re_ + re * other.im_;
    return *this;
}

Complex& Complex::operator+=(double value)
{
    re_ += value;
    return *this;
}

Complex& Complex::operator-=(double value)
{
    re_ -= value;
    return *this;
}

Complex& Complex::operator*=(double value)
{
    re_ *= value;
    im_ *= value;
    return *this;
}

Complex& Complex::operator/=(double value)
{
    re_ /= value;
    im_ /= value;
    return *this;
}

Complex& Complex::operator=(const Complex& other)
{
    re_ = other.re_;
    im_ = other.im_;
    return *this;
}

Complex& Complex::operator=(double value)
{
    re_ = value;
    im_ = 0.0;
    return *this;
}

std::istream& operator>>(std::istream& stream, Complex& value)
{
    std::string tmp;
    stream >> value.re_ >> value.im_ >> tmp;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Complex& value)
{
    value.print(stream);
    return stream;
}

Complex operator+(double lhs, const Complex& rhs)
{
    return Complex(lhs + rhs.re_, rhs.im_);
}

Complex operator-(double lhs, const Complex& rhs)
{
    return Complex(lhs - rhs.re_, -rhs.im_);
}

Complex operator*(double lhs, const Complex& rhs)
{
    return Complex(lhs * rhs.re_, lhs * rhs.im_);
}
