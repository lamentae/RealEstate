#include "RealEstateAgent.h"
#include <iostream>
#include <math.h>
using namespace std;


int RealEstateAgent::total_employee_id = 1;

RealEstateAgent::RealEstateAgent(string pname, Date bday, Date employdate, int earnings  )
	: Person(pname, bday),
	employment_date(employdate)
{
	total_earnings = earnings; 
	employee_id = total_employee_id;
	total_employee_id++;
}

void RealEstateAgent::print() {
	
	cout << "Agent"<<employee_id;  
	cout << "Earnings: $" << total_earnings << endl;
}
//calculate 5% of the price of the property and add it to the total_earnings
void RealEstateAgent::earnings(int sale)
{
    double sale_com = sale * 0.05;
    sale_com = floor(sale_com);
    total_earnings = total_earnings + sale_com;
}

RealEstateAgent::~RealEstateAgent()
{
}
