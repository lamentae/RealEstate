#pragma once
#include <iostream>
#include <string>
#include "ClientBuyer.h" // might be something messed up with the includes, they are looking good so far...
#include "RealEstateAgent.h"
#include "Date.h" // Added a bunch to be safe.
#include "ClientSeller.h"
#include "Person.h"



class Property
{
private:

	std::string street_address;
	int year_of_built;
	int no_of_rooms;
	int price;
	bool property_status;
	ClientSeller* landlord;
	RealEstateAgent* seller_agent;
	Date listing_date;
	ClientBuyer* buyer_client;


public:

	void setlandlord(ClientSeller*);

	int getprice();
	bool getproperty_status();
	RealEstateAgent* getseller_agent();


	Property(std::string = "", int = 0, int = 0, int = 0, ClientSeller* = nullptr, RealEstateAgent* = nullptr, Date = Date());
	virtual void print();
	virtual void property_sold(ClientBuyer*); // Not sure about void return type. Not specified in Assignment
	virtual ~Property();
};

