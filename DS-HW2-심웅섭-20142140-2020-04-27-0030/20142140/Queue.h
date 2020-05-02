#pragma once
#include "List.h"
#include <cassert>

template<typename T> 
class Queue : public List<T> {
public:
	void enqueue(T elem);
	T dequeue();
	bool isEmpty();
};

template<typename T> 
void Queue<T>::enqueue(T elem)
{
	List<T>::insert(elem);
}

template<typename T>
T Queue<T>::dequeue()
{
	assert(!isEmpty());
	T elem;
	List<T>::GetLast(elem);
	return elem;
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return bool(List<T>::isEmpty());
}
