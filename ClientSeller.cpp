#include "ClientSeller.h"
#include "CondoSale.h"

using namespace std;

ClientSeller::ClientSeller(string pname, Date bday, RealEstateAgent* agentptr, Property* ptr)
	: Client(pname, bday, agentptr)
{
	ptr->setlandlord(this);			// when a client seller is the property is passed as a parameter and the constructor will set the landlord data member in class Property
	property_on_sale = ptr;

}

void ClientSeller::print()
{
    property_on_sale->Property::print();
};

void ClientSeller::earnings(int)
{

}

ClientSeller::~ClientSeller()
{

}

