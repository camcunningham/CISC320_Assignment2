// CISC 320 Assignment 2 implementation file
// Created by Cam Cunningham on 10/17/2019.
//

#include "fraction_16cjc12.h"

//FractionException implementation
FractionException::FractionException(const string &message) : errorMessage(message) {}
const string& FractionException::what() { return errorMessage; }

//Fraction constructors

//Default constructor
Fraction::Fraction() : num(0), denom(1) {}
//One parameter -> numerator = num1, denominator = 1
Fraction::Fraction(int num1) : num(num1), denom(1) {}
//Two parameter -> numerator = num1, denominator = num2
Fraction::Fraction(int num1, int num2) {
    //Checking if the fraction is legal
    if(num2 != 0) {
        //Making the minus for a negative fraction appear on the numerator
        if(num2 < 0 && num1 > 0) {
            num1 = -num1;
            num2 = -num2;
        }
        //Normalizing the fraction
        int div = gcd(num1, num2);
        if(div == 0) {
           div = 1;
        }
        num = num1 / div;
        denom = num2 / div;

    } else {
        throw FractionException("Divisor cannot be zero.");
    }
}

//Numerator getter
int Fraction::numerator() const {
    return num;
}

//Denominator getter
int Fraction::denominator() const {
    return denom;
}

//Func to calculate and return the greatest common denominator of two integers
int gcd(int n, int m) {
    n = abs(n);
    m = abs(m);
    if(n == 0 || m == 0) {
        return 0;
    }
    if(m <= n && (n % m == 0)) {
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

    return {numerator, denominator};
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    int numerator = (left.numerator() * right.denominator()) - (right.numerator() * left.denominator());
    int denominator = (left.denominator() * right.denominator());

    return {numerator, denominator};
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    int numerator = left.numerator() * right.numerator();
    int denominator = left.denominator() * right.denominator();

    return {numerator, denominator};
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    int numerator = left.numerator() * right.denominator();
    int denominator = left.denominator() * right.numerator();

    return {numerator, denominator};
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

bool operator<(const Fraction& left, const Fraction& right) {
    bool result;
    compare(left, right) == -1 ? result = true : result = false;
    return result;
}

bool operator<=(const Fraction& left, const Fraction& right) {
    bool result;
    (compare(left, right) == -1 || compare(left,right) == 0) ? result = true : result = false;
    return result;
}

bool operator>=(const Fraction& left, const Fraction& right) {
    bool result;
    (compare(left, right) == 1 || compare(left,right) == 0) ? result = true : result = false;
    return result;
}

bool operator>(const Fraction& left, const Fraction& right) {
    bool result;
    compare(left, right) == 1 ? result = true : result = false;
    return result;
}

bool operator!=(const Fraction& left, const Fraction& right) {
    bool result;
    compare(left, right) != 0 ? result = true : result = false;
    return result;
}

//Member overloaded operators
ostream& operator<<(ostream& out, const Fraction& value) {
    out << value.num << "/" << value.denom;
    return out;
}

istream& operator>>(istream& in, Fraction& value) {
    //Var to hold the input
    string temp;
    //Read input into temp
    in >> temp;
    //If there is a '/' -> it is a fraction
    if(temp.find('/') != string::npos) {
        //Tokenize the string with / as the delimiter
        vector<string> container;
        stringstream ss(temp);
        string token;
        while(getline(ss, token, '/')) {
            container.push_back(token);
        }

        //Before the / char will be the numerator
        value.num = stoi(container[0]);
        //After the / char will be the denominator
        value.denom = stoi(container[1]);
    } else {
        //No '/', so it's an integer: make the numerator the supplied integer and default the denominator to 1
        value.num = stoi(temp);
        value.denom = 1;
    }

}

//Negation operator
Fraction Fraction::operator-() {
    return {-(this->num), this->denom};
}

//Pre-increment operator
Fraction& Fraction::operator++() {
    this->num = num + denom;
    this->denom = denom;
    return *this;
}

//Post increment operator
Fraction Fraction::operator++(int unused) {
    Fraction temp = *this;
    ++*this;
    return temp;
}
