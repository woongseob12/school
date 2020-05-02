#pragma once
#include <cassert>
#include <iostream>
#include "CPharmacy.h"
using namespace std;

template <typename T> 
class List {
public:
	List();
	void insert(const T & elem);
	void insertTail(const T & elem);	
	bool first(T & elem);
	bool next(T & elem);
	bool last(T & elem);
	bool previous(T & elem);
	void remove(const T & elem);
	T GetFirst();
	void GetLast(T &);
	bool isEmpty();
	void clear();
	friend ostream& operator<<(ostream & os, CPharmacy &);

private:
	struct Node;
	typedef Node *Link;
	struct Node {	
		T elem;
		Link next;
		Link prev;
	};
	Link head;
	Link current;
	Link tail;
};


template<typename T> 
List<T>::List()
{
	head = NULL;
	current = NULL;
	tail = NULL;
}

template<typename T>
void List<T>::insert(const T & elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	addedNode->next = head;
	if (addedNode->next == NULL) {
		tail = addedNode;
	}
	if (head) {
		head->prev = addedNode;
	}
	addedNode->prev = NULL;
	head = addedNode;
}

template<typename T> 
void List<T>::insertTail(const T & elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;
	addedNode->prev = tail;
	if (head == NULL) {
		head = addedNode;
	}
	if (tail) {
		tail->next = addedNode;
	}
	addedNode->next = NULL;
	tail = addedNode;
}

template<typename T> 
bool List<T>::first(T & elem)
{
	if (head == NULL) {
		return false;
	}
	current = head;
	elem = current->elem;
	return true;
}

template<typename T> 
bool List<T>::next(T & elem)
{
	assert(current);
	if (current->next == NULL) {
		return false;
	}
	current = current->next;
	elem = current->elem;
	return true;
}

template<typename T>
bool List<T>::last(T & elem)
{
	if (tail == NULL) {
		return false;
	}
	current = tail;
	elem = current->elem;
	return true;
}

template<typename T> 
bool List<T>::previous(T &elem)
{
	assert(current);
	if (current->prev == NULL)
		return false;
	else {
		current = current->prev;
		elem = current->elem;
		return true;
	}
}

template<typename T> 
void List<T>::remove(const T & elem)
{
	Link delNode;
	assert(head);
	current = head;
	while (current != NULL) {
		if (elem == current->elem) {
			delNode = current;
			if (current->prev != NULL) {	// 첫번째 노드가 아니면
				current->prev->next = delNode->next;
			}
			else {
				head = current->next;
			}
			if (current->next != NULL) {	// 마지막 노드가 아니면
				current->next->prev = delNode->prev;
			}
			else {
				tail = current->prev;
			}
			current = current->next;
			delete delNode;
		}
		else {
			current = current->next;
		}
	}
}

template<typename T>
T List<T>::GetFirst()
{
	assert(head);
	T elem;
	elem = head->elem;
	head = head->next;
	delete head->prev;
	head->prev = NULL;

	return elem;
}

template<typename T> 
void List<T>::GetLast(T &elem)
{
	assert(tail);
	elem = tail->elem;
	if (tail->prev != NULL) {
		tail = tail->prev;
		if (tail->next != NULL) {
			delete tail->next;
		}
		tail->next = NULL;
	}
	else {
		delete tail;
		head = NULL;
		tail = NULL;
	}
}

template<typename T>
bool List<T>::isEmpty()
{
	if (head == NULL && tail == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void List<T>::clear()
{
	Link delNode;
	assert(head);
	current = head;
	while (current != NULL) {
		delNode = head;
		current = current->next;
		head = current;
		delete delNode;
	}
}

ostream& operator<<(ostream & os, CPharmacy& elem)
{
	elem.ShowPharmacy();
	return os;
}