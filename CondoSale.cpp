#include "CondoSale.h"

using namespace std;

CondoSale::CondoSale(string address, int ybuilt, int nbroom, int cost, int fee, ClientSeller* csptr, RealEstateAgent* agptr, Date listingdate)
	:Property(address, ybuilt, nbroom, cost, csptr, agptr, listingdate)
{

	condo_fee = fee;
}

void CondoSale::print()
{

	cout << "Type: " << "Condo" << endl;
	cout << "Condo Fees: $";
	cout << condo_fee << endl;

}

CondoSale::~CondoSale()
{

}
