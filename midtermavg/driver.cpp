/***************
*Max Faykus
*CPSC 1021 3, F16
*Programming Assignment 2
*mfaykus
***************/

#include <iostream>
#include <iomanip>
#include "midterm.h"
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    int numcat,j,w,result;
    int t=0;
    int q=0;
    int i=0;
    int totalnum;
    double percentage;
    string m;

    midterm n;

    ifstream file(argv[1]);

    file >> numcat;
//each time this loop runs it reads and calculates a section of the grades (ex. Lab)
//the values are overwritten each time the loop runs the calculations are stored in the class
    while(i<numcat){
        t=0;
        file >> m;
        file >> w;
        q=0;
        while(w>q){
            j=0;
            file >> j;
            t+=j;
            q++;
        }
        file >> totalnum;
        file >> percentage;
//this is where my class is called the calculategrade keeps the amount of points i earned
        n.calculateGrade(t,percentage,totalnum);
//the calculatepoint keeps track of the percentage points you can get.
        n.calculatePoint(w,percentage,totalnum);
        i++;
    }
//this returns the value of your midterm average not rounded,
//because most of my classes don't round grades
    result=n.finalGrade();
    cout<<"the midterm average is "<<result<<endl;
    return (0);

}
