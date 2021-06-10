#include <iostream>
#include "math.h"
int main()
{
	// x^5 - x + 0.2
	double x0, x1,x2, Eps, dx, P;
	printf("Iteration Method\nEnter Epsilon and x0 --> ");
	scanf_s("%lf %lf", &Eps, &x0);

	P = 5 * pow(x0, 4);
	double Xnach = x0;
	if (P < 1) {
		do {
			x1 = pow(x0, 5) + 0.2;
			dx = fabs(x0 - x1);
			x0 = x1;
		} while (dx > Eps);
		if (Xnach != x0) printf("x0= %lf", x0);
	}
	else printf("Method is not usable. Function is indeterminate");

	


	printf("\n\nHalf-Divide Method\nEnter XL and XR --> ");
	scanf_s("%lf %lf", &x1, &x2);
	int n = 0;
	double y, yl;
	yl = pow(x1, 5) - x1 + 0.2;
	if (yl * (pow(x2, 5) - x2 + 0.2)<0) {
		do {
			x0 = (x1 + x2) / 2;
			y = pow(x0, 5) - x0 + 0.2;
			if (y * yl > 0) x1 = x0;
			else x2 = x0;
			yl = pow(x1, 5) - x1 + 0.2; n++;
		} while (fabs(x1-x2)>Eps && n<10000);
		printf("X = %lf ;     Iteration number - %d", x0, n);
	}



}
