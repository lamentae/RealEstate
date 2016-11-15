#pragma once
#include <string>
#include "Property.h"
#include "ClientSeller.h"
#include "ClientBuyer.h"

class CondoSale:public Property
{

private:
	int condo_fee;

public:
	CondoSale(std::string = "address", int = 0, int = 0 , int = 0, int = 0, ClientSeller* = nullptr, RealEstateAgent* = nullptr, Date = Date());
	virtual void print();
	~CondoSale();
};

