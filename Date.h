#pragma once
class Date
{
	int month;
	int day;
	int year;
public:
	Date(int = 0, int = 0, int = 0);
	void print();
	~Date();
};

