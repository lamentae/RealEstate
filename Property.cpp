#include "Property.h"
#include "CondoSale.h"
#include "HouseSale.h"

using namespace std;

Property::Property(string address, int ybuilt, int nbroom, int cost, ClientSeller* cptr, RealEstateAgent* rptr, Date listingdate)
{
	street_address = address;
	year_of_built = ybuilt;
	no_of_rooms = nbroom;
	price = cost;
	property_status = false;
	landlord = cptr;
	seller_agent = rptr;
	listing_date = listingdate;
	buyer_client = nullptr;
	
}


void Property::print()
{

    std::string sold;
    if(property_status){sold = "YES";}
    if(!property_status){sold = "NO";}
	cout << "Address: " << street_address << endl;
	cout << "Year Built: " << year_of_built << endl;
	cout << "number of rooms: "<<no_of_rooms << endl;
	cout << "Price: $"<<price << endl;
	cout << "Sold: "<< sold<<endl;

}

//function will sell a property, casts the current object pointer into a condo or house and checks if it has been sold and that the buyer can afford the property.
//if the checks are good then the property status is set to true meaning it has been sold and sets the buyer_client data member to the current buyer
void Property::property_sold(ClientBuyer* buyerptr)
{
		CondoSale* condoptr = dynamic_cast<CondoSale*>(this);
		if (condoptr != nullptr)
		{
			if (!property_status)
			{
				if (buyerptr->getmax_cost() >= price)
				{
					buyer_client = buyerptr;
					property_status = true;
					cout <<street_address << " Condo has been Sold" << endl;
				}
			}
		}
		HouseSale* houseptr = dynamic_cast<HouseSale*>(this);
		if (houseptr != nullptr)
		{
			if (!property_status)
			{
				if (buyerptr->getmax_cost() >= price)
				{
					buyer_client = buyerptr;
					property_status = true;
					cout << street_address << " House has been Sold" << endl;
				}
			}
		}
}

Property::~Property()
{

}

// set function used for property class
void Property::setlandlord(ClientSeller* clientptr)
{
	landlord = clientptr;
}





// get functions used for property  class
int Property::getprice()
{
	return price;
}
bool Property::getproperty_status()
{
	return property_status;
}

RealEstateAgent* Property::getseller_agent()
{
	return seller_agent;
}
