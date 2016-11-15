#pragma once
#include <string>
#include "Person.h"

class RealEstateAgent:public Person
{
private:
	Date employment_date;
	static int total_employee_id;
	int employee_id;
	int total_earnings; 
public:
	RealEstateAgent(std::string, Date, Date, int); // string comes from the name data member in class person
	virtual void print();		// first Date is birthdate from class person, second is employment date.
	virtual void earnings(int);
	~RealEstateAgent();
};

