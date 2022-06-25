#pragma once
#include<iostream>
#include<cmath>
#include<Windows.h>
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
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	Fraction& to_improper();

	Fraction& to_proper();
	Fraction inverted()const;

	void print()const;

	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();



	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator++();
	Fraction& operator++(int);
	Fraction& operator--();
	Fraction& operator--(int);

	explicit operator int()const;
	operator double()const;
};