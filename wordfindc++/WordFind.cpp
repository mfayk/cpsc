/**********************
*Max Faykus
*CPSC 1021 03,F16
*PA3
*mfaykus
*********************/
#include <cstdlib>
#include "WordFind.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
/*Default constructor*/
WordFind::WordFind()
{
    matSize=0;
    numAns=0;
    answer=0;
    correct=0;
    numCorrect=0;
    ans='\0';
    matrix='\0';
}

/*Regular constructor*/
WordFind::WordFind(int matSize, int numAns, string *ans, int *answer, char **matrix)
{
    numCorrect=0;
	/*initializes the size for the matrix (matSize)*/
    this->matSize = matSize;


	/*initializes the size fo the number of answers (numAns)*/
    this->numAns= numAns;


	/*Allocates memory for the number of string answers*/
    this->ans = new string[numAns];
        for(int j=0;j<numAns;j++){
        this->ans[j] = ans[j];
    }

    /*Allocate memory for the correct bools*/
    correct = new bool[numAns];


	/*Now lets initialize the array for the strings for the answers also
	 *initialize the correct to false*/
    for (int i=0;i<numAns;i++){
      correct[i]=false;
    }



	/*Allocates memory for the numbers that represents the combination
	 *of integers that represent the answer*/
    this->answer = new int[numAns];


	/*initializes the answer*/
    for (int k=0;k<numAns;k++){
         this->answer[k]=answer[k];
    }


	/*This allocates memory for the 2d Array.*/
    this->matrix = new char*[matSize];
        for(int i=0; i<matSize; ++i){
            this->matrix[i] = new char[matSize];
        }


	/*Now lets fill the array*/
    for(int w=0;w<matSize;w++){
            for(int x=0;x<matSize;x++){
                this->matrix[w][x]=matrix[w][x];
            }
    }


}

/*Destructor*/
WordFind::~WordFind()
{

    /*Call Delete on all the dynamically allocated memory*/
    for(int i=0;i<matSize;i++){
        delete [] matrix[i];
    }
    delete [] answer;
    delete []correct;
    delete []ans;
    delete []answer;
}

void WordFind::setMatrix(char **mat)
{
    int w;
   /* matrix = new char*[matSize];
        for(int i=0; i<matSize; ++i){
            matrix[i] = new char[matSize];
        }*/
    for(w=0;w<matSize;w++){
            for(int x=0;x<matSize;x++){
                matrix[w][x]=mat[w][x];
            }
    }
}
void WordFind::setMatSize(int mSize)
{
    matSize=mSize;

}

void WordFind::setNumAns(int nAns)
{
    numAns=nAns;

}

void WordFind::setAns(string *ans)
{
    for(int j=0;j<numAns;j++){
        this->ans[j]= ans[j];
    }
}

void WordFind::setAns(int *answer)
{
//    this->answer = new int[numAns];
    for(int k=0;k<numAns;k++){
        this->answer[k]= answer[k];
    }
}


/*prints the instructions for the game.  This will also ask the user
 *if they want to play they should enter a 1 for yes 0 for no.
 *Return their answer.*/
int WordFind::printInstruction()
{
    int x;
    cout<<"!!!Welcome to the WordFind program!!!"<<endl;
    cout<<"You will be given a grid of characters."<<endl;
    cout<<"The grid has various words hidden in it."<<endl;
    cout<<"Your job is to find the hidden words."<<endl;
    cout<<"If you are ready for the challenge enter 1 or 0 to quit"<<endl;
    cin>>x;

    return x;

}

/*prints the game board */
void WordFind::printGame(){
    int i,k,w,n;
    int count1=1;
    int f=0;
    int count=0;

    cout<<"The numbers in this grid map to letters ";
    cout<<"in the wordfind grid below."<<endl;
    cout<<"There are 2 words in the word grid.";
    cout<<"  Define the answer using the numbers in the first grid.\n\n";
    for(k=0;k<matSize;k++){
        cout<<"+";
        for (i=0;i<matSize;i++){
            cout<<"---+";
        }
        cout<<"\n";
        cout<<"| ";
        for (i=0;i<matSize;i++){
            cout<<count1<<" | ";
            count1++;
        }
        cout<<"\n";
    }
    for (w=0;w<matSize;w++){
            cout<<"+---";
        }
        cout<<"+";
    cout<<"\n\n\nWORDFIND PUZZLE\n";
    for(k=0;k<matSize;k++){
        cout<<"+";
        for (i=0;i<matSize;i++){
            cout<<"---+";
        }
        cout<<"\n| ";
        for (i=0;i<matSize;i++){
            cout<<matrix[k][i]<<" | ";


        }
        cout<<"\n";
    }
    for (w=0;w<matSize;w++){
            cout<<"+---";
        }
        cout<<"+";
    cout<<"\n\n";
    while(f<numAns){
        k=0;
        count=0;
        n=answer[f];
        while(n!=0){
            n /= 10;
            count++;
        }
        while(k<count){
            cout<<"-- ";
            k++;
        }
        cout<<"\t\t";
        f++;
    }
    cout<<"\n\nEnter your answer"<<endl;

}

