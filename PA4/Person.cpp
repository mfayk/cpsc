/*Implement the Person class here*/
#include "Person.h"
Person::Person(){
	firstName= " ";
	lastName= " ";
}

Person::Person(string first, string last){
	firstName=first;
	lastName=last;
}
Person::~Person(){
}
void Person::setFirstName( string first){
	firstName=first;
}

void Person::setLastName(string last){
	lastName=last;
}

string Person::getFirstName(){
	return firstName;
}

string Person::getLastName(){
	return lastName;
}
void Person::printInfo5(){
	cout<< firstName<<" "<<lastName<<endl;
}
