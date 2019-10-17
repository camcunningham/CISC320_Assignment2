//
// Created by Cam on 10/17/2019.
//
#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

class Fraction {
private:
    //Func to calculate gcd
    static int gcd(int n, int m);
    //Numerator
    int num;
    //Denominator
    int denom;



public:
    Fraction();
    Fraction(int num1);
    Fraction(int num1, int num2);

    int numerator() const;
    int denominator() const;

friend ostream& operator<<(ostream& out, const Fraction& value);
friend istream& operator>>(istream& in, Fraction& value);

Fraction operator-();
//Pre
Fraction& operator++();
//Post
Fraction operator++(int unused);

};

class FractionException {
private:
    string errorMessage;
public:
    FractionException(const string& message);

    const string& what(void);
};

int compare(Fraction& first, Fraction& second);

//Non-member overloading funcs
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+=(Fraction& left, const Fraction& right);

//bool operator<(const Fraction& left, const Fraction& right);
//bool operator<=(const Fraction& left, const Fraction& right);
//bool operator==(const Fraction& left, const Fraction& right);
//bool operator>(const Fraction& left, const Fraction& right);
//bool operator>=(const Fraction& left, const Fraction& right);
//bool operator!=(const Fraction& left, const Fraction& right);



