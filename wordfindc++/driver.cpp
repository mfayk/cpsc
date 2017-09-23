#include <iostream>
#include <cstdlib>
#include <fstream>
#include "WordFind.h"
using namespace std;


WordFind readData(ifstream &);
void start(WordFind, ifstream &);
int main (int argc, char *argv[])
{
	ifstream input(argv[1]);
	if(input.fail())
	{
		cout << "Error opening file.";
		exit(1);
	}

  /*Create an instance of WordFind and call readData.  Remember readData returns
	 *a WordFind.  */
    WordFind n = readData(input);
	/*Using the instance WordFind to call start. */
    start(n,input);
    return 0;
}

/*This is a local or client function. It is not part of the class WordFind.*/
 void start(WordFind n, ifstream & input){
        n.start(input);
 }
WordFind readData(ifstream & input)
{

    //matSize,numAns,ans,answer,matrix
    char **matrix;
    string *ans;
    int *answer;
 /*1. Create local variables for the size of the matrix and the number of
  *answers */
    int matSize,numAns;
    int i,j,k,w;
 /*2. Read in the size of the matrix and the number of answers.*/
    input >> matSize;
    input >> numAns;
 /*3. Create a 2D array for the gameboard. You must dynamically allocate the
  *memory for this array. Look in the notes for an example of how to do this
  *using malloc (however you must use new rather than malloc) or google how to
  *dynamically allocate memory for a 2D array in C++.  I am sure there tons of
  *examples out there. An example can be found here:
  http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new */
    matrix = new char*[matSize];
    for(i=0; i<matSize; ++i){
        matrix[i] = new char[matSize];
    }
 /*4. Create and dynamically allocate memory for the number of integers*/
    answer= new int[numAns];
 /*5. Create and dynamically allocate memory to hold the strings that will
	*that represents the words in the puzzle */
    ans = new string[numAns];
 /*6. Read the strings from the file*/
    for(j=0;j<numAns;j++){
        input >> ans[j];
    }
 /*7. Read the integers that will represent the answers*/
    for(k=0;k<numAns;k++){
        input >> answer[k];
    }
 /*8. Read the information for th 2d array.  */
    for(w=0;w<matSize;w++){
            for(int x=0;x<matSize;x++){
                input >> matrix[w][x];
            }

    }

 /*9. Create an instance of Wordfind, call the constructor, and return the
	*instance*/
//	here the construcer is being called

    WordFind n(matSize,numAns,ans,answer,matrix);
    delete [] answer;
    delete [] ans;
    for(i=0;i<matSize;i++){
        delete [] matrix[i];
    }


    return(n);
}
