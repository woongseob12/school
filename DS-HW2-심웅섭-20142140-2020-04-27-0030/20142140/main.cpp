#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "CPharmacy.h"
using namespace std;

template<typename T>
void problem1(List<T>&);	// 정순 출력
template<typename T>
void problem2(List<T>&);	// 역순 출력
template<typename T>
void problem3(List<T>&);	// 원소 제거
template<typename T>
void problem4(List<T>&);	// 첫번째 원소, 마지막 원소 제거
template<typename T>
void problem5(List<T>&);	// Tail 넣기
template<typename T>
void problem6(Stack<T>&);	// Stack 구현
template<typename T>
void problem7(Queue<T>&);	// Queue 구현
template<typename T>
void problem9(Queue<T>&);	// 약국 클래스

int main()
{
	List<int> l;

	cout << "문제 1 ----------------------------------" << endl;
	cout << "# head쪽으로 역순으로 넣어서 first & next를 사용하여 출력하기" << endl;
	l.insert(7);
	l.insert(6);
	l.insert(5);
	l.insert(4);
	l.insert(3);
	l.insert(2);
	l.insert(1);
	problem1(l);
	cout << "\n문제 2 ----------------------------------" << endl;
	cout << "# head쪽으로 넣어서 last & previous를 사용하여 출력하기" << endl;
	problem2(l);
	cout << "\n문제 3 ----------------------------------" << endl;
	cout << "#  head쪽으로 넣어서 5, 7, 1 순서로 타겟 원소 제거 후 2번처럼 출력하기" << endl;
	problem3(l);
	l.clear();
	cout << "\n문제 4 ----------------------------------" << endl;
	cout << "# head쪽으로 넣어서 첫번째, 마지막 원소 찾아서 가져오고 제거 후 1번처럼 출력하기" << endl;
	l.insert(7);
	l.insert(6);
	l.insert(5);
	l.insert(4);
	l.insert(3);
	l.insert(2);
	l.insert(1);
	problem4(l);
	cout << "\n문제 5 ----------------------------------" << endl;
	cout << "# tail쪽으로 넣어 1번처럼 출력하기" << endl;
	l.clear();
	problem5(l);
	cout << "\n문제 6 ----------------------------------" << endl;
	cout << "# Stack 구현하기(LIFO)" << endl;
	Stack<int> s;
	problem6(s);
	cout << "\n문제 7 ----------------------------------" << endl;
	cout << "# Queue 구현하기(FIFO)" << endl;
	Queue<int> q;
	problem7(q);
	cout << "\n문제 9 ----------------------------------" << endl;
	cout << "# Template & Operator overloading을 통해 약국 클래스 구현 및 enqueue 와 dequeue 출력하기" << endl;
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
	cout << "첫 번째 원소 : " << firstElem;
	lP.GetLast(elem);
	cout << "\t마지막 원소 : " << elem << endl;
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
		cout << "pop한 원소 : " << elem;
		if (sP.isEmpty()) {
			cout << "\tTop 원소 : NULL" << endl;
		}
		else {
			sP.top(elem);
			cout << "\tTop 원소 : " << elem << endl;
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
		cout << "dequeue한 원소 : " << elem << endl;
	}
}

template<typename T>
void problem9(Queue<T>& qP)
{
	T elem;
	qP.enqueue(CPharmacy("스 약국", 200, 40, "1시"));
	qP.enqueue(CPharmacy("고 약국", 300, 80, "1시 10분"));
	qP.enqueue(CPharmacy("텐 약국", 900, 20, "1시 20분"));
	qP.enqueue(CPharmacy("도 약국", 100, 30, "1시 30분"));
	qP.enqueue(CPharmacy("닌 약국", 500, 10, "1시 40분"));
	qP.enqueue(CPharmacy("위 약국", 700, 50, "1시 50분"));
	qP.enqueue(CPharmacy("요 약국", 400, 100, "2시"));
	qP.enqueue(CPharmacy("사 약국", 1000, 70, "2시 10분"));
	qP.enqueue(CPharmacy("치 약국", 600, 60, "2시 20분"));
	qP.enqueue(CPharmacy("파 약국", 800, 90, "2시 30분"));
	cout << "enqueue한 원소 :\n ";
	problem2(qP);
	
	cout << "dequeue한 원소 :\n ";
	while (!qP.isEmpty()) {
		elem = qP.dequeue();
		cout << elem << " ";
	}
	
}