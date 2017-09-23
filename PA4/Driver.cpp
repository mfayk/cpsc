/*#includes go here*/
#include <vector>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "Student.h"
#include "Faculty.h"
#include "CpscCourse.h"
using namespace std;

void fillFaculty(ifstream&, vector <Faculty> &);
void fillStudents(ifstream&, vector <Student> &);
void fillCpscCourse(ifstream&, vector <CpscCourse> &);


int main(int argc, char* argv[])
{
    ifstream inStudent(argv[1]);

    ifstream inCourse(argv[2]);

    ifstream inFaculty(argv[3]);

    /*Use these to store the courses, students and faculty read from
     *the files. */
    vector <CpscCourse> courses;
    vector <Student> stu;
    vector <Faculty> fac;

    fillFaculty(inFaculty, fac);
    fillStudents(inStudent, stu);
    fillCpscCourse(inCourse, courses);

    inStudent.close();
    inCourse.close();
    inFaculty.close();


	return 0;
}

void fillFaculty(ifstream& inFaculty, vector<Faculty> &fac)
{
  /*Your code goes here*/
  int numPeople;
  string title;
  string firstName;
  string lastName;
  int roomNum;
  string building;
    inFaculty >> numPeople;
    for(int i=numPeople;i>0;i--){
        inFaculty >> title;
        inFaculty >> firstName;
        inFaculty >> lastName;
        inFaculty >> roomNum;
        inFaculty >> building;
        fac.push_back( Faculty(title,building,roomNum,firstName,lastName));
    }
    for(int k=0;k<numPeople;k++){
		fac[k].printInfo2();
		}


}

void fillStudents(ifstream& inStudent, vector<Student>& stu)
{
	/*Your code goes here*/
    int numPeople;
    string firstname;
    string lastname;
    string classlvl;
    float gpa;
    int curcred;
    inStudent >> numPeople;
    for(int i=numPeople;i>0;i--){
        inStudent >> firstname;
        inStudent >> lastname;
        inStudent >> gpa;
        inStudent >> classlvl;
        inStudent >> curcred;
        stu.push_back( Student(gpa,classlvl,curcred,firstname,lastname));
    }
    for(int k=0;k<numPeople;k++){
		stu[k].printInfo3();
		}

}

void fillCpscCourse(ifstream& inCourse, vector <CpscCourse>& courses)
{
	/*Your code goes here*/

	/*Your code goes here*/
     string courseName;
     int numOfcourse;
     int courseNumber;
     int courseSeat;
     int availSeat;
     int openSeat;

     inCourse >> numOfcourse;
     for(int i = 0; i < numOfcourse; i++){
             inCourse >> courseName;
             inCourse >> courseNumber;
             inCourse >> courseSeat;
             inCourse >> availSeat;
             inCourse >> openSeat;

             courses.push_back(CpscCourse(courseName, courseNumber, courseSeat, availSeat, openSeat));
		 }
		 for(int k = 0; k < numOfcourse; k++){
             courses[k].printInfo1();
		 }


}

