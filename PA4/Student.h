#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
using namespace std;

/*This class is used to student information.  It inherites from Person
 *which provides the first and last name*/
class Student : public Person
{
	private:
		/*Student's GPA*/
		float GPA;
		/*What class is the students in (Freshman, Sophmore, Junior, Senior)*/
		string classStanding;
		int maxCredit;
		int curCredit;
		string firstName;
		string lastName;



	public:
        Student();
		Student(float sgpa, string sclass,int scurCredit,string fname, string lname);
		~Student();
		void setGPA(float gpa);
		void setClassStanding(string standing);
		void setCurCredit(int credit);
		float getGPA();
		string getClassStanding();
		int getCurCredit();


		/*What is the maximum credit hours a student can take?
		 *If a student is a first semester Freshman they can only take 15 credit
		 *hours.  Any student (this includes 2nd semester freshman) with a gpa
		 *< 2.5 can take no more than 12 hours. If they are a sophmore, juniors,
		 *or seniors with a gpa >= 2.5 they can take up to 18 hours. */
		int getMaxCredit(float g, string c);


		void printInfo3();

};

#endif
