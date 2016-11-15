

// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "Client.h"
#include "ClientBuyer.h"
#include "ClientSeller.h"
#include "CondoSale.h"
#include "Date.h"
#include "HouseSale.h"
#include "Person.h"
#include "Property.h"
#include "RealEstateAgent.h"
#include "RealEstateManager.h"
using namespace std;

int main()
{
	//create manager object and pointers to various objects
	RealEstateManager* manager = nullptr;
	manager = new RealEstateManager();
	bool inserted = false;

	Date* date = new Date(11, 11, 2016);

	Property* property_array[6];

	for (int i = 0; i < 6; i++) {
		property_array[i] = nullptr;
	}

	RealEstateAgent* agentptr[2];
	agentptr[0] = nullptr;
	agentptr[1] = nullptr;

	Client* clientptr[12];
	for (int i = 0; i < 12; i++) {
		clientptr[i] = nullptr;
	}

	

	//create agent
	agentptr[0] = new RealEstateAgent("Agent1", *date, *date, 30000);
	agentptr[1] = new RealEstateAgent("Agent2", *date, *date, 30000);

	// create property and pass an agent as parameter, client seller set to nullptr
	property_array[0] = new CondoSale("address1", 2001, 3, 275000, 300, nullptr, agentptr[0], *date);
	property_array[1] = new HouseSale("address2", 2002, 4, 500000, 7000, nullptr, agentptr[1], *date);
	property_array[2] = new CondoSale("address3", 2003, 5, 600000, 600, nullptr, agentptr[0], *date);
	property_array[3] = new HouseSale("address4", 2004, 6, 1000000, 15000, nullptr, agentptr[1], *date);
	property_array[4] = new HouseSale("address5", 2005, 2, 300000, 6500, nullptr, agentptr[0], *date);
	property_array[5] = new CondoSale("address6", 2006, 1, 200000, 100, nullptr, agentptr[1], *date);

	// create seller and pass a property and an agent as parameter
	for (int i = 0; i < 6; i++) {
		clientptr[i] = new ClientSeller("ClientSeller", *date, agentptr[i % 2], property_array[i]);
	}

	// call insert agent
	for (int i = 0; i < 6; i++) {
		inserted = manager->insertAgent(agentptr[i % 2]);
	}


	// call insert property
	for (int i = 0; i < 6; i++) {
		inserted = manager->insertProperty(property_array[i]);
	}

	// call insert client
	for (int i = 0; i < 6; i++) {
		inserted = manager->insertClient(clientptr[i]);
	}

	// create a buyer with real estate agent pointer set to nullptr

	clientptr[6] = new ClientBuyer("ClientBuyer1", *date, nullptr, "Condo", 300000);
	clientptr[7] = new ClientBuyer("ClientBuyer1", *date, nullptr, "House", 400000);
	clientptr[8] = new ClientBuyer("ClientBuyer1", *date, nullptr, "Condo", 500000);
	clientptr[9] = new ClientBuyer("ClientBuyer1", *date, nullptr, "House", 600000);
	clientptr[10] = new ClientBuyer("ClientBuyer1", *date, nullptr, "Condo", 700000);
	clientptr[11] = new ClientBuyer("ClientBuyer1", *date, nullptr, "House", 8000000);

	// call insert client again to insert buyers
	for (int i = 0; i < 12; i++) {
		inserted = manager->insertClient(clientptr[i]);
	}

	// call find properties print all properties for sale should output 6 properties
	manager->findHouseProperties();

	// cast a client pointer into a client buyer pointer and call property sold to assign a buyer to a property this is the function that sells the property
	ClientBuyer* bptr = dynamic_cast<ClientBuyer*>(clientptr[6]);
	property_array[0]->property_sold(bptr); //selling 
	// call property sold update earnings of agent
	manager->property_sold(property_array[0], bptr);// sold updating


	// call find properties print all properties for sale should output 5 properties 
	manager->findHouseProperties();
	// call find properties agent and print all properties associated with that agent both sold and not sold properties will be printed
	manager->findPropertiesAgent(agentptr[0]);

	system("PAUSE");
	return 0;
}