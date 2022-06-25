#include"Fraction.h"



int Fraction::get_integer()const {
	return integer;
}
int Fraction::get_numerator()const {
	return numerator;
}
int Fraction::get_denominator()const {
	return denominator;
}
void Fraction::set_integer(int integer) {
	this->integer - integer;
}
void Fraction::set_numerator(int numerator) {
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator) {
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

Fraction& Fraction::to_improper() {
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper() {
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const {
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;
}

void Fraction::print()const {
	if (integer)cout << integer;
	if (numerator) {
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	if (!integer && !numerator)cout << 0;
	cout << endl;
}

Fraction::Fraction() {
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer) {
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "largConstructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) {
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator) {
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssigment:\t" << this << endl;
}
Fraction::~Fraction() {
	cout << "Destructor:\t" << this << endl;
}



Fraction& Fraction::operator=(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssigment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other) {
	return *this = *this * other;
}
Fraction& Fraction::operator+=(const Fraction& other) {
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other) {
	return *this = *this - other;
}
Fraction& Fraction::operator/=(const Fraction& other) {
	return *this = *this / other;
}
Fraction& Fraction::operator++() {
	integer++;
	return *this;
}
Fraction& Fraction::operator++(int) {
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction::operator--() {
	integer--;
	return *this;
}
Fraction& Fraction::operator--(int) {
	Fraction old = *this;
	integer--;
	return old;
}

Fraction::operator int()const {
	return this->integer;
}
Fraction::operator double()const {
	return integer + (double)numerator / denominator;
}

Fraction operator*(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(const Fraction& left, const Fraction& right) {
	return left * right.inverted();
}
Fraction operator+(const Fraction& left, const Fraction& right) {
	return Fraction(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(const Fraction& left, const Fraction& right) {
	return Fraction(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}





bool operator==(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	bool result = left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
	return result;
}
bool operator!=(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	bool result = left.get_numerator() * right.get_denominator() != right.get_numerator() * left.get_denominator();
	return result;
}
bool operator>(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	bool result = left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
	return result;
}
bool operator<(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	bool result = left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
	return result;
}
bool operator>=(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	bool result = left.get_numerator() * right.get_denominator() != right.get_numerator() * left.get_denominator();
	return result;
}
bool operator<=(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	bool result = left.get_numerator() * right.get_denominator() != right.get_numerator() * left.get_denominator();
	return result;
}


std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator()) {
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (!obj.get_integer() && !obj.get_numerator())os << 0;
	return os;
}