#include <stdio.h>

int main()
{
	int a = 112;
	int b = -1;
	float c = 3.14;
	int *d = &a;
	float *e = &c;
	char arr[] = "Yvon";

	/*Is it ok to do the following?
	 *  int *a1;
	 *  *a1 = 12;
	 *Here is what happened,
	 *the declaration creates a pointer variable called 'a1', and
	 *the assignment stores 12 in the location to which 'a1'
	 *points.  But WHERE DOES 'a1' POINT? We declared the variable
	 *but never initialized it, so there is not a way to predict
	 *where the value 12 is being stored.  Declaring an int pointer
	 *does not "create" memory to store an int.  Uninitialized
	 *and illegal pointers can cause a segfault, bus error, or
	 *memory fault error.  Worse yet, it could actually corrupt
	 *other memory. These errors are hard to find.  So be sure to
	 *initialize all your pointers. */

	//int *a1;
	//*a1 = 12;



	/*or NULL you can not dereference a null pointer*
	 *If you try you could get a compile error or
	 *a runtime error */
	int *g = 0;
	g = &b;
	printf("g is %d\n", *g);

	/*This gives us the size of each variable.  This will allow us to
	 *check the addresses to see if they are contiguous which they
	 *are not always for regular variable.  */
	printf("size of variables: a = %lu, b = %lu, c = %lu, d = %lu, e = %lu\n",
		     sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e));

	/*This shows the address of each of the variables*/
	printf("address:  a = %p, b = %p, c = %p, d = %p, e = %p\n",
		&a, &b, &c, &d, &e);

    printf("value: d=%p g=%p\n",&d,&g);

	/*This shows that array memory is contiguous*/
	printf("address of arr: %p, %p, %p, %p, %p\n",
		&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

	return 0;
}
