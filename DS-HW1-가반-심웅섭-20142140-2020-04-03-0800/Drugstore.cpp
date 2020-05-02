#include "Drugstore.h"
#include <iostream>
#include <iomanip>

Drugstore::Drugstore()
{
	this->name = "";
	this->distance = 0;
	this->maskCnt = 0;
	this->maskTime = 0;
}

Drugstore::Drugstore(string name , int distance, int maskCnt, int maskTime)
{
	this->name = name;
	this->distance = distance;
	this->maskCnt = maskCnt;
	this->maskTime = maskTime;
}

void Drugstore::setInfo(string name, int distance, int maskCnt, int maskTime)
{	
	this->name = name;
	this->distance = distance;
	this->maskCnt = maskCnt;
	this->maskTime = maskTime;
}

string Drugstore::getName()
{
	return name;
}

int Drugstore::getMaskCnt()
{
	return maskCnt;
}

void Drugstore::showInfo(int n)
{
	cout << setw(2) <<n+1 <<".�౹ �̸� : " << name << "\t  �౹ �Ÿ� : " << distance << "km\t  ����ũ ���� �ܷ� : " << maskCnt << "\t  ����ũ ���� �ð� : " << setw(2) << maskTime <<"��" << endl;
}