#include <stdio.h>
int main()
{
   
   int values[10] = {-1, 14, -24, 6, 9, 2, -3, 4, 7, 3};
   char word[26] = {'H', 'a', 'v', 'e', ' ', 'a', ' ','g', 'r', 'e',
    'a', 't', ' ', 'w', 'e', 'e', 'k', 'e', 'n', 'd', '!', '!', '!', '!'};
   int i, n=10;

   
   int *pv0 = values;
   printf("0. pv0 = %i\n", *pv0);
   int *pv1 = pv0 + 5;
   printf("\n1. pv1 = %i\n", *(pv1+3));

   char *pv2;
   pv2 = word;
   printf("\n2. *pv2 = %c\n", *pv2);
   printf("\n3. *(pv2 + 3) = %c\n\n", *(pv2 + 3));


   // output
   printf("\n4. Check: ");
   char *pv4 = word;
   for (i=0; i<5; i++) {
      printf("%c", *pv4);
      pv4 += 3;
   }

   printf("\n\n5. %s\n", word);

   // exit
   printf("\nAll done!\n");
   return(0);
} 
