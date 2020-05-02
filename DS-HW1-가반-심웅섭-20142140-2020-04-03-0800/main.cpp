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
- ����ũ ���Ÿ� ���� �౹�̸�, �Ÿ�, ����ũ �����ܷ�, ����ũ �����ð��� ��Ÿ����

Operations:
- void makeAry(Drugstore*)
Precondition: �⺻ �����ڷ� ������ Drugstore ��ü�� �迭
Postcondition: ��ü�� ������ �Է�
Returns: ����

- void displayAry(Drugstore*)
Precondition: Drugstore Ŭ������ �迭
Postcondition: ȭ�鿡 Drugstore�迭�� ��ü ���� ���
Returns: ����

- void selSort(Drugstore*)
Precondition: Drugstore Ŭ������ �迭
Postcondition: selection sort�� ���� �̸������� ���� �� Drugstore Ŭ���� �迭 ȭ�鿡 ���
Returns: ����

- void classSwap(Drugstore*, Drugstore*)
Precondition: �� ���� Drugstore Ŭ���� ��ü
Postcondition: �� ���� Drugstore ��ü�� �迭���� ��ġ�� ���� �ٲ�
Returns: ����

- void binarySearch(Drugstore*, int, string)
Precondition: �̸��� �������� ������������ ���ĵ� Drugstore �迭
Postcondition: Drugstore�ȿ� �ش��ϴ� �����Ͱ� �ִ��� ������ �Ǻ� �� �׿� ���� ��� ���
Returns: ����

- void quickSort(Drugstore*, int, int)
Precondition: Drugstore ��ü �迭
Postcondition: Drugstore ��ü �迭�� �ܿ� ����ũ ������ �������� ������������ ����
Returns: ����

- int partition(Drugstore*, int, int)
Precondition: Drugstore ��ü �迭
Postcondition: ���� ���� �������� ���ʿ��� ���غ��� ���� ��, �����ʿ��� ���غ��� ū ������ ����
Returns: ���� ��
*/

int main()
{
	int originalCompareCnt = 0, originalCalculationCnt = 0, originalSwapCnt = 0;
	cout << "\n���� 1---------------------------------------------------------------------------------------------------------\n" << endl;
	adt();
	Drugstore storeAry[ARY_SIZE];
	cout << "���� 2---------------------------------------------------------------------------------------------------------\n" << endl;
	makeAry(storeAry);
	quickSort(storeAry, 0, sizeof(storeAry) / sizeof(storeAry[0]) - 1);
	originalCompareCnt = compareCnt, originalCalculationCnt = calculationCnt, originalSwapCnt = swapCnt;
	selSort(storeAry);
	cout << "\n���� 3---------------------------------------------------------------------------------------------------------\n" << endl;
	//�����Ϳ� �ִ� �౹��
	binarySearch(storeAry, sizeof(storeAry)/ sizeof(storeAry[0]), "�����౹");
	//�����Ϳ� ���� �౹��
	binarySearch(storeAry, sizeof(storeAry) / sizeof(storeAry[0]), "��ž�౹");
	cout << "\n���� 4---------------------------------------------------------------------------------------------------------\n" << endl;
	compareCnt = 0, calculationCnt = 0, swapCnt = 0;
	quickSort(storeAry, 0, sizeof(storeAry) / sizeof(storeAry[0]) -1);
	cout << "quicksort�� ���� ����ũ ���� �ܷ������� ���� : \n" << endl;
	displayAry(storeAry);
	cout << "\n���� 5---------------------------------------------------------------------------------------------------------\n" << endl;
	cout << "ó�� �迭�� quicksort ���� ���� :";
	cout << "�񱳹� Ƚ��(" << originalCompareCnt << ") + ����� Ƚ��(" << originalCalculationCnt << ") + swap Ƚ��(" << originalSwapCnt << ") = " << originalCompareCnt + originalCalculationCnt + originalSwapCnt << endl;
	cout << "\n�̸����� ���ĵ� �迭�� quicksort ���� ���� : ";
	cout << "�񱳹� Ƚ��(" << compareCnt << ") + ����� Ƚ��(" << calculationCnt << ") + swap Ƚ��(" << swapCnt << ") = " << compareCnt + calculationCnt + swapCnt << endl;
	cout << "\n��� �м� :\nquicksort�� �迭�� ù ���� ���� ������ �迭�� �����ϴµ�, ���� �迭�� ù ��ü�� ����ũ �ܷ��� ���� '6', �̸����� ���ĵ� �迭�� ù ��ü�� ����ũ �ܷ��� ���� '24'�� ���� �迭�� ù ���� �ξ� ���� ������ ���� ���ذ����� �� ���� ����Ƚ���� �迭�� �����Ͽ���. ���� �迭�ȿ� ����� data�� ������ ���ĵ� ���¿� ���� ����� swapȽ���� ���̰� ���ٴ� ���� �� �� �ִ�."<< endl;
	cout << "\n---------------------------------------------------------------------------------------------------------------\n" << endl;
}

