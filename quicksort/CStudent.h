#pragma once
class CStudent
{
public:
	void setId(int);
	int getId();
	bool operator<=(CStudent &);
private:
	int id;
};
