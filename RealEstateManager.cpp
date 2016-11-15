#include "RealEstateManager.h"
#include <iostream>
#include "CondoSale.h"
#include "HouseSale.h"
#include "Property.h"
#include "RealEstateAgent.h"
using namespace std;

RealEstateManager::RealEstateManager()
{
	//initialize arrays to nullptrs
	for(int i = 0; i < max_number_of_agents; i++) {
		agentListingArray[i] = nullptr;
	}
	for (int i = 0; i < listingsize; i++) {
		propertyListingArray[i] = nullptr;
	}
	for (int i = 0; i < max_no_clients; i++) {
		clientListingArray[i] = nullptr;
	}
}


RealEstateManager::~RealEstateManager()
{
}

// insert agent function into first agentlistingarray, loop through arrays, check if the current element is a nullptr if yes then insert and return otherwise next
bool RealEstateManager::insertAgent(RealEstateAgent* agptr)
{

	for (int i = 0; i < max_number_of_agents; i++) {
		if (agentListingArray[i] == nullptr) {
			agentListingArray[i] = agptr;
			return true;
		}

	}

	return false;
}

//insert property into first available location in propertylistingrray.
bool RealEstateManager::insertProperty(Property* ptr)
{
	for (int i = 0; i < listingsize; i++) {
		if (propertyListingArray[i] == nullptr) {
			propertyListingArray[i] = ptr;
			return true;
		}
	}
	return false;
}

// same but for clientlistingarray
bool RealEstateManager::insertClient(Client* clientptr)
{
	for (int i = 0; i < max_no_clients; i++) {
		if (clientListingArray[i] == nullptr) {
			clientListingArray[i] = clientptr;
			return true;
		}
	}
	return false;
}





// once a property has been sold update earnings of real estate agent and print the earnings before and after sale
bool RealEstateManager::property_sold(Property* proptr, ClientBuyer* bptr)
{
	int price = proptr->getprice();
 
        RealEstateAgent* agptr = proptr->getseller_agent();
		agptr->print();
        agptr->earnings(price);
		
        cout << "Agent Earnings Updated." <<endl;
		agptr->print();

	return false;
}

// finds all available properties for sale and prints them, loop properties, check if the property has been sold, if not call print.
void RealEstateManager::findHouseProperties()
{
	cout << "These are the available Properties" << endl << endl;
	bool sold = false;
	for (int i = 0; i < listingsize; i++) {
		if (propertyListingArray[i] != nullptr) {
			sold = propertyListingArray[i]->getproperty_status();
			if (!sold) {
                    propertyListingArray[i]->print();
					propertyListingArray[i]->Property::print();
					cout << endl << endl;
			}
		}
	}
}



// determines all property listings of an agent and prints them. uses the getseller_agent function in property class to compare agents
void RealEstateManager::findPropertiesAgent(RealEstateAgent* agptr)
{
	cout << "These are the Properties listed to the Agent" << endl << endl;
    RealEstateAgent* agptrtemp = nullptr;
    for(int i = 0 ; i < listingsize; i++) {
        if(propertyListingArray[i] == nullptr){continue;}

        agptrtemp = propertyListingArray[i]->getseller_agent();

            if(agptr == agptrtemp ){
                propertyListingArray[i]->print();
                propertyListingArray[i]->Property::print();
                cout << endl << endl;

            }

    }
}

