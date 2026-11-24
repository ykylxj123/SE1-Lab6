#include <cmath>
#include <iostream>

#include "mycomplex.h"

using namespace std;

Complex::Complex(double re, double im)
{
    re_ = re;
    im_ = im;
}

Complex::Complex(const Complex& aRval)
{
    re_ = aRval.re_;
    im_ = aRval.im_;
}

Complex::~Complex()
{
    re_ = 0.0;
    im_ = 0.0;
}

void Complex::set(double re, double im)
{
    re_ = re;
    im_ = im;
}

Complex::operator double()
{
    return abs();
}

double Complex::abs()
{
    return sqrt(re_ * re_ + im_ * im_);
}

Complex Complex::operator+(const Complex& aRval)
{
    Complex result;
    result.re_ = re_ + aRval.re_;
    result.im_ = im_ + aRval.im_;
    return result;
}

Complex Complex::operator-(const Complex& aRval)
{
    Complex result;
    result.re_ = re_ - aRval.re_;
    result.im_ = im_ - aRval.im_;
    return result;
}

Complex Complex::operator+(const double& aRval)
{
    Complex result;
    result.re_ = re_ + aRval;
    result.im_ = im_;
    return result;
}

Complex Complex::operator-(const double& aRval)
{
    Complex result(*this);
    result.re_ = re_ - aRval;
    return result;
}

Complex Complex::operator*(const Complex& aRval)
{
    Complex result;
    result.re_ = re_ * aRval.re_ - im_ * aRval.im_;
    result.im_ = re_ * aRval.im_ + im_ * aRval.re_;
    return result;
}

Complex Complex::operator*(const double& aRval)
{
    Complex result;
    result.re_ = re_ * aRval;
    result.im_ = im_ * aRval;
    return result;
}

Complex Complex::operator/(const double& aRval)
{
    Complex result;
    result.re_ = re_ / aRval;
    result.im_ = im_ / aRval;
    return result;
}

Complex& Complex::operator+=(const Complex& aRval)
{
    re_ += aRval.re_;
    im_ += aRval.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& aRval)
{
    re_ -= aRval.re_;
    im_ -= aRval.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& aRval)
{
    double tmp_re = re_;
    re_ = re_ * aRval.re_ - im_ * aRval.im_;
    im_ = im_ * aRval.re_ + tmp_re * aRval.im_;
    return *this;
}

Complex& Complex::operator+=(const double& aRval)
{
    re_ += aRval;
    return *this;
}

Complex& Complex::operator-=(const double& aRval)
{
    re_ -= aRval;
    return *this;
}

Complex& Complex::operator*=(const double& aRval)
{
    re_ *= aRval;
    im_ *= aRval;
    return *this;
}

Complex& Complex::operator/=(const double& aRval)
{
    re_ /= aRval;
    im_ /= aRval;
    return *this;
}

Complex& Complex::operator=(const Complex& aRval)
{
    re_ = aRval.re_;
    im_ = aRval.im_;
    return *this;
}

Complex& Complex::operator=(const double& aRval)
{
    re_ = aRval;
    im_ = 0.0;
    return *this;
}

istream& operator>>(istream& stream, Complex& a)
{
    char tmp[256];
    stream >> a.re_ >> a.im_ >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, Complex& a)
{
    stream << a.re_;
    if (!(a.im_ < 0)) {
        stream << '+';
    }
    stream << a.im_ << 'i';
    return stream;
}

Complex operator+(const double& aLval, const Complex& aRval)
{
    Complex result;
    result.re_ = aLval + aRval.re_;
    result.im_ = aRval.im_;
    return result;
}

Complex operator-(const double& aLval, const Complex& aRval)
{
    Complex result;
    result.re_ = aLval - aRval.re_;
    result.im_ = -aRval.im_;
    return result;
}

Complex operator*(const double& aLval, const Complex& a)
{
    Complex result;
    result.re_ = aLval * a.re_;
    result.im_ = aLval * a.im_;
    return result;
}
