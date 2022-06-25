#include"Fraction.h"

/*
#define CONSTRUCTORS_CHECK
#define ARECHMETICAL_OPERATORS
*/

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
	Fraction A1(2, 3, 4);
	A1.print();
	Fraction B1(3, 4, 5);
	B1.print();
	Fraction C1 = A - B;
	C1.print();
	C1.print();
	C1.print();
	cout << "\n-----------------------------" << endl;
	(A1 / B1).print();
	cout << "\n-----------------------------" << endl;
	A1 *= B1;
	A1.print();
	for (Fraction i(1, 2); i.get_integer() < 10; i++) {
		i.print();
	}
#endif;
	Fraction A2(2, 3, 4);
	cout << A2;
	int a = (int)A2;
	cout << a << endl;

	double b = (int)A2;
	cout << b << endl;
}