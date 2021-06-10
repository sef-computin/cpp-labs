
/* Y(x)=
		-1 при -2>X
		X+1 при -2<=X<0
		1 при 0<=X<1
		0 при 1<=X
*/

#include "pch.h"
#include "math.h"
#include <iostream>

int main()
{
		int x, y;
		scanf_s("%f", &x);
		if (x < -2) { printf("-1"); }
		if (x >= -2 and x < 0) { y = x + 1; printf("%i", &y); }
		if (x >= 0 and x < 1) { printf("1"); }
		if (x >= 1) { printf("0"); }

}