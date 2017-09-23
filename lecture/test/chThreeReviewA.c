/* Program 3.2, Page 31
with additional code to
practice arithmetic operations */

#include <stdio.h>

int main (void) {
// declaring some variables
	int a = 100, b=2, c=25, d=4, e=1;
	int result;
	result = a – b;
printf ("a – b = %i \n", result);
result = b * c;
printf ("b * c = %i \n", result);
result = a / c;
printf ("a / c = %i \n", result);
result = a + b * c;
printf ("a + b * c = %i \n", result);
printf ("a * b + c * d = %i \n", a * b + c * d);
printf ("-a = %i \n", -a);
printf ("a %% b = %i \n", a % b);
printf ("c %% d = %i \n", c % d);
printf ("a = %i \n", a);
printf ("a /= d + e makes a = %i \n", a /= d + e);
printf ("a = %i \n", a);
printf ("b +=5 makes b = %i \n", b += 5);
printf("25 / 2 = %i (using %%i)\n", 25 / 2);
printf("25 / 2 = %f (using %%f)\n", 25 / 2);
printf("(float) 25 / 2 = %f (using %%f) \n", (float) 25 / 2);
printf("25.0 / 2 = %i (using %%i)\n", 25.0 / 2);
printf("(int) 25.0 / 2 = %i (using %%i)\n", (int) 25.0 / 2);
printf("25.0 / 2 = %f (using %%f)\n\n", 25.0 / 2);
return 0;
}
