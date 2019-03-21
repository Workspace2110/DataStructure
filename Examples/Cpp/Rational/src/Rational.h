#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
#include<string>
#include<sstream>
#include"Numbers.h"
using namespace std;

class  Rational {
public:
	Rational();
	Rational(int numerator);
	Rational(int numerator, int denominator);
	~Rational();

	int getNumerator() const;
	int getDenominator() const;

	Rational Zore();
	bool IsZero() const;

	Rational Add(const Rational& otherNumber) const;
	Rational Subtract(const Rational& otherNumber) const;
	Rational Multiply(const Rational& otherNumber) const;
	Rational Divide(const Rational& otherNumber) const;

	int compareTo(const Rational& otherNumber) const;
	bool IsEqual(const Rational& otherNumber) const;
	bool IsGreater(const Rational otherNumber) const;
	bool IsLess(const Rational& otherNumber) const;

	int intValue();
	double doubleValue();
	string ToString() const;

	Rational &operator+=(const Rational& otherNumber);
	Rational &operator-=(const Rational& otherNumber);
	Rational &operator*=(const Rational& otherNumber);
	Rational &operator/=(const Rational& otherNumber);

	Rational &operator++();
	Rational &operator--();

	Rational operator++(int dummy);
	Rational operator--(int dummy);

	Rational &operator+();
	Rational &operator-();

	friend ostream &operator<<(ostream& os, Rational& rational);
	friend istream &operator>>(istream& is, Rational& rational);
private:
	Numbers rationalNumber;
	static int gcd(int n, int d);
protected:
};

bool operator<(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);

Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
#endif // ! RATIONAL_H
