/*************************
*Max Faykus
*CPSC 1021 3, F16
*Programming Assignment 1
*mfaykus
**************************/




 #include "wordfind.h"
 #include <stdbool.h>
 #include <stdlib.h>
 #include <stdio.h>

//this function reads in the file and starts the game
void readData(int argc, char *argv[]){
      /*This variable holds the number of words that can be found in the game*/
  int numAns;

  /*This arrays stores the words hidden in the game.  This could be read in
   *from the file, but I decided to hard code it for this assignment.*/
  char *ans[2] = {"SHOUT", "FISH"};

  /*This array holds the number configuration of the answer*/
  int answer[2];

  /*Used to determine which word is correct and needs to be printed.  As the
   *word is correctly found false will be replace with true.  For those of you
   *who have not had C, bool is a data type that allows you to give the value
   *of a variable either true or false.  In order to use bool you must include
   *the stdbool.h, (see above)*/
  bool correct[2] = {false, false};

  /*A count of the number of words the user has correct*/
  int numCorrect = 0;
  int i, j;

  /*This line creates a file pointer.  fopen basically opens
   *the file passed in by the command line argument argv[1]*/
  FILE *inPtr = fopen(argv[1], "r");

  /*This block of code check to see if the file was actually opened properly. If
   *not, it will print an error message and then close the program. */
  if(inPtr == NULL)
  {
    printf("Can't open input file!");
    exit(1);
  }

  /*Now we are going to read in the data from the file.  First the number of
   *words we will need to find in the matrix*/
  fscanf(inPtr, "%d", &numAns);

  char matrix[3][3];
  /*Now read in the numerical values that corrsponds to the actual answers*/
  fscanf(inPtr, "%d %d", &answer[0], &answer[1]);

  /*Read in the data for the 3 by 3 matrix.  This is for the gameboard */
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      fscanf(inPtr," %c", &matrix[i][j]);
    }
    printf("\n");
  }


    int z,a;
    bool k;
  /*Call printInstruction to start the game.*/
  z = printInstruction(numAns, numCorrect, matrix, answer, correct, ans);
    if(z==1){
        //if the player chose 1 to start the game this prints out game board
        printGame(numAns, numCorrect, matrix, answer, correct, ans);
            }
    while(z==1){
        //this is where the user inputs there first guess
        scanf("%i",&a);
        //k holds the true or false value to see if answer they guessed is correct
        k=isCorrectAnswer(numAns,correct,numCorrect,answer,a,matrix,ans);
        if(k==true){
            //if the answer is right the matrix updates and the number correct incriments
            updateMatrix(numAns, numCorrect, matrix, answer, correct, a, ans);
            numCorrect++;
            }
        if(k==false){
        //if it is not correct the user gets to try again
        printf("You entered the wrong code please try again\n");
        }
        //if the correct number of answers is reached the game is won and loop ends;
        if(numCorrect == numAns){
           printf("!!!!Congratulations you found all the words!!!!\n\n");
           break;
           }
        
        }
        }



/*prints the instructions for the game.  This will also ask the user
 *if they want to play they should enter a 1 for yes 0 for no.
 *Return their answer.*/
int printInstruction(int numAns, int numCorrect, char matrix[3][3],
                    int *answer, bool *correct, char *ans[])
{
    int x;
    printf("!!!Welcome to the WordFind program!!!");
    printf("You will be given a grid of characters.\n");
    printf("The grid has various words hidden in it.\n");
    printf("Your job is to find the hidden words.\n\n");
    printf("If you are ready for the challenge enter 1 or 0 to quit\n");
    scanf("%i",&x);
        
    return(x);
}

/*prints the game board */

