/*Implemant the Faculty class here*/
#include "Faculty.h"
Faculty::Faculty()
{
 title = " ";
 building = " ";
 officeNumber = 0;
}

Faculty::Faculty(string title1, string building1, int officeNumber1,string fname,string lname)
{
 title = title1;
 building = building1;
 officeNumber = officeNumber1;
 Person::setFirstName(fname);
 Person::setLastName(lname);
}
Faculty::~Faculty(){

}

void Faculty::setTitle(string title1)
{
title = title1;
}

string Faculty::getTitle()
{
return title;
}

void Faculty::setBuilding(string building1)
{
building = building1;
}

void Faculty::setOfficeNumber(int officeNumber1)
{
officeNumber = officeNumber1;
}

string Faculty::getBuilding()
{
return building;
}

int Faculty::getOfficeNumber()
{
return officeNumber;
}

void Faculty::printInfo2()
{
cout<<"*****************************\n";
//cout<< title<<" "<<Person::printInfo5()<<endl;
Person::printInfo5();
cout<< officeNumber<< " " << building<<endl;
cout<<"*****************************\n";
}

