#include "ClientBuyer.h"
#include <iostream>


using namespace std;

ClientBuyer::ClientBuyer(string pname, Date bday, RealEstateAgent* agentptr, string buildtype, int costmax )
	: Client(pname,bday,agentptr)
{
	building_type = buildtype;
	max_cost = costmax;
}

std::string ClientBuyer::getbuilding_type()
{
    return building_type;
}

int ClientBuyer::getmax_cost()
{
    return max_cost;
}

void ClientBuyer::print() {};

void ClientBuyer::earnings(int)
{

}

ClientBuyer::~ClientBuyer()
{
}
