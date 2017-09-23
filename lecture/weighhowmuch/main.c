#include"defs.h"


int main(void){
	int weight,planet,run=0;
	char p[8][20] = {"Mercury", "Venus", "Mars", "Jupiter", "saturn", "Uranus", "Neptune", "the moon"};
//this is where the user chooses the planet he wants to see his weight on 
	
	printf("enter your weight: \n");
	scanf("%i",&weight);

	do {	
		printf("\nwhich planet do you want to see how much you would weigh on?\n");
		printf("1: Mercury\n2: Venus\n3: Mars\n4: Jupiter\n5: Saturn\n6: Uranus\n7: Neptune\n8: the moon\n");
//this is the output of the function to find the weight on another planet
		scanf("%i",&planet);
		printf("On %s, you would weigh %.2f pounds!",p[planet-1],otherweight(weight,planet));

		printf("\nDo you want to go again? (1 for Yes, 0 for no)\n");
		scanf("%i",&run);
		}
		while( run != 0);
//this allows the user to use the program again
	return 0;
}