void printGame(int numAns, int numCorrect, char matrix[3][3], int *answer,
               bool *correct,  char *ans[])
{
    printf("The numbers in this grid map to letters in the wordFind grid below.\n");
    printf("There are 2 words in the word grid.  Define the answer using in the first grid.\n\n");
    int i=1;
    int g=1;
    int k=0;
    int count=0;
    int n;
    int f=0;
    //this first while loop prints out the number grid to help the users play the game
    printf(" +---+---+---+\n");
    while(g<4){
        printf(" | %i | %i | %i |\n",i,i+1,i+2);
        printf(" +---+---+---+\n");
        i=i+3;
        g++;
    }
    printf("\n\n\n");
    printf("WORDFIND PUZZLE\n");
    i=0;
    g=0;
    printf(" +---+---+---+\n");
    //this loop prints out the matrix containing the words the player needs to find
    while(i<3){
        printf(" | %c | %c | %c |\n",matrix[i][g],matrix[i][g+1],matrix[i][g+2]);
        printf(" +---+---+---+\n");
        i++;
    }
    printf("\n\n");
    //this loop has 2 nested loops in it the first one finds the number of characters 
    //that are in the word and the second one prints out the correct number of lines 
    //and spaces so the player knows the length of the word. the loop continues until 
    //all of the words have been counted
        while(f<numAns){
            k=0;
            count=0;
            n=answer[f];
            while(n!= 0){
                n /= 10;
                count++;
                }
        
            while(k<count){
                printf("-- ");
                k++;
                }
            printf("\t");
            f++;
        }
    printf("\n\n");
    printf("Enter your answer:\n");
    
}

//this function prints the words when the player puts in the correct answer.
void printWords(bool *correct, char *ans[], int *answer)
{
    int n;
    int i=0;
    int z=0;
    int t=0;
    int count;
    int f=0;
    //this first loop counts how long the answer is.
    while(ans[t]!=NULL){
        t++;
        }
    //this loop runs for each word in the puzzle printing it if its answered.
    while(i<t){
    //this first if statment check if answer is right if it is the word is printed
        if(correct[i] == true ){
            printf("%s\t",ans[i]);
            }
        //if the answer is wrong it prints the -- to show length of word using nested while loops.
        if(correct[i] == false){
            while(f<t){
                count=0;
                n=answer[i];
                while(n!= 0){
                    n /= 10;
                    count++;
                    }
                f++;
            }
            while(z<count){
                printf("-- ");
                z++;
                }
            }
        i++;
        }
    printf("\n\n");
}


/*This function checks the players answer with all possible answers in the
 *array.    If the answer is incorrect return false.  */

bool isCorrectAnswer(int numAns, bool *correct, int numCorrect,
                               int *answer, int a, char matrix[3][3], char **ans)
{
    int i=0;
    int k=0;
    //this checks if the answer is correct yes return true no return false
    while(k<numAns){
        if(a==answer[k]){
            correct[k]=true;
            i=1;
            }
        k++;
    }
    if(i==1){
        return true;
        }
     return false;
}

