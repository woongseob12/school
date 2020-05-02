//
// ����ũ ���� ���α׷� ADT
//
// Characteristics:
//    �� ���α׷��� �౹�� ������ �����ϰ� �����ִ� ���α׷��̴�.
//    �౹�� �������� �౹ �̸�, �Ÿ�, ����ũ �����ܷ�, ����ũ �����ð��� �ִ�.
//    �౹�� ������ ��� �����ϰų�, ������ �� ������, �̸��� ����ũ �����ܷ��� ���� �����ϰ� ���� ������ �� �ִ�. 
//
// Operations:
//void ShowPharmacy()
//    Precondition: �౹�� ������ �����Ǿ�� ��.
//    Postcondition: None.
//    return: None.
//void setPharmacyName(string strPharmacyName)
//    Precondition: �౹ ��ü�� �����Ǿ�� ��.
//    Postcondition: m_strPharmacyName�� ���� strPharmacyName�� ���� ��.
//    return: None.
//string getPharmacyName()
//    Precondition: m_strPharmacyName�� ���� �����Ǿ�� ��.
//    Postcondition: None.
//    return: m_strPharmacyName�� ���� return��.
//void setRemaining(int nRemaining)
//    Precondition: �౹ ��ü�� �����Ǿ�� ��.
//    Postcondition: m_nRemaining�� ���� nRemaining�� ���� ��.
//    return: None.
//int getRemaining()
//    Precondition: m_nRemaining�� ���� �����Ǿ�� ��.
//    Postcondition: None.
//    return: m_nRemaining�� ���� return��.


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