void adt()
{
	const char* msg =
		"Characteristics:\n"
		"-����ũ ���Ÿ� ���� �౹�̸�, �Ÿ�, ����ũ �����ܷ�, ����ũ �����ð��� ��Ÿ����\n"
		"\n"
		"Operations :\n"
		"- void makeAry(Drugstore*)\n"
		"	Precondition: �⺻ �����ڷ� ������ Drugstore ��ü�� �迭\n"
		"	Postcondition : ��ü�� ������ �Է� �� ȭ�鿡 ���\n"
		"	Returns : ����\n"
		"\n"
		"- void displayAry(Drugstore*)\n"
		"	Precondition : Drugstore Ŭ������ �迭\n"
		"	Postcondition : ȭ�鿡 Drugstore�迭�� ��ü ���� ���\n"
		"	Returns : ����\n"
		"\n"
		"- void selSort(Drugstore*)\n"
		"	Precondition : Drugstore Ŭ������ �迭\n"
		"	Postcondition : selection sort�� ���� �̸������� ���� �� Drugstore Ŭ���� �迭 ȭ�鿡 ���\n"
		"	Returns : ����\n"
		"\n"
		"- void classSwap(Drugstore*, Drugstore*)\n"
		"	Precondition : �� ���� Drugstore Ŭ���� ��ü\n"
		"	Postcondition : �� ���� Drugstore ��ü�� �迭���� ��ġ�� ���� �ٲ�\n"
		"	Returns : ����\n"
		"\n"
		"-void binarySearch(Drugstore*, int, string)\n"
		"	Precondition: �̸��� �������� ������������ ���ĵ� Drugstore �迭\n"
		"	Postcondition : Drugstore ��ü �迭�ȿ� �ش��ϴ� �����Ͱ� �ִ��� ������ �Ǻ� �� �׿� ���� ��� ���\n"
		"	Returns : ����\n"
		"\n"
		"- void quickSort(Drugstore*, int, int)\n"
		"	Precondition: Drugstore ��ü �迭\n"
		"	Postcondition : Drugstore ��ü �迭�� �ܿ� ����ũ ������ �������� ������������ ����\n"
		"	Returns : ����\n"
		"\n"
		"- int partition(Drugstore*, int, int)\n"
		"	Precondition: Drugstore ��ü �迭\n"
		"	Postcondition : ���� ���� �������� ���ʿ��� ���غ��� ���� ��, �����ʿ��� ���غ��� ū ������ ����\n"
		"	Returns : ���� ��\n";

		cout << msg << endl;
}

void makeAry(Drugstore* dP)
{
	dP[0].setInfo("�̸ž౹",8,6,14);
	dP[1].setInfo("ǳ���౹",5,14,13);
	dP[2].setInfo("â�ξ౹",9,19,9);
	dP[3].setInfo("�����౹",1,0,8);
	dP[4].setInfo("�̱ݾ౹",22,7,15);
	dP[5].setInfo("�д�౹",17,9,13);
	dP[6].setInfo("�����౹",9,13,18);
	dP[7].setInfo("�����౹",13,3,15);
	dP[8].setInfo("�ݰ�౹",33,24,12);
	dP[9].setInfo("�Ǳ��౹",18,0,13);
	cout << "���� : \n" << endl;
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
	cout << "\nselection sort�� ���� �̸� ������ ���� : \n" << endl;
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
			cout << "ã�� �౹ : ";
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
	cout << "ã�� �౹ : \"" << find << "\"�� �ش��ϴ� �౹�� �����ϴ�." << endl;
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
