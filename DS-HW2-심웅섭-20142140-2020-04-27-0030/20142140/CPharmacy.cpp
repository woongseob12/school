#include "CPharmacy.h"

CPharmacy::CPharmacy()
	:m_strPharmacyName(""), m_nDistance(0), m_nRemaining(0), m_strArrivalTime("") {}

CPharmacy::CPharmacy(string strPharmacyName, int nDistance, int nRemaining, string strArrivalTime)
	:m_strPharmacyName(strPharmacyName), m_nDistance(nDistance), m_nRemaining(nRemaining), m_strArrivalTime(strArrivalTime) {}



void CPharmacy::ShowPharmacy()
{
	cout << "* �౹ �̸� : " << m_strPharmacyName << ", �Ÿ� : " << m_nDistance << " m, ����ũ ���� �ܷ� : "
		<< m_nRemaining << " ��, ����ũ ���� �ð� : " << m_strArrivalTime << endl;
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