
#pragma once
#include "RealEstateAgent.h"
#include "Property.h"
#include "Person.h"
#include "Client.h"
#include "ClientBuyer.h"

class RealEstateManager
{
private:

	static int const max_number_of_agents = 30;
	static int const max_no_clients = 200;
	static int const listingsize = 1000;
	RealEstateAgent* agentListingArray[max_number_of_agents];
	Property* propertyListingArray[listingsize];
	Person* clientListingArray[max_no_clients];

public:

	RealEstateManager();
	bool insertAgent(RealEstateAgent*);				// insert agent function into first agentlistingarray
	bool insertProperty(Property*);					//insert property into first available location in propertylistingrray.
	bool insertClient(Client*);						// same but for clientlistingarray
	
	bool property_sold(Property*, ClientBuyer*);		// update clientbuyer and update earnings of real estate agent
	void findHouseProperties();							// finds all available properties for sale and prints them. Need to use dynamic_cast, see assignment
	void findPropertiesAgent(RealEstateAgent*);			// determines all property listings of an agent and prints them.

	~RealEstateManager();
};

