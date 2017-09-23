/***************
*Max Faykus
*CPSC 1021 3, F16
*Programming Assignment 2
*mfaykus
***************/

#include <iostream>
#include "midterm.h"
#include <cmath>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <string>
using namespace std;

midterm::midterm(){
        totalGrade=0;
        totalPoint=0;
        totalExamGrade=0;
    }


double midterm::getTotalGrade(){
    return (totalGrade);
}

double midterm::getTotalPoint(){
    return (totalPoint);
}



void midterm::calculateGrade(int num,double percent,int totalnum){
//this is the calculation to find the total amount of grades i have
    double i,k;
    i=percent/totalnum;
    i/=100;
    k=num*i;
    totalGrade+=k;
}

void midterm::calculatePoint(int num,double percent,int totalnum){
//this finds the percentage of grades i currently have done
    double i,k;
    i=percent/totalnum;
    i=i/100;
    k=i*num;
    totalPoint+=k;
}

int midterm::finalGrade(){
//this is the calculation of the current average i have given the grades i have gotten
    int midavg;
    midavg=totalGrade/totalPoint;
    return(midavg);
}
