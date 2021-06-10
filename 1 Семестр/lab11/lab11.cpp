
#include <iostream>
#include "math.h"
#include "conio.h"

using namespace std;

double func(double x) 
{
	double f = 2 * pow(x, 4) - (12 * pow(x, 3)) - (4 * pow(x, 2)) + 2;
	return f;
}

int main()
{
	double Xn[20];

	int n = 0;
	for (n = 0; n < 20; n += 1) {Xn[n] = -1.0+(0.1*n); }


	double x = Xn[n];
	double min = func(x);
	double max = func(x);
	int minindex = 0, maxindex = 0;
	n = 1;
	for (n = 0; n < 20; n++) {
		x = Xn[n];
		double y = func(x);
		if (y > max) { max = y; maxindex = n; }
		if (y < min) { min = y; minindex = n; }
	}
	printf("minimum value = %9.4lf\t index = %d \t x = %9.4lf\n\n", min, minindex, Xn[minindex]);
	printf("maximum value = %9.4lf\t index = %d \t x = %9.4lf\n\n", max, maxindex, Xn[maxindex]);

}
