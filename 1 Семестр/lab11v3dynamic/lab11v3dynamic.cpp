
#include <iostream>
#include "math.h"
#include "conio.h"

int main()
{
	double* Xn;
	int i;
	printf("array lenght = ");
	scanf_s("%d", &i);
	Xn = new double[i];
	int n = 0;
	//for (n = 0; n < i; n += 1) { Xn[n] = -1.0 + (0.1 * n); }
	for (n = 0; n < i; n++) { printf("#%d  ", n+1); scanf_s("%lf", &Xn[n]); }

	n = 0;
	double x = Xn[n];
	double min = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
	double max = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
	int minindex = 0, maxindex = 0;
	for (n = 0; n < i; n++) {
		x = Xn[n];
		
		double y = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
		printf("x = %10.2lf,  y = %10.4lf\n", x, y);
		if (y > max) { max = y; maxindex = n; }
		if (y < min) { min = y; minindex = n; }
	}
	printf("\n\n");
	printf("minimum value = %9.4lf\t index = %d \t x = %9.4lf\n\n", min, minindex, Xn[minindex]);
	printf("maximum value = %9.4lf\t index = %d \t x = %9.4lf\n\n", max, maxindex, Xn[maxindex]);

	delete[] Xn;
	return 0;
}
