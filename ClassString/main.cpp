#include<iostream>
#include <algorithm>
using namespace std;
using std::cin;
using std::endl;
using std::cout;


class String
{
	int size;	
	char* str;	
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}


	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator +=(const String& other) {
		return *this = *this + other;
	}
	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}


	//				Methods:
	void print()const {
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right) {
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
} 



//#define NULL_TERMINATED_LINES
//#define DEBUG_ASSERTION_FAILED_1
//#define DEBUG_ASSERTION_FAILED_2
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef NULL_TERMINATED_LINES
	char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;
	cout << strlen(str) << endl;
#endif // NULL_TERMINATED_LINES

#ifdef DEBUG_ASSERTION_FAILED_1
	int a = 2;
	int* pa = &a;
	int arr[] = { 3,5,8 };

	delete arr;
#endif // DEBUG_ASSERTION_FAILED_1

#ifdef DEBUG_ASSERTION_FAILED_2
	int* arr = new int[5];
	int* brr = arr;
	delete[] brr;
	delete[] arr;
#endif // DEBUG_ASSERTION_FAILED_2

#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(44);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();
	cout << str3 << endl;

	String str4 = str3;		//Copy constructor
	cout << "Str4:\t" << str4 << endl;

	String str5;	//Default constructor
	str5 = str4;	//Copy assignment
	cout << str5 << endl;

	int a = 2;
	int b = 3;
	a = b;
#endif // CONSTRUCTORS_CHECK
String str3 = "Hello World";
	cout << str3 << endl;
str3:to_upper(str3);
	cout << str3 << endl;
}