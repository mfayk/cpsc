/***************
*Max Faykus
*CPSC 1021 3, F16
*Programming Assignment 2
*mfaykus
***************/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

class midterm  {


    private:
        double totalGrade;
        double totalPoint;
        double totalExamGrade;

    public:
        midterm();

        double getTotalGrade();
        double getTotalPoint();
        void calculateGrade(int num,double percent,int totalnum);
        void calculatePoint(int numthere,double percent,int totalnum);
        int finalGrade();

};
