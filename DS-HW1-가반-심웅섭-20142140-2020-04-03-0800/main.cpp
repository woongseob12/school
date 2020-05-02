#define ARY_SIZE 10
#include <iostream>
#include "drugstore.h"

using namespace std;

void adt();
void makeAry(Drugstore*);
void displayAry(Drugstore*);
void selSort(Drugstore*);
void classSwap(Drugstore*, Drugstore*);
void binarySearch(Drugstore*, int, string);
void quickSort(Drugstore*, int, int);
int partition(Drugstore*, int, int);

int compareCnt = 0, calculationCnt = 0, swapCnt = 0;
/*
Characteristics:
- 마스크 구매를 위해 약국이름, 거리, 마스크 보유잔량, 마스크 도착시간을 나타낸다

Operations:
- void makeAry(Drugstore*)
Precondition: 기본 생성자로 생성된 Drugstore 객체의 배열
Postcondition: 객체에 정보를 입력
Returns: 없음

- void displayAry(Drugstore*)
Precondition: Drugstore 클래스의 배열
Postcondition: 화면에 Drugstore배열의 객체 정보 출력
Returns: 없음

- void selSort(Drugstore*)
Precondition: Drugstore 클래스의 배열
Postcondition: selection sort를 통해 이름순으로 정렬 후 Drugstore 클래스 배열 화면에 출력
Returns: 없음

- void classSwap(Drugstore*, Drugstore*)
Precondition: 두 개의 Drugstore 클래스 객체
Postcondition: 두 개의 Drugstore 객체의 배열내의 위치를 서로 바꿈
Returns: 없음

- void binarySearch(Drugstore*, int, string)
Precondition: 이름을 기준으로 오름차순으로 정렬된 Drugstore 배열
Postcondition: Drugstore안에 해당하는 데이터가 있는지 없는지 판별 후 그에 따른 결과 출력
Returns: 없음

- void quickSort(Drugstore*, int, int)
Precondition: Drugstore 객체 배열
Postcondition: Drugstore 객체 배열이 잔여 마스크 수량을 기준으로 오름차순으로 정렬
Returns: 없음

- int partition(Drugstore*, int, int)
Precondition: Drugstore 객체 배열
Postcondition: 기준 값을 기준으로 왼쪽에는 기준보다 작은 값, 오른쪽에는 기준보다 큰 값으로 정렬
Returns: 기준 값
*/

int main()
{
	int originalCompareCnt = 0, originalCalculationCnt = 0, originalSwapCnt = 0;
	cout << "\n문제 1---------------------------------------------------------------------------------------------------------\n" << endl;
	adt();
	Drugstore storeAry[ARY_SIZE];
	cout << "문제 2---------------------------------------------------------------------------------------------------------\n" << endl;
	makeAry(storeAry);
	quickSort(storeAry, 0, sizeof(storeAry) / sizeof(storeAry[0]) - 1);
	originalCompareCnt = compareCnt, originalCalculationCnt = calculationCnt, originalSwapCnt = swapCnt;
	selSort(storeAry);
	cout << "\n문제 3---------------------------------------------------------------------------------------------------------\n" << endl;
	//데이터에 있는 약국명
	binarySearch(storeAry, sizeof(storeAry)/ sizeof(storeAry[0]), "서현약국");
	//데이터에 없는 약국명
	binarySearch(storeAry, sizeof(storeAry) / sizeof(storeAry[0]), "야탑약국");
	cout << "\n문제 4---------------------------------------------------------------------------------------------------------\n" << endl;
	compareCnt = 0, calculationCnt = 0, swapCnt = 0;
	quickSort(storeAry, 0, sizeof(storeAry) / sizeof(storeAry[0]) -1);
	cout << "quicksort를 통해 마스크 보유 잔량순으로 정렬 : \n" << endl;
	displayAry(storeAry);
	cout << "\n문제 5---------------------------------------------------------------------------------------------------------\n" << endl;
	cout << "처음 배열의 quicksort 연산 개수 :";
	cout << "비교문 횟수(" << originalCompareCnt << ") + 산술문 횟수(" << originalCalculationCnt << ") + swap 횟수(" << originalSwapCnt << ") = " << originalCompareCnt + originalCalculationCnt + originalSwapCnt << endl;
	cout << "\n이름으로 정렬된 배열의 quicksort 연산 개수 : ";
	cout << "비교문 횟수(" << compareCnt << ") + 산술문 횟수(" << calculationCnt << ") + swap 횟수(" << swapCnt << ") = " << compareCnt + calculationCnt + swapCnt << endl;
	cout << "\n결과 분석 :\nquicksort는 배열의 첫 값을 기준 값으로 배열을 정렬하는데, 원래 배열의 첫 객체의 마스크 잔량의 값은 '6', 이름으로 정렬된 배열의 첫 객체의 마스크 잔량의 값은 '24'로 원래 배열의 첫 값이 훨씬 값을 나누기 좋은 기준값으로 더 적은 연산횟수로 배열을 정렬하였다. 또한 배열안에 저장된 data가 같더라도 정렬된 상태에 따라 산술과 swap횟수가 차이가 난다는 것을 알 수 있다."<< endl;
	cout << "\n---------------------------------------------------------------------------------------------------------------\n" << endl;
}

