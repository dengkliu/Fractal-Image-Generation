//
//complex.cpp
//operator overloaded
//
//created by Dengke Liu on 12/10/2014
//

#include "complex.h"
#include<iostream>
#include<math.h>

complex()// constructor
{
    real=5;imag=5;
}

complex(double r)
{
    real=r;
}

complex(double r,double i)
{
    real=r;
    imag=i;
}

double displayreal()// return the real part
{
    return real;
}

double displayimag()// return the imagnary part
{
    return imag;
}

complex complex::operator+(complex c)// addition
{
    complex newnum;
    newnum.real=real+c.real;
    newnum.imag=imag+c.imag;
    return newnum;
}

complex complex::operator-(complex c)// substraction
{
    complex newnum;
    newnum.real=real-c.real;
    newnum.imag=imag-c.imag;
    return newnum;
}

complex complex::operator*(complex c)//multiplication
{
    complex newnum;
    newnum.real=real*c.real-imag*c.imag;
    newnum.imag=real*c.imag+imag*c.real;
    return newnum;
}

complex complex::operator/(complex c)//division
{
    complex newnum;
    newnum.real=(real*c.real+imag*c.imag)/(c.real*c.real+c.imag*c.imag);
    newnum.imag=(imag*c.real-real*c.imag)/(c.real*c.real+c.imag*c.imag);
    return newnum;
}

double complex::magnitude2()//magnitude
{
    return real*real+imag*imag
}

std::ostream & operator<<(std::ostream & out, complex & obj)
{
    if(obj.imag==0) out << obj.real;
    else out << obj.real << "+" << obj.imag << "i";
    return out;
}

