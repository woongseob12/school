#include "CStudent.h"

void CStudent::setId(int id)
{
	this->id = id;
}

int CStudent::getId()
{
	return id;
}

bool CStudent::operator<=(CStudent &t)
{
	if (this->getId() <= t.getId()) {
		return true;
	}
	return false;
}