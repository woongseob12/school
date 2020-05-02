#include "CPharmacy.h"

CPharmacy::CPharmacy()
	:m_strPharmacyName(""), m_nDistance(0), m_nRemaining(0), m_strArrivalTime("") {}

CPharmacy::CPharmacy(string strPharmacyName, int nDistance, int nRemaining, string strArrivalTime)
	:m_strPharmacyName(strPharmacyName), m_nDistance(nDistance), m_nRemaining(nRemaining), m_strArrivalTime(strArrivalTime) {}



void CPharmacy::ShowPharmacy()
{
	cout << "* 약국 이름 : " << m_strPharmacyName << ", 거리 : " << m_nDistance << " m, 마스크 보유 잔량 : "
		<< m_nRemaining << " 개, 마스크 도착 시간 : " << m_strArrivalTime << endl;
}


void CPharmacy::setPharmacyName(string strPharmacyName)
{
	m_strPharmacyName = strPharmacyName;
}

string CPharmacy::getPharmacyName()
{
	return m_strPharmacyName;
}

void CPharmacy::setRemaining(int nRemaining)
{
	m_nRemaining = nRemaining;
}

int CPharmacy::getRemaining()
{
	return m_nRemaining;
}