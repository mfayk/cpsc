#include "defs.h"
//this function is where the weight is calculate on the chosen planet
float otherweight (float x,int y){
float gravity,weight;
switch(y)
	{
	case 1:
		gravity = 0.284;
		break;
	case 2:
		gravity = 0.907;
		break;
	case 3:
		gravity = 0.38;
		break;
	case 4:
		gravity = 2.34;
		break;
	case 5:
		gravity = 0.925;
		break;
	case 6:
		gravity = 0.795;
		break;
	case 7:
		gravity = 1.125;
		break;
	default:
		gravity = 0.166;
		break;
	}
//this is the calculation to find the weight on the planet
	weight= (x/9.8)*gravity*10;
return(weight);
}
