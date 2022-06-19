#include<iostream>
#include<cmath>
using namespace std;

class Fraction {
	int a, b;
public:
	Fraction(int a, int b) {
		this->a = a;
		this->b = b;
	}

	Fraction operator+(Fraction c) {
		int a1 = int(this->a * c.b + this->b * c.a);
		int a2 = int(this->b * c.b);
		return Fraction(a1, a2);
	}
	Fraction operator-(Fraction c) {
		int a1 = int(this->a * c.b - this->b * c.a);
		int a2 = int(this->b * c.b);
		return Fraction(a1, a2);
	}

	Fraction operator*(Fraction c) {
		return Fraction(this->a * c.a, this->b * c.b);
	}
	Fraction operator/(Fraction c) {
		return Fraction(this->a * c.b, this->b * c.a);
	}

	void Print() {
		cout << "(" << this->a << "/" << this->b << ")";
	}
};




void main() {
	setlocale(LC_ALL, "Russian");
	Fraction d1(1, 5);
	Fraction d2(2, 5);
	cout << "ִנמבü 1: "; d1.Print(); cout << endl;
	cout << "ִנמבü 2: "; d2.Print(); cout << endl;

	d1.Print(); cout << "+"; d2.Print(); cout << "="; Fraction(d1 + d2).Print(); cout << endl;
	d1.Print(); cout << "-"; d2.Print(); cout << "="; Fraction(d1 - d2).Print(); cout << endl;
	d1.Print(); cout << "*"; d2.Print(); cout << "="; Fraction(d1 * d2).Print(); cout << endl;
	d1.Print(); cout << "/"; d2.Print(); cout << "="; Fraction(d1 / d2).Print(); cout << endl;

}