/*
    max faykus
    Cpsc
    soManyChoices
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//prototypes
float choice1(float array[]);
float choice2(float array[]);
float choice3(float array[]);
void choice4(float array[], int size, bool isIncreasing);
void choice5(float array[], int size, bool isDecresaing);
void sort1(float* first, float* second, bool isIncreasing);
void sort2(float* first, float* second, bool isDecreasing);
void swap(float* first, float* second);
void choice6(float array[], int size);
void choice7(float array[], int size);
void choice8(float array[], int size);
void choice9(float array[], int size);
void choice10(float array[],int size);
void choice11(float array[], int size);
void choice12(char user[]);
void choice99();


//in my main i printed the choices and have a large if else statments to see what the user chooses
int main(void){
    const int MaxNUM = 100;
    float numbers2[MaxNUM];
    int loop=0;
    int choice;
    int count;
    int ctr=0;
    char inptxt[100];
    while(loop==0){
        printf("1 -Read from arraynumbers1.txt\n");
        printf("2 -Read from arraynumbers2.txt\n");
        printf("3 -Read from arraynumbers3.txt\n");
        printf("4 -Sort in ascending order\n");
        printf("5 -Sort im descending order\n");
        printf("6 -Calculate the Sum\n");
        printf("7 -Calculate the Average\n");
        printf("8 -Calculate the Minimum\n");
        printf("9 -Calcualte the Maximum\n");
        printf("10 -Display the array in 1 column\n");
        printf("11 -Display the array in 2 columns\n");
        printf("12 -Display user's input string in reverse\n");
        printf("99-Exit\n\n");

        printf("Enter selection: ");
        scanf("%d",&choice);
        
        if (choice==1){
            count= choice1(numbers2);
            count= count-1;
            ctr=1;
            }
        else if (choice==2){
            count= choice2(numbers2);
            count=count-1;
            ctr=1;
            }
        else if (choice==3){
            count= choice3(numbers2);
            count= count-1;
            ctr=1;
            }
        else if (choice==4 && ctr==1){
            choice4(numbers2, count, true);
            }
        else if (choice==5 && ctr==1){
            choice5(numbers2, count, false);
            }
        else if (choice==6 && ctr==1){
            choice6(numbers2, count);
            }
        else if (choice==7 && ctr==1){
            choice7(numbers2, count);
            }
        else if (choice==8 && ctr==1){
            choice8(numbers2, count);
            }
        else if (choice==9 && ctr==1){
            choice9(numbers2, count);
            }
        else if (choice==10 && ctr==1){
            choice10(numbers2, count);
            }
        else if (choice==11 && ctr==1){
            choice11(numbers2, count);
            }
        else if (choice==12){
            printf("Enter a String: ");
            scanf("%s",inptxt);
            choice12(inptxt);
            }
        else if (choice==99){
            choice99();
            }
        else {
            printf("please select a correct input\n");
            }
        
        printf("\n");
        }
    return (0);
}

//in the choice 1 function i am reading in the numbers from the arraynumbers1.txt file
//im inputing it in as a file pointer and returning it to main
float choice1(float array[100]){
    int numberRead = 0;
     FILE * inFile1 = fopen("arraynumbers1.txt","r");
     
    if( inFile1 == NULL){
        fprintf(stderr, "file open error. exiting program\n");
        exit(1);

     }
    while( !feof(inFile1)){
    fscanf(inFile1, "%f", &array[numberRead]);
    numberRead++;
        }
        fclose(inFile1);
        printf("\n%d numbers were read from arraynumbers1.txt.\n",numberRead-1);
    return numberRead;
}

//in the choice 2 function i am reading in the numbers from the arraynumbers2.txt file
//im inputing it in as a file pointer and returning it to main
float choice2(float array[100]){
    int numberRead = 0;
     FILE * inFile2 = fopen("arraynumbers2.txt","r");
     
    if( inFile2 == NULL){
        fprintf(stderr, "file open error. exiting program\n");
        exit(1);

     }
    while( !feof(inFile2)){
    fscanf(inFile2, "%f", &array[numberRead]);
    numberRead++;
        }
        fclose(inFile2);
        printf("\n%d numbers were read from arraynumbers2.txt.\n",numberRead-1);
    return numberRead;
}


//in the choice 3 function i am reading in the numbers from the arraynumbers3.txt file
//im inputing it in as a file pointer and returning it to main
float choice3(float array[100]){
    int numberRead = 0;
     FILE * inFile3 = fopen("arraynumbers3.txt","r");
     
    if( inFile3 == NULL){
        fprintf(stderr, "file open error. exiting program\n");
        exit(1);

     }
    while( !feof(inFile3)){
    fscanf(inFile3, "%f", &array[numberRead]);
    numberRead++;
        }
        fclose(inFile3);
        printf("\n%d numbers were read from arraynumbers3.txt.\n",numberRead-1);
    return numberRead;
}

//in the choice 4 i am using a bubble sort and have a bool input set to true to make the array increasing
void choice4(float array[100], int size, bool isIncreasing) {
    if (size >= 2) {
        int i;

        for (i = 0; i < size; i++) {
            int j;

            for (j = 0; j < size - 1 - i; j++) {
                sort1(&array[j], &array[j + 1], isIncreasing);
            }
        }
    }
}

//here i also use a bubble sort but to make the array decreasing i pass in a value of false to the bool isDecreasing
void choice5(float array[100], int size, bool isDecreasing) {
    if (size >= 2) {
        int i;

        for (i = 0; i < size; i++) {
            int j;

            for (j = 0; j < size - 1 - i; j++) {
                sort1(&array[j], &array[j + 1], isDecreasing);
            }
        }
    }
}

//tis is the sort function that i call when useing the bubble sort it evaluates the first and second to see which one is bigger and it then calls the swap function
void sort1(float* first, float* second, bool isIncreasing){
    if (  ( (!isIncreasing) && (*first < *second) ) || 
		    ( ( isIncreasing) && (*first > *second) )   ) {
        swap(first, second);
    }
}

//this function swaps the first and second pointers i use this with the sort function where it evaluates the code and if two numbers need to be switched i use this function to change there values
void swap(float* first, float* second) {
    int holder;

    holder  = *first;
    *first  = *second;
    *second = holder;
}


//this function takes the sum of the array by using a loop to add up the values 
void choice6(float array[], int size){
int i=0;
float sum=0;
while (i<size){
    sum=sum+array[i];
    i++;
    }
    printf("the sum is %f \n\n",sum);
  }

//choice7 finds the average of the array of numbers. it does this by summing up all the numbers and then dividing by the amount of numbers
void choice7(float array[], int size){
int i=0;
float avg=0;
while (i<size){
    avg=avg+array[i];
    i++;
    }
    avg=avg/size;
    printf("the average is %f \n\n",avg);
  }


//choice8 is a function that finds the lowest number in the array of numbers it does this by going through and comparing each value and replacing the higher one with the lowest till it reaches the end
void choice8(float array[], int size){
int g=0;
int h=0;

while(h<size){
    if(array[g]>array[h]){
        g=h;
        }
    h++;
    }
    printf("Lowest value is %f \n\n",array[g]);
}

//choice9 is a function that finds the highest value it uses the same method as choice8 but it replaces the lower value with the higher one instead
void choice9(float array[], int size){
int g=0;
int h=0;

while(h<size){
    if(array[g]<array[h]){
        g=h;
        }
    h++;
    }
    printf("Highest value is %f \n\n",array[g]);
}


//choice10 this just prints the array in 1 column just useing a loop that prints the value then goes to a new line and repeats
void choice10(float array[], int size){
int i=0;
while (i<size){
    printf("%f\n",array[i]);
    i++;
    }
}


//choice11 this function prints the array in two columns  by printing the first and second value  then incrimenting it by 2
void choice11(float array[], int size){
int i=0;
while (i<size){
        printf("%f\t%f\n",array[i],array[i+1]);
        i++;
        i++;
        }
}


//in this function takes a user input and gives it in reverse it does this by finding the string lenght with strlen then it prints the string starting with the max length then decriments it
void choice12(char user[]){
int letters;
int x;

letters = strlen(user);
letters--;
for (x = letters; x >= 0; x--){

    printf("%c",user[x]);
    }
    printf("\n");
}


//this function ends the program
void choice99(){
    exit(0);
    }
