#include <iostream>
#include "temp.h"
using namespace std;

int main()
{
	int a[10] = { 27,14,9,22,11,4,8,41,56,31 };
	cout << "quicksort 수행 전 int형 배열 : ";
	show(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	quicksort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	cout << "quicksort 수행 후 int형 배열 : ";
	show(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	cout << endl;
	
	char c[13] = { 'd','a','t','a','s','t','r','u','c','t','u','r','e' };
	cout << "quicksort 수행 전 char형 배열 : ";
	show(c, 0, sizeof(c) / sizeof(c[0]) - 1);
	quicksort(c, 0, sizeof(c) / sizeof(c[0]) - 1);
	cout << "quicksort 수행 후 char형 배열 : ";
	show(c, 0, sizeof(c) / sizeof(c[0]) - 1);
	cout << endl;

	double d[5] = { 2.2, 1.1, 4.4 , 5.5, 3.3 };
	cout << "quicksort 수행 전 double형 배열 : ";
	show(d, 0, sizeof(d) / sizeof(d[0]) - 1);
	quicksort(d, 0, sizeof(d) / sizeof(d[0]) - 1);
	cout << "quicksort 수행 후 double형 배열 : ";
	show(d, 0, sizeof(d) / sizeof(d[0]) - 1);
	cout << endl;

	CStudent s[6];
	for (int i = 0; i < sizeof(s) / sizeof(s[0]) ; i++) {
		s[i].setId(rand());
	}
	cout << "quicksort 수행 전 class형 배열 : ";
	for (int i = 0; i < sizeof(s) / sizeof(s[0]) ; i++) {
		cout << s[i].getId() << " ";
	}
	cout << endl;
	quicksort(s, 0, sizeof(s) / sizeof(s[0]) - 1);
	cout << "quicksort 수행 후 class형 배열 : ";
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		cout << s[i].getId() << " ";
	}
	cout << endl;
}

