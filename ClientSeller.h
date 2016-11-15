#pragma once
#include <string>
#include <iostream>
#include "Client.h"


class Property;
class ClientSeller:public Client
{
private:
	Property* property_on_sale;
public:
	ClientSeller(std::string, Date, RealEstateAgent*, Property*);
	virtual void print();
	virtual void earnings(int);
	Property * getproperty_on_sale();
	~ClientSeller();
};

