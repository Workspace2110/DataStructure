#include "Rational.h"

Rational::Rational()
{
	this->rationalNumber.numerator = 0;
	this->rationalNumber.denominator = 1;
}

Rational::Rational(int numerator) {
	this->rationalNumber.numerator = numerator;
	this->rationalNumber.denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
	int factor = gcd(numerator, denominator);
	this->rationalNumber.numerator = (denominator > 0 ? 1 : -1)* numerator / factor;
	try {
		this->rationalNumber.denominator = (denominator != 0) ? abs(denominator) / factor: throw -1;
	}
	catch (int error) {
		cout << "Denominator can't be 0." << endl;
	}
}

int Rational::getNumerator() const {
	return this->rationalNumber.numerator;
}

int Rational::getDenominator() const {
	return this->rationalNumber.denominator;
}

Rational Rational::Zore() {
	this->rationalNumber.numerator = 0;
	this->rationalNumber.denominator = 1;
	return *this;
}

bool Rational::IsZero() const {
	try {
		if (getDenominator()!= 0) {
			if (this->getNumerator() != 0)
				return false;
			else
				return true;
		}
		else
			throw "error";
	}
	catch (char* error) {
		cout << "Denominator can't be 0." << endl;
		return false;
	}
}

Rational Rational::Add(const Rational& otherNumber) const {
	return Rational(getNumerator()*otherNumber.getDenominator()+getDenominator()*otherNumber.getNumerator() , getDenominator()*otherNumber.getDenominator());
}

Rational Rational::Subtract(const Rational& otherNumber) const {
	return Rational(getNumerator()*otherNumber.getDenominator() - getDenominator()*otherNumber.getNumerator() , getDenominator()*otherNumber.getDenominator());
}

Rational Rational::Multiply(const Rational& otherNumber) const {
	return Rational(getNumerator()*otherNumber.getNumerator() , getDenominator()*otherNumber.getDenominator());
}

Rational Rational::Divide(const Rational& otherNumber) const {
	return Rational(getNumerator()*otherNumber.getDenominator(), getDenominator()*otherNumber.getNumerator());
}

int Rational::compareTo(const Rational& otherNumber) const {
	Rational temp = Subtract(otherNumber);
	if (temp.getNumerator() < 0)
		return -1;
	else if (temp.getNumerator() == 0)
		return 0;
	else if (temp.getNumerator() > 0)
		return 1;
}

bool Rational::IsEqual(const Rational& otherNumber) const {
	if (compareTo(otherNumber) == 0)
		return true;
	else
		return false;
}

bool Rational::IsGreater(const Rational otherNumber) const {
	if (compareTo(otherNumber) == 1)
		return true;
	else
		return false;
}

bool Rational::IsLess(const Rational& otherNumber) const {
	if (compareTo(otherNumber) == -1)
		return true;
	else
		return false;
}

int Rational::intValue() {
	return getNumerator() / getDenominator();
}

double Rational::doubleValue() {
	return 1.0*getNumerator() / getDenominator();
}

string Rational::ToString() const {
	Rational temp(getNumerator(),getDenominator());
	stringstream ss;
	if (getDenominator() == 1)
		ss << temp.getNumerator();
	else
		ss << temp.getNumerator() << "/" << temp.getDenominator();

	return ss.str();
}

int Rational::gcd(int numerator, int denominator) {
	int gcd = 1 ,n=abs(numerator) ,d=abs(denominator);
	for (int i = 1; i <= n && i <= d; ++i) {
		if (n%i == 0 && d%i == 0)
			gcd = i;
	}
	return gcd;
}

Rational &Rational::operator+=(const Rational& otherNumber) {
	*this = Add(otherNumber);
	return *this;
}

Rational &Rational::operator-=(const Rational& otherNumber) {
	*this = Subtract(otherNumber);
	return *this;
}

Rational &Rational::operator*=(const Rational& otherNumber) {
	*this = Multiply(otherNumber);
	return *this;
}

Rational &Rational::operator/=(const Rational& otherNumber) {
	*this = Divide(otherNumber);
	return *this;
}

Rational &Rational::operator++() {
	this->rationalNumber.numerator += getDenominator();
	return *this;
}

Rational &Rational::operator--() {
	this->rationalNumber.numerator -= getDenominator();
	return *this;
}

Rational Rational::operator++(int dummy) {
	Rational temp(getNumerator(),getDenominator());
	this->rationalNumber.numerator += getDenominator();
	return temp;
}

Rational Rational::operator--(int dummy) {
	Rational temp(getNumerator(), getDenominator());
	this->rationalNumber.numerator -= getDenominator();
	return temp;
}

Rational &Rational::operator+() {
	return *this;
}

Rational &Rational::operator-() {
	return Rational(-getNumerator(), getDenominator());
}

ostream &operator<<(ostream& os, Rational& rational) {
	try {
		if (rational.getDenominator() != 0) {
			os << rational.ToString();
			return os;
		}
		else
			throw - 1;
	}
	catch (int error) {
		os << "infinirty";
		return os;
	}
	
}

istream &operator>>(istream& is, Rational& rational) {
	cout << "Enter numerator: ";
	is >> rational.rationalNumber.numerator;
	cout << "Enter denominator: ";
	is >> rational.rationalNumber.denominator;
	return is;
}

Rational::~Rational() {

}

bool operator<(const Rational& r1, const Rational& r2)
{
	return r1.IsLess(r2);
}

bool operator>(const Rational& r1, const Rational& r2)
{
	return r1.IsGreater(r2);
}

bool operator==(const Rational& r1, const Rational& r2)
{
	return r1.IsEqual(r2);
}

bool operator<=(const Rational& r1, const Rational& r2)
{
	return (r1.IsLess(r2) || r1.IsEqual(r2));
}

bool operator>=(const Rational& r1, const Rational& r2)
{
	return (r1.IsGreater(r2) || r1.IsEqual(r2));
}

Rational operator+(const Rational& r1, const Rational& r2) {
	return r1.Add(r2);
}

Rational operator-(const Rational& r1, const Rational& r2) {
	return r1.Subtract(r2);
}

Rational operator*(const Rational& r1, const Rational& r2) {
	return r1.Multiply(r2);
}
Rational operator/(const Rational& r1, const Rational& r2) {
	return r1.Divide(r2);
}