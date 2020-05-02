#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "CPharmacy.h"
using namespace std;

template<typename T>
void problem1(List<T>&);	// ���� ���
template<typename T>
void problem2(List<T>&);	// ���� ���
template<typename T>
void problem3(List<T>&);	// ���� ����
template<typename T>
void problem4(List<T>&);	// ù��° ����, ������ ���� ����
template<typename T>
void problem5(List<T>&);	// Tail �ֱ�
template<typename T>
void problem6(Stack<T>&);	// Stack ����
template<typename T>
void problem7(Queue<T>&);	// Queue ����
template<typename T>
void problem9(Queue<T>&);	// �౹ Ŭ����

int main()
{
	List<int> l;

	cout << "���� 1 ----------------------------------" << endl;
	cout << "# head������ �������� �־ first & next�� ����Ͽ� ����ϱ�" << endl;
	l.insert(7);
	l.insert(6);
	l.insert(5);
	l.insert(4);
	l.insert(3);
	l.insert(2);
	l.insert(1);
	problem1(l);
	cout << "\n���� 2 ----------------------------------" << endl;
	cout << "# head������ �־ last & previous�� ����Ͽ� ����ϱ�" << endl;
	problem2(l);
	cout << "\n���� 3 ----------------------------------" << endl;
	cout << "#  head������ �־ 5, 7, 1 ������ Ÿ�� ���� ���� �� 2��ó�� ����ϱ�" << endl;
	problem3(l);
	l.clear();
	cout << "\n���� 4 ----------------------------------" << endl;
	cout << "# head������ �־ ù��°, ������ ���� ã�Ƽ� �������� ���� �� 1��ó�� ����ϱ�" << endl;
	l.insert(7);
	l.insert(6);
	l.insert(5);
	l.insert(4);
	l.insert(3);
	l.insert(2);
	l.insert(1);
	problem4(l);
	cout << "\n���� 5 ----------------------------------" << endl;
	cout << "# tail������ �־� 1��ó�� ����ϱ�" << endl;
	l.clear();
	problem5(l);
	cout << "\n���� 6 ----------------------------------" << endl;
	cout << "# Stack �����ϱ�(LIFO)" << endl;
	Stack<int> s;
	problem6(s);
	cout << "\n���� 7 ----------------------------------" << endl;
	cout << "# Queue �����ϱ�(FIFO)" << endl;
	Queue<int> q;
	problem7(q);
	cout << "\n���� 9 ----------------------------------" << endl;
	cout << "# Template & Operator overloading�� ���� �౹ Ŭ���� ���� �� enqueue �� dequeue ����ϱ�" << endl;
	Queue<CPharmacy> c;
	problem9(c);

}

template<typename T>
void problem1(List<T>& lP)
{
	T elem;

	lP.first(elem);
	cout << elem << " ";
	while (lP.next(elem)) {
		cout << elem << " ";
	}
	cout << endl;
}

template<typename T>
void problem2(List<T>& lP)
{
	T elem;

	lP.last(elem);
	cout << elem << " ";
	while (lP.previous(elem)) {
		cout << elem << " ";
	}
	cout << endl;
}

template<typename T>
void problem3(List<T>& lP)
{
	lP.remove(5);
	lP.remove(1);
	lP.remove(7);
	problem2(lP);
}

template<typename T>
void problem4(List<T>& lP)
{
	T firstElem, elem;
	firstElem = lP.GetFirst();
	cout << "ù ��° ���� : " << firstElem;
	lP.GetLast(elem);
	cout << "\t������ ���� : " << elem << endl;
	problem1(lP);
}

template<typename T>
void problem5(List<T>& lP)
{
	lP.insertTail(7);
	lP.insertTail(6);
	lP.insertTail(5);
	lP.insertTail(4);
	lP.insertTail(3);
	lP.insertTail(2);
	lP.insertTail(1);
	problem1(lP);
}

template<typename T>
void problem6(Stack<T>& sP)
{
	sP.push(7);
	sP.push(6);
	sP.push(5);
	sP.push(4);
	sP.push(3);
	sP.push(2);
	sP.push(1);

	T elem;
	while (!sP.isEmpty()) {
		elem = sP.pop();
		cout << "pop�� ���� : " << elem;
		if (sP.isEmpty()) {
			cout << "\tTop ���� : NULL" << endl;
		}
		else {
			sP.top(elem);
			cout << "\tTop ���� : " << elem << endl;
		}
	}
}

template<typename T>
void problem7(Queue<T>& qP)
{
	qP.enqueue(7);
	qP.enqueue(6);
	qP.enqueue(5);
	qP.enqueue(4);
	qP.enqueue(3);
	qP.enqueue(2);
	qP.enqueue(1);

	T elem;
	while (!qP.isEmpty()) {
		elem = qP.dequeue();
		cout << "dequeue�� ���� : " << elem << endl;
	}
}

template<typename T>
void problem9(Queue<T>& qP)
{
	T elem;
	qP.enqueue(CPharmacy("�� �౹", 200, 40, "1��"));
	qP.enqueue(CPharmacy("�� �౹", 300, 80, "1�� 10��"));
	qP.enqueue(CPharmacy("�� �౹", 900, 20, "1�� 20��"));
	qP.enqueue(CPharmacy("�� �౹", 100, 30, "1�� 30��"));
	qP.enqueue(CPharmacy("�� �౹", 500, 10, "1�� 40��"));
	qP.enqueue(CPharmacy("�� �౹", 700, 50, "1�� 50��"));
	qP.enqueue(CPharmacy("�� �౹", 400, 100, "2��"));
	qP.enqueue(CPharmacy("�� �౹", 1000, 70, "2�� 10��"));
	qP.enqueue(CPharmacy("ġ �౹", 600, 60, "2�� 20��"));
	qP.enqueue(CPharmacy("�� �౹", 800, 90, "2�� 30��"));
	cout << "enqueue�� ���� :\n ";
	problem2(qP);
	
	cout << "dequeue�� ���� :\n ";
	while (!qP.isEmpty()) {
		elem = qP.dequeue();
		cout << elem << " ";
	}
	
}