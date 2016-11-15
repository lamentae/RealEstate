#pragma once
#include <string>
#include "Person.h"
#include "RealEstateAgent.h"

class Client:public Person
{

private:
	RealEstateAgent* my_agent;

public:
	Client(std::string, Date, RealEstateAgent*);
	virtual void print();
	virtual void earnings(int);

	~Client();
};

