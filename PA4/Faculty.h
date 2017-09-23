#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "Person.h"

using namespace std;

class Faculty : public Person
{

  private:
    string title;
    string building;
    int officeNumber;

  public:

    /*Default constructor*/
    Faculty();
    /*This constructor passes the first two strings for the person constructor*/
    Faculty(string, string, int, string, string);
    ~Faculty();

    void setTitle(string);
    void setFirstName(string);
    void setLastname(string);
    string getFirstName();
    string getLastName();
    string getTitle();
    void setBuilding(string);
    void setOfficeNumber(int);
    string getBuilding();
    int getOfficeNumber();
    void printInfo2();

};

#endif
