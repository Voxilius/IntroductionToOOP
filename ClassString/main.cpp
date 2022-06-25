#include"String.h"

//#define NULL_TERMINATED_LINES
//#define DEBUG_ASSERTION_FAILED_1
//#define DEBUG_ASSERTION_FAILED_2
//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define KEYBOARD_INPUT_CHECK

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

	String str4 = str3;	
	cout << "Str4:\t" << str4 << endl;

	String str5;
	str5 = str4;
	cout << str5 << endl;

	int a = 2;
	int b = 3;
	a = b;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef KEYBOARD_INPUT_CHECK
	String str;
	cout << "Введите строку: ";
	getline(cin, str);
	cout << str << endl;
	str.to_upper();
	cout << str << endl;
	str.to_lower();
	cout << str << endl;

#endif // KEYBOARD_INPUT_CHECK

	String str1;	
	str1.print();
	String str2(22);
	str2.print();
	String str3 = "Hello";
	str3.print();
	String str4(); 
	String str5{};
	str5.print();
	String str6 = str3;
	str6.print();
}