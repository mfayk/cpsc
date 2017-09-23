#ifndef PERSON_H
#define PERSON_H
#include <iostream>


using namespace std;
class Person
{
	private:
		string firstName;
		string lastName;


	public:
		/*setters and getters*/
		void setFirstName(string firstn);
		void setLastName(string lastn);
		string getFirstName();
		string getLastName();

		/*constructors and destructors*/
		Person();
		Person(string, string);
		~Person();

		void printInfo5();
};

#endif
