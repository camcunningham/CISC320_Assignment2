// CISC 320 Assignment 2 header file
// Created by Cam Cunningham on 10/17/2019.
//
#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

class Fraction {
private:
    //Numerator
    int num;
    //Denominator
    int denom;
public:
    //Default constructor
    Fraction();
    //Single param
    Fraction(int num1);
    //Both params
    Fraction(int num1, int num2);

    //Getters
    int numerator() const;
    int denominator() const;

//Friend functions to overload istream and ostream
friend ostream& operator<<(ostream& out, const Fraction& value);
friend istream& operator>>(istream& in, Fraction& value);

//Unary operator overloading
//negation
Fraction operator-();
//Pre increment
Fraction& operator++();
//Post increment
Fraction operator++(int unused);

}; //end Fraction

//Fraction exception class
class FractionException {
private:
    //String to hold the supplied error message
    string errorMessage;
public:
    //Constructor: takes in an error message
    FractionException(const string& message);

    //Func to print the error message to the stream
    const string& what(void);
}; //end FractionException

//Func to calculate gcd
static int gcd(int n, int m);

//Non-member overloading funcs
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+=(Fraction& left, const Fraction& right);

//Comparison overloading
//Comparison function: Compares two fractions -> Returns 0 if equal, 1 if first > second, -1 if first < second
int compare(Fraction& first, Fraction& second);
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);



