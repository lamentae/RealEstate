#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string pname, Date bday )
	:birthdate(bday)
{
	name = pname;
}

void Person::print()
{
    cout << "Name: " << name << endl;
    birthdate.print();
    cout<<endl;

} 


void Person::earnings(int)
{

}

Person::~Person()
{
}
