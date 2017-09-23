#ifndef CPSCCOURSE_H
#define CPSCCOURSE_H
#include <iostream>

using namespace std;
/*This class holds the information about the cpsc courses*/
class CpscCourse
{
	private:
		string cn;
		int cnum;
		int cs;
		int as; //available seats
		int os;


	public:
		/*Constructors*/

		//Default Constructor
		CpscCourse();

		//Paremetized Constructor
		CpscCourse(string, int, int, int, int);

		/*Destructors*/
		~CpscCourse();

		/*Setters*/
		void setCourseName(string);
		void setCourseNum(int);
		void setCourseSect(int);
		void setAvailSeats(int);
		void setOpenSeats(int);

		/*Getters*/
		string getCourseName();
		int getCourseNum();
		int getCourseSect();
		int getAvailSeat();
		int getOpenSeats();

		/*Member Functions (Methods)*/

		void printInfo1();
		static int courseID;
};
#endif
