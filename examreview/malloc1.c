#include <stdio.h>
#include <stdlib.h>


/* 1  2  3  4
   5  6  7  8
   9  10 11 12 */

int main()
{

  /*The row and column for the above 2D array*/
	int r = 3, c = 4;

  /*This dynamically allocates memory for r * c ints*/
	int *arr = (int *)malloc(r * c * sizeof(int));

	int i, j, count = 0;
  /*Nested for loop to loop through all */
	for (i = 0; i < r; i++)
  {
	   for (j = 0; j < c; j++)
     {
       /*These basically do the same.  If I want to address a 2 dimensional
        *array using 1D notation, I can use the following formula.
        *The row I want multiplied by the total number of columns plus the
        *row I want.*/
       arr[i*c + j] = ++count;

       /*The following statement basically says add i times c plus j to where
        *arr is pointing.  Remember arr is pointing to the first element of arr
        *This will get you to the correct element of the array.
        *Then Increment the value of i and assign it to count. */

         //*(arr + i*c + j) = ++count;
     }
  }

	for (i = 0; i < r; i++)
  {
	   for (j = 0; j < c; j++)
     {
		   printf("%3d ", *(arr + i*c + j));
     }
     printf("\n");
  }
  printf("\n");

  /* Code for further processing and free the
	   dynamically allocated memory */
     free(arr);

return 0;
}
