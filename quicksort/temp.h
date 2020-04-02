#pragma once
#include <iostream>
#include "CStudent.h"
using namespace std;

template <typename Type>
void swapElements(Type a[], int first, int last)
{
	Type temp;
	temp = a[first];
	a[first] = a[last];
	a[last] = temp;
}

template <typename Type>
void show(Type a[], int first, int last)
{
	for (int i = first; i <= last; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

template <typename Type>
int partition(Type a[], int first, int last)
{
	int lastSmall = first, i;

	for (i = first + 1; i <= last; i++) {
		if (a[i] <= a[first]) {
			++lastSmall;
			swapElements(a, lastSmall, i);
		}
	}
	swapElements(a, first, lastSmall);
	return lastSmall;
}

template <typename Type>
void quicksort(Type a[], int first, int last)
{
	if (first >= last) {
		return;
	}
	cout << "partition 수행 전 : ";
	show(a, first, last);
	int split = partition(a, first, last);
	cout << "partition 수행 후 : ";
	show(a, first, last);
	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
}

template <>
void quicksort(CStudent a[], int first, int last)
{
	if (first >= last) {
		return;
	}
	cout << "partition 수행 전 : ";
	for (int i = 0; i < last; i++) {
		cout << a[i].getId() << " ";
	}
	cout << endl;
	int split = partition(a, first, last);
	cout << "partition 수행 후 : ";
	for (int i = 0; i < last; i++) {
		cout << a[i].getId() << " ";
	}
	cout << endl;
	quicksort(a, first, split - 1);
	quicksort(a, split + 1, last);
}
