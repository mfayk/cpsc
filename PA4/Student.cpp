/*Implement the Student class here*/
#include "Student.h"

Student::Student(){
	GPA=0.0;
	classStanding=" ";
	maxCredit=0;
	curCredit=0;
}

Student::Student( float sgpa, string sclass,int scurCredit,string fname, string lname )
{
	Person::setFirstName(fname);
	Person::setLastName(lname);
	GPA=sgpa;
	classStanding=sclass;
	curCredit=scurCredit;
}
Student::~Student(){

}

void Student::setGPA(float gpa){
	GPA=gpa;
}

void Student::setClassStanding(string standing){
	classStanding=standing;
}

void Student::setCurCredit(int credit){
	curCredit=credit;
}

float Student::getGPA(){
	return GPA;
}

string Student::getClassStanding(){
	return classStanding;
}

int Student::getCurCredit(){
	return curCredit;
}

int Student::getMaxCredit(float g, string c){
	g=GPA;
	c=classStanding;
	if(c=="Freshman"){
		if(curCredit>0 && GPA>2.5){
			return 15;
		}
		if(curCredit>0 && GPA<2.5){
			return 12;
		}
		if(curCredit==0){
			return 15;
		}
	}
	if(c=="Sophmore" || c=="Junior" || c=="Senior"){
		if(GPA>2.5){
			return 18;
		}
		else{
			return 12;
		}
	}
	return 0;
}

void Student::printInfo3(){
	int k;
	k=getMaxCredit(GPA,classStanding);
	cout<<"*****************************\n";
	cout<<"Name:\t\t";
	Person::printInfo5();
	cout<<"GPA;\t\t"<<GPA<<endl;
	cout<<"category: \t"<<classStanding<<endl;
	cout<<"Maximum Credit:\t"<<k<<endl;
	cout<<"Current Credit:\t"<<curCredit<<endl;
	cout<<"*****************************\n";
}
