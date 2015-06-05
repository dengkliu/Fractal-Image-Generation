// Complex.h
// Created by Dengke Liu on 12/10/2014

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex
{
private:
    double real;
    double imag;

public:
    complex();//default constructor
    complex(double r);//constructor assigning value to real part
    complex(double r,double i);//constructor assigning vales to real and imaginary part
    double displayreal();//return the real part
    double displayimag();// return the imagnary part
    complex operator+(complex c);// addition
    complex operator-(complex c);//substraction
    complex operator*(complex c);//multiplication
    complex operator/(complex c);//division
    double magnitude2();//magnitude

    friend std::ostream & operator<<(std::ostream & out, complex & obj);

};

#endif // COMPLEX_H
