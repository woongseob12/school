#pragma once
#include <string>
using namespace std;

class Drugstore
{
public:
	Drugstore();
	Drugstore(string, int, int, int);
	void setInfo(string,int,int, int);
	string getName();
	int getMaskCnt();
	void showInfo(int);
private:
	string name;
	int distance;
	int maskCnt;
	int maskTime;
};

