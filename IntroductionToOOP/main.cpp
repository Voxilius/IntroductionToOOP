#include<iostream>
#include<cmath>
using namespace std;


class Point {
	double x;
	double y;
public:
	double get_x()const {
		return x;
	}
	double get_y()const {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;	
	}
	//                     Constructors:

	Point() {
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x) {
		this->x = x;
		this->y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x,double y) {
		this->x = x;
		this->y = y;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point() {
		cout << "Destructor\t\t" << this << endl;
	}
	Point operator=(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	double distance(const Point& other) {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print() {
		cout << "X = " << x << "\tY =" << y << endl;
	}
};

double distance(Point A, Point B) {
	double x_distance = A.get_x() - B.get_y();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(pow(x_distance, 2) + pow(y_distance, 2));
}



void main() {
	setlocale(LC_ALL, "Russian");
#ifdef Struct_point;

	int a;
	Point A;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif 
#ifdef DISTANCE;
	Point A;
	A.set_x(2);
	A.set_y(3);
	A.print();

	Point B;
	cout << "\n----------------------------\n";
	B.set_x(7);
	B.set_y(8);
	B.print();
	cout << "Расстояние от A до B:" << A.distance(B) << endl;
	cout << "\n----------------------------\n";
	cout << "Расстояние от B до A:" << B.distance(A) << endl;
	cout << "\n----------------------------\n";
	cout << "Расстояние между A и B:" << distance(A, B) << endl;
	cout << "\n----------------------------\n";
	cout << "Расстояние между B и A:" << distance(B, A) << endl;
	cout << "\n----------------------------\n";
#endif
#ifdef CONSTRUCTORS_CHECK;
	Point A;
	A.print();
	Point B = 5;
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C;
	D.print();
#endif
#ifdef COPY_ASSIGNMENT_1;
	Point A(2, 3);
	Point B = A;
	Point C;
	C = B;
#endif
#ifdef COPY_ASSIGMENT_2;
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	cout << "\n----------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n----------------------------\n";
	add(A, B);
	A + B;
	A.add(b);
	A _ = B;

#endif
}