void WordFind::printWords(int c)
{
    int n,count;
    int i=0;
    int z=0;
    int t=0;
    int f=0;

    while (t<numAns){
        t++;
    }

    while(i<t){
        if (correct[i]==true){
                cout<<ans[i]<<"  ";
        }
        if(correct[i] == false){
            while(f<t){
                count=0;
                n=answer[i];
                while(n!=0){
                    n /= 10;
                    count++;
                }
                f++;
                }

            while(z<count){
                cout<<"-- ";
                z++;
            }
            cout<<" ";
        }
    i++;
    }
    cout<<"\n\n";
}
/*this is the actual driver of the game.  This is called by main.  */
void WordFind::start(ifstream &input){
    int z;
    bool k;
    z=printInstruction();
    if (z==1){
        printGame();
        while(z==1){
            cin>>playerAns;
            k=isCorrectAnswer(playerAns);
            if (k==true){
                    updateMatrix(playerAns);
                    numCorrect++;
            }
            if (k==false){
                cout<<"You entered the wrong code please try again"<<endl;
            }
            if (numCorrect == numAns){
                cout<<"\n\n!!!!Congratulations you found all the words!!!!\n"<<endl;
                exit(1);
            }
            }
        }
    else {
        cout<<"thank you for playing\n\n";
        exit(1);
    }
}

/*This function checks the players answer with all possible answers in the
 *array.    If the answer is incorrect return false.  */
bool WordFind::isCorrectAnswer(int a)
{
    int i=0;
    int k=0;

    while (k<numAns){
        if(a==answer[k]){
            correct[k]=true;
            i=1;
        }
        k++;
        }
        if (i==1){
            return true;
            }
        return false;
    }



/*When the player returns a correct word the characters in the matrix are
 *replaced with spaces and the word is printed below the matrix.  */
void WordFind::updateMatrix(int a){
    int k,r,i,kill,w,count;
    int f=0;
    int z=0;
    int corr=0;
    int q=0;
    int dig;
    int vecSize;
    vector<int> finder;
    int count1=1;
     /*strip out each digit of 'a' then use that number to determine
		 *which subscript needs to replaced with a space */
    cout<<"The numbers in this grid map to letters in the wordFind";
    cout<<" grid below\nThere are 2 words in the word grid.  Define the";
    cout<<" answer using in the first grid.\n\n";

    for(k=0;k<matSize;k++){
        for (i=0;i<matSize;i++){
            cout<<"+---";
        }

        cout<<"+\n| ";
        for (i=0;i<matSize;i++){
            cout<<count1<<" | ";
            count1++;
        }
        cout<<" \n";
    }
    for (w=0;w<matSize;w++){
            cout<<"+---";
        }

    cout<<"+\n\n\nWORDFIND PUZZLE\n";
    while (z<numAns && f!=5){
            if(correct[z]==true){
                corr++;
            }
            if(corr==numAns){
                for(k=0;k<matSize;k++){
                    for (i=0;i<matSize;i++){
                        cout<<"+---";
                    }

                    cout<<"+\n| ";
                    for (i=0;i<matSize;i++){
                        cout<<" "<<" | ";
                    }
                    cout<<" \n";
                }
                for (w=0;w<matSize;w++){
                    cout<<"+---";
                }
                cout<<"+";
                f=5;

            }
            z++;
    }
    int x=0;
//this loop finds the total current correct answers number values
    while(q<numAns && f!=5){
        if(correct[q]==true){
            r=answer[q];
            dig=0;
            if (r<0){
                dig =1;
            }
            while (r!=0){
                finder.push_back(r % 10);
                r=r/10;
                dig++;
                x++;
            }
        }
        q++;
    }
    //this massive nested loop to print out any size matrix
    vecSize=finder.size();
        count=0;
        if(f!=5){
            for(k=0;k<matSize;k++){
                cout<<"+";
                for (i=0;i<matSize;i++){
                    cout<<"---+";
                }
                cout<<"\n| ";
                for (i=0;i<matSize;i++){
                    kill=0;
                    for(int sera=0;sera<vecSize;sera++){
                        if(count==finder[sera]-1){
                            kill=5;
                        }
                    }
                    if(kill==5){
                        cout<<" "<<" | ";
                    }
                    else {

                        cout<<matrix[k][i]<<" | ";
                    }
                count++;
                }
                cout<<"\n";
                }

            for (i=0;i<matSize;i++){
                cout<<"+---";
                    }
                cout<<"+\n\n";
        }
    if(f!=5){
        printWords(a);
        cout<<"Enter your answer:"<<endl;
    }
   }


