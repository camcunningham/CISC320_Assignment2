//
// Created by Cam on 10/17/2019.
//

#include "fraction_16cjc12.h"

//FractionException implementation
FractionException::FractionException(const string &message) : errorMessage(message) {}
const string& FractionException::what() { return errorMessage; }

Fraction::Fraction() : num(0), denom(1) {}
Fraction::Fraction(int num1) : num(1), denom(1) {}
Fraction::Fraction(int num1, int num2) {
    if(num2 != 0) {
        int div = gcd(num1, num2);
        num = num1 / div;
        denom = num2 / div;
    } else {
        throw FractionException("Divisor cannot be zero.");
    }
}

int Fraction::numerator() const {
    return num;
}

int Fraction::denominator() const {
    return denom;
}

int Fraction::gcd(int n, int m) {
    if(m <= n && n % m == 0) {
        return m;
    } else if (n < m) {
        return gcd(m,n);
    } else {
        return gcd(m, (n%m));
    }
}

//Compares two supplied fractions: Returns 0 if equal, 1 if first param > second param, -1 if second param > first param
int compare(const Fraction& first, const Fraction& second) {
    int size1 = first.numerator() * second.denominator();
    int size2 = second.numerator() * first.denominator();
    if(size1 == size2) {
        return 0;
    } else if (size1 > size2) {
        return 1;
    } else {
        return -1;
    }

}

//Overloading operators
Fraction operator+(const Fraction& left, const Fraction& right) {
    int numerator = (left.numerator() * right.denominator()) + (right.numerator() * left.denominator());
    int denominator = (left.denominator() * right.denominator());

    return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    int numerator = (left.numerator() * right.denominator()) - (right.numerator() * left.denominator());
    int denominator = (left.denominator() * right.denominator());

    return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    int numerator = left.numerator() * right.numerator();
    int denominator = left.denominator() * right.denominator();

    return Fraction(numerator, denominator);
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    int numerator = left.numerator() * right.denominator();
    int denominator = left.denominator() * right.numerator();

    return Fraction(numerator, denominator);
}

Fraction operator+=(Fraction& left, const Fraction& right) {
    Fraction temp = left + right;
    left = temp;
    return left;
}

bool operator==(const Fraction& left, const Fraction& right) {
    bool result;
    compare(left, right) == 0 ? result = true : result = false;
    return result;
}

ostream& operator<<(ostream& out, const Fraction& value) {
    out << value.num << "/" << value.denom;
    return out;
}

istream& operator>>(istream& in, Fraction& value) {
    cout << "Enter the numerator: ";
    in >> value.num;
    cout << "Enter the denominator: ";
    in >> value.denom;
    return in;
}
