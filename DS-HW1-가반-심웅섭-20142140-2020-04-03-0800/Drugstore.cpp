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
	cout << setw(2) <<n+1 <<".약국 이름 : " << name << "\t  약국 거리 : " << distance << "km\t  마스크 보유 잔량 : " << maskCnt << "\t  마스크 도착 시간 : " << setw(2) << maskTime <<"시" << endl;
}