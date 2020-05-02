//
// 마스크 구매 프로그램 ADT
//
// Characteristics:
//    이 프로그램은 약국의 정보를 설정하고 보여주는 프로그램이다.
//    약국의 정보에는 약국 이름, 거리, 마스크 보유잔량, 마스크 도착시간이 있다.
//    약국의 정보를 모두 설정하거나, 보여줄 수 있으며, 이름과 마스크 보유잔량만 각각 설정하고 값을 가져올 수 있다. 
//
// Operations:
//void ShowPharmacy()
//    Precondition: 약국의 정보가 설정되어야 함.
//    Postcondition: None.
//    return: None.
//void setPharmacyName(string strPharmacyName)
//    Precondition: 약국 객체가 생성되어야 함.
//    Postcondition: m_strPharmacyName의 값이 strPharmacyName의 값이 됨.
//    return: None.
//string getPharmacyName()
//    Precondition: m_strPharmacyName의 값이 설정되어야 함.
//    Postcondition: None.
//    return: m_strPharmacyName의 값이 return됨.
//void setRemaining(int nRemaining)
//    Precondition: 약국 객체가 생성되어야 함.
//    Postcondition: m_nRemaining의 값이 nRemaining의 값이 됨.
//    return: None.
//int getRemaining()
//    Precondition: m_nRemaining의 값이 설정되어야 함.
//    Postcondition: None.
//    return: m_nRemaining의 값이 return됨.


#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

class CPharmacy
{
public:
	CPharmacy();
	CPharmacy(string strPharmacyName, int nDistance, int nRemaining, string strArrivalTime);


	void ShowPharmacy();

	void setPharmacyName(string strPharmacyName);
	string getPharmacyName();
	void setRemaining(int nRemaining);
	int getRemaining();

private:
	string m_strPharmacyName;
	int m_nDistance;
	int m_nRemaining;
	string m_strArrivalTime;
};