/*When the player returns a correct word the characters in the matrix are
 *replaced with spaces and the word is printed below the matrix.  */

 void updateMatrix(int numAns, int numCorrect, char matrix[3][3], int *answer,
               bool *correct,int a, char **ans)
{
    printf("The numbers in this grid map to letters in the wordFind grid below.\n");
    printf("There are 2 words in the word grid.  Define the answer using in the first grid.\n\n");
    int i=1;
    int g=1;
    int f,z,e,k;
    int b,c,d,h,j,p,l,m,n;
    int q;
    int r;

//this prints out the number guide to the grid so it dosent dissapear when it updates
    printf(" +---+---+---+\n");
    while(g<4){
        printf(" | %i | %i | %i |\n",i,i+1,i+2);
        printf(" +---+---+---+\n");
        i=i+3;
        g++;
    }
    printf("\n\n\n");
    printf("WORDFIND PUZZLE\n");
    i=0;
    g=0;
    k=0;
    f=0;
    z=0;
    e=0;
    q=0;
    //if the player gets all the answers it will print out a blank grid and return
    //a value to skip rest of function
        while(z<numAns){
            if(correct[z]==true){
                e++;
                }
            if(e == numAns){
                printf(" +---+---+---+\n");
                while(k<3){
                    printf(" |   |   |   |\n");
                    printf(" +---+---+---+\n");
                    k++;
                    f=5;
                    }
            }
        z++;
        }


        while(q<numAns && f!=5){
//here it breaks down each number in the answer to find the letters they chose
            r=answer[q];
            b=r%10;
            r/=10;
            c=r%10;
            r/=10;
            d=r%10;
            r/=10;
            h=r%10;
            r/=10;
            j=r%10;
            r/=10;
            p=r%10;
            r/=10;
            l=r%10;
            r/=10;
            m=r%10;
            r/=10;
            n=r%10;

//this massive if test each quadrent to see if that corrsponding number was chosen
//if it was chosen it prints a blank and if it was not it prints the appropiat char
//this only works for a 3x3 matrix
            if(correct[q]==true && f!=5){
                printf(" +---+---+---+\n |");
                if(b==1||c==1||d==1||h==1||j==1||p==1||l==1||m==1||n==1){
                    printf("   |");
                    }
                if(b!=1&&c!=1&&d!=1&&h!=1&&j!=1&&p!=1&&l!=1&&m!=1&&n!=1){
                    printf(" %c |",matrix[i][g]);
                    }
                if(b==2||c==2||d==2||h==2||j==2||p==2||l==2||m==2||n==2){
                    printf("   |");
                    }
                if(b!=2&&c!=2&&d!=2&&h!=2&&j!=2&&p!=2&&l!=2&&m!=2&&n!=2){
                    printf(" %c |",matrix[i][g+1]);
                    }
                if(b==3||c==3||d==3||h==3||j==3||p==3||l==3||m==3||n==3){
                    printf("   |");
                    }
                if(b!=3&&c!=3&&d!=3&&h!=3&&j!=3&&p!=3&&l!=3&&m!=3&&n!=3){
                    printf(" %c |",matrix[i][g+2]);
                    }
                printf("\n +---+---+---+\n |");
                if(b==4||c==4||d==4||h==4||j==4||p==4||l==4||m==4||n==4){
                    printf("   |");
                    }
                if(b!=4&&c!=4&&d!=4&&h!=4&&j!=4&&p!=4&&l!=4&&m!=4&&n!=4){
                    printf(" %c |",matrix[i+1][g]);
                    }
                if(b==5||c==5||d==5||h==5||j==5||p==5||l==5||m==5||n==5){
                    printf("   |");
                    }
                if(b!=5&&c!=5&&d!=5&&h!=5&&j!=5&&p!=5&&l!=5&&m!=5&&n!=5){
                    printf(" %c |",matrix[i+1][g+1]);
                    }
                if(b==6||c==6||d==6||h==6||j==6||p==6||l==6||m==6||n==6){
                    printf("   |");
                    }
                if(b!=6&&c!=6&&d!=6&&h!=6&&j!=6&&p!=6&&l!=6&&m!=6&&n!=6){
                    printf(" %c |",matrix[i+1][g+2]);
                    }
                printf("\n +---+---+---+\n |");
                if(b==7||c==7||d==7||h==7||j==7||p==7||l==7||m==7||n==7){
                    printf("   |");
                    }
                if(b!=7&&c!=7&&d!=7&&h!=7&&j!=7&&p!=7&&l!=7&&m!=7&&n!=7){
                    printf(" %c |",matrix[i+2][g]);
                    }
                if(b==8||c==8||d==8||h==8||j==8||p==8||l==8||m==8||n==8){
                    printf("   |");
                    }
                if(b!=8&&c!=8&&d!=8&&h!=8&&j!=8&&p!=8&&l!=8&&m!=8&&n!=8){
                    printf(" %c |",matrix[i+2][g+1]);
                    }
                if(b==9||c==9||d==9||h==9||j==9||p==9||l==9||m==9||n==9){
                    printf("   |");
                    }
                if(b!=9&&c!=9&&d!=9&&h!=9&&j!=9&&p!=9&&l!=9&&m!=9&&n!=9){
                    printf(" %c |",matrix[i+2][g+2]);
                    }
                    
                printf("\n +---+---+---+\n");
                q++;
            }
   //if the answer they put in is wrong it incriments to the next one
            if(correct[q]==false && f!=5){
                q++;
                }
}
//if the solution is not found this is calle dto print the remaining word blanks
    if(f!=5){
        printWords(correct,ans,answer);
        printf("Enter your answer:\n");
        }
}



