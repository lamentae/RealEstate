#include "HouseSale.h"

using namespace std;

HouseSale::HouseSale(string address, int ybuilt, int nbroom, int cost, int totland, ClientSeller* csptr, RealEstateAgent* rptr, Date listingdate)
	:Property(address, ybuilt,nbroom,cost,csptr,rptr,listingdate)
{

	total_land = totland;
}

void HouseSale::print()
{
    
    cout << "Type: " << "House" << endl;
	cout << "Total Land: "<< total_land << "ft^2" << endl;
}

HouseSale::~HouseSale()
{
	
}
