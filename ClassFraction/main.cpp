#include<iostream>
#include<cmath>
using namespace std;
using std::cin;
using std::endl;
using std::cout;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);

class Fraction {
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const {
		return integer;
	}
	int get_numerator()const {
		return numerator;
	}
	int get_denominator()const {
		return denominator;
	}
	void set_integer(int integer) {
		this->integer - integer;
	}
	void set_numerator(int numerator) {
		this->numerator = numerator;
	}
	void set_denominator(int denominator) {
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	Fraction& to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const {
		Fraction inverted = *this;
		inverted.to_improper();
		int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;
		return inverted;
	}

	void print()const {
		if (integer)cout << integer;
		if (numerator) {
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (!integer && !numerator)cout << 0;
		cout << endl;
	}

	Fraction() {
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer) {
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "largConstructor:\t" << this << endl;
	}
	/*
	Fraction(int integer) { //
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "largConstructor:\t" << this << endl;
	}
	*/
	Fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator , int denominator ) {
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
	}
	~Fraction() {
		cout << "Destructor:\t" << this << endl;
	}

	

	Fraction& operator=(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other) {
		return *this = *this * other;
	}
	Fraction& operator+=(const Fraction& other) {
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other) {
		return *this = *this - other;
	}
	Fraction& operator/=(const Fraction& other) {
		return *this = *this / other;
	}
	Fraction& operator++() {
		integer++;
		return *this;
	}
	Fraction& operator++(int) {
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--() {
		integer--;
		return *this;
	}
	Fraction& operator--(int) {
		Fraction old = *this;
		integer--;
		return old;
	}

	explicit operator int()const {
		return this->integer;
	}
	operator double()const {
		return integer + (double)numerator / denominator;
	}
};

Fraction operator*(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	/*
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
	*/
	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(const Fraction& left, const Fraction& right) {
	return left * right.inverted();
}
Fraction operator+(const Fraction& left, const Fraction& right){
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




//#define CONSTRUCTORS_CHECK
//#define ARECHMETICAL_OPERATORS
void main() {
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D;
	E.print();
	Fraction F;
	F = E;
	F.print();
#endif;
#ifdef ARECHMETICAL_OPERATORS
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	Fraction C = A - B;
	C.print();
	C.print();
	C.print();
	cout << "\n-----------------------------" << endl;
	(A / B).print();
	cout << "\n-----------------------------" << endl;
	A *= B;
	A.print();
	for (Fraction i(1, 2); i.get_integer() < 10; i++) {
		i.print();
	}
#endif;
	Fraction A(2, 3, 4);
	cout << A;
	int a = (int)A;
	cout << a << endl;

	double b = (int)A;
	cout << b << endl;
}