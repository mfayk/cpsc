/*Implement the CpscCourse class here*/
/*Implement the CpscCourse class here*/
#include "CpscCourse.h"
CpscCourse::CpscCourse()
{
 cn = " ";
 cnum = 0;
 cs = 0;
 as = 0;
 os = 0;
}

CpscCourse::CpscCourse(string courseName, int courseNum, int courseSect, int availSeats, int openSeats)
{
 cn = courseName;
 cnum = courseNum;
 cs = courseSect;
 as = availSeats;
 os = openSeats;
}

CpscCourse::~CpscCourse()
{
}

void CpscCourse::setCourseName(string courseName)
{
 cn =courseName;
}

void CpscCourse::setCourseNum(int courseNum)
{
 cnum = courseNum;
}

void CpscCourse::setCourseSect(int courseSect)
{
cs = courseSect;
}

void CpscCourse::setAvailSeats(int availSeats)
{
 as = availSeats;
}

void CpscCourse::setOpenSeats(int openSeats)
{
 os = openSeats;
}

string CpscCourse::getCourseName()
{
 return cn;
}

int CpscCourse::getCourseNum()
{
 return cnum;
}

int CpscCourse::getCourseSect()
{
 return cs;
}

int CpscCourse::getAvailSeat()
{
 return as;
}

int CpscCourse::getOpenSeats()
{
return os;
}

void CpscCourse::printInfo1()
{
cout<<"*********************************\n";
cout<<"Course Name:"<<"    "<< cn << endl;
cout<<"Course Number:"<<"   "<< cnum << endl;
cout<<"Course Section:"<<"   "<< cs << endl;
cout<<"Available Seats:"<<"  "<< as << endl;
cout<<"Open Seats:"<<"   "<< os << endl;
cout<<"Course ID:" << "   "<< courseID;
cout<<"*********************************\n";
}
