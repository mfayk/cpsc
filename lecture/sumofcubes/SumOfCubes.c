/* Max Faykus
mfaykus
111-002
2/14/2016
progect assignment 1- sum of cubes
this program takes a number that the user inputs checks if it is divisible by 3
it then cubes each of the digits and find s the quotient 
*/



#include <stdio.h>

int main (void)
{
	int oddNum;
	int digits; 
	int cube;
	printf("enter a number that is divisible by three: ");
	scanf("%i", &oddNum);

	if (oddNum%3 == 0) {
//this is first if statment to determin if the input oddNum is divisible by 3
		
		while (oddNum > 0) {
//the while loop is used to isolate the intiger value of oddNum
			
			digits = oddNum % 10;
			printf("%i ",(digits*digits*digits));
			cube += (digits*digits*digits);
			oddNum/=10;
//oddNum is divided by 10 at the end to move to the next digit to calculate
				
				if (oddNum > 0) {
					printf("+ ");
//the purpuse of this if statement is to proberly space and put the + sign inbetween the digits im adding
				} 
			}
	

	printf("= %i",cube);
	printf("\nthe quotient of the cubes is %i\n",cube/3);
//this is printing the results of the quotient of sum of cubes and the one before it is the sum of the cubes of each digit of the entered number	
	}
	else  {
		printf("that number is not divisible by three\n");
		}
//this else statement is to tell the user that they didnt input a number that is divisible by 3

	return 0;
}
