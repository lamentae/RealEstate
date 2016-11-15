#pragma once
#include <iostream>
#include <string>
#include "Property.h"
#include "ClientSeller.h"
#include "ClientBuyer.h"

class HouseSale: public Property
{
private:
	int total_land;
public:
	HouseSale(std::string = "House", int=0, int=0, int=0, int=0, ClientSeller* = nullptr, RealEstateAgent* = nullptr, Date = Date()); 
	virtual void print(); 
	~HouseSale();
};

