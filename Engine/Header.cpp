#include "Header.h"

float circle::circumference(float x, float y, float r)
{
	//This creates a circle ! it does not create an area !!
	float powerofx = pow(x, 2);
	float powerofy = pow(y, 2);
	float circum = (0-powerofx)+(0+powerofy);
	return circum;
}
