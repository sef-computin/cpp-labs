
#include <iostream>
#include "math.h"
#include "conio.h"

int main()
{
	double Xn[20];

	int n = 0;
	for (n = 0; n < 20; n += 1) { Xn[n] = -1.0 + (0.1 * n); }

	n = 0;
	double x = Xn[n];
	double min = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
	double max = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
	int minindex = 0, maxindex = 0;
	for (n = 0; n < 20; n++) {
		x = Xn[n];
		double y = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
		if (y > max) { max = y; maxindex = n; }
		if (y < min) { min = y; minindex = n; }
	}
	printf("minimum value = %9.4lf\t index = %d \t x = %9.4lf\n\n", min, minindex, Xn[minindex]);
	printf("maximum value = %9.4lf\t index = %d \t x = %9.4lf\n\n", max, maxindex, Xn[maxindex]);

}
