#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(string pname, Date bday, RealEstateAgent* ptr)
	:Person(pname,bday), my_agent(ptr)
{
	// Double check to see if this is the correct way to pass a pointer to a constructor.
}

void Client::print()
{
    
}

void Client::earnings(int)
{

}

Client::~Client()
{
}

