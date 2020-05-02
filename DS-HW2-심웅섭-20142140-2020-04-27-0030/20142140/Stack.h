#pragma once
#include "List.h"
#include <cassert>

template<typename T>
class Stack : public List<T> {
public:
	void push(T elem);
	T pop();
	void top(T &elem);
	bool isEmpty();
};

template<typename T> 
void Stack<T>::push(T elem)
{
	List<T>::insertTail(elem);
}

template<typename T> 
T Stack<T>::pop()
{
	assert(!isEmpty());
	T elem;
	List<T>::GetLast(elem);
	return elem;
}

template<typename T> 
void Stack<T>::top(T &elem)
{
	List<T>::last(elem);
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return bool(List<T>::isEmpty());
}