void adt()
{
	const char* msg =
		"Characteristics:\n"
		"-마스크 구매를 위해 약국이름, 거리, 마스크 보유잔량, 마스크 도착시간을 나타낸다\n"
		"\n"
		"Operations :\n"
		"- void makeAry(Drugstore*)\n"
		"	Precondition: 기본 생성자로 생성된 Drugstore 객체의 배열\n"
		"	Postcondition : 객체에 정보를 입력 후 화면에 출력\n"
		"	Returns : 없음\n"
		"\n"
		"- void displayAry(Drugstore*)\n"
		"	Precondition : Drugstore 클래스의 배열\n"
		"	Postcondition : 화면에 Drugstore배열의 객체 정보 출력\n"
		"	Returns : 없음\n"
		"\n"
		"- void selSort(Drugstore*)\n"
		"	Precondition : Drugstore 클래스의 배열\n"
		"	Postcondition : selection sort를 통해 이름순으로 정렬 후 Drugstore 클래스 배열 화면에 출력\n"
		"	Returns : 없음\n"
		"\n"
		"- void classSwap(Drugstore*, Drugstore*)\n"
		"	Precondition : 두 개의 Drugstore 클래스 객체\n"
		"	Postcondition : 두 개의 Drugstore 객체의 배열내의 위치를 서로 바꿈\n"
		"	Returns : 없음\n"
		"\n"
		"-void binarySearch(Drugstore*, int, string)\n"
		"	Precondition: 이름을 기준으로 오름차순으로 정렬된 Drugstore 배열\n"
		"	Postcondition : Drugstore 객체 배열안에 해당하는 데이터가 있는지 없는지 판별 후 그에 따른 결과 출력\n"
		"	Returns : 없음\n"
		"\n"
		"- void quickSort(Drugstore*, int, int)\n"
		"	Precondition: Drugstore 객체 배열\n"
		"	Postcondition : Drugstore 객체 배열이 잔여 마스크 수량을 기준으로 오름차순으로 정렬\n"
		"	Returns : 없음\n"
		"\n"
		"- int partition(Drugstore*, int, int)\n"
		"	Precondition: Drugstore 객체 배열\n"
		"	Postcondition : 기준 값을 기준으로 왼쪽에는 기준보다 작은 값, 오른쪽에는 기준보다 큰 값으로 정렬\n"
		"	Returns : 기준 값\n";

		cout << msg << endl;
}

void makeAry(Drugstore* dP)
{
	dP[0].setInfo("이매약국",8,6,14);
	dP[1].setInfo("풍림약국",5,14,13);
	dP[2].setInfo("창인약국",9,19,9);
	dP[3].setInfo("서현약국",1,0,8);
	dP[4].setInfo("미금약국",22,7,15);
	dP[5].setInfo("분당약국",17,9,13);
	dP[6].setInfo("돌마약국",9,13,18);
	dP[7].setInfo("수내약국",13,3,15);
	dP[8].setInfo("금곡약국",33,24,12);
	dP[9].setInfo("판교약국",18,0,13);
	cout << "기존 : \n" << endl;
	displayAry(dP);
}

void displayAry(Drugstore* dP)
{
	for (int i = 0; i < ARY_SIZE; i++) {
		dP[i].showInfo(i);
	}
}

void selSort(Drugstore* dP)
{
	string temp;
	int least = -1;
	cout << "\nselection sort를 통해 이름 순으로 정렬 : \n" << endl;
	for (int i = 0; i < ARY_SIZE - 1; i++) {
		temp = dP[i].getName();
		for (int j = i + 1; j < ARY_SIZE; j++) {
			if (dP[j].getName() < temp) {
				temp = dP[j].getName();
				least = j;
			}
		}
		if (dP[i].getName() != temp && least != -1) {
			classSwap(&dP[i], &dP[least]);
		}
	}
	displayAry(dP);
}

void classSwap(Drugstore* a, Drugstore* b)
{
	Drugstore temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void binarySearch(Drugstore* dP, int size, string find)
{
	int first = 0;
	int last = size - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (find == dP[mid].getName()) {
			cout << "찾는 약국 : ";
			dP[mid].showInfo(mid);
			cout << endl;
			return ;
		}
		else if (find < dP[mid].getName()) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}
	cout << "찾는 약국 : \"" << find << "\"에 해당하는 약국이 없습니다." << endl;
	return;
}

void quickSort(Drugstore* dP, int first, int last)
{
	if (first >= last) { return; }
	int split = partition(dP, first, last);

	calculationCnt++;
	quickSort(dP, first, split - 1);
	calculationCnt++;
	quickSort(dP, split + 1, last);
}

int partition(Drugstore* dP, int first, int last)
{
	int pivot = first;

	for (int i = first + 1; i <= last; i++) {
		compareCnt++;
		if (dP[i].getMaskCnt() <= dP[first].getMaskCnt()) {
			calculationCnt++;
			pivot++;
			classSwap(&dP[i], &dP[pivot]);
			swapCnt++;
		}
	}
	classSwap(&dP[first], &dP[pivot]);
	swapCnt++;

	return pivot;
}
