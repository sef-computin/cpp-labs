
#include <iostream>
#include "math.h"

using namespace std;

int main()
{
	float A, B, C, D, E;
	printf("Enter X\n");
	scanf_s("%f", &A);
	B = A + 5;
	C = A - 2;
	D = B + C;
	E = A - C;
	printf("p1.1 = %f\n", A / (A + 5));
	printf("p2.1 = %f\n", (pow(A, 2) - 2 * A) / (A + 5));
	printf("p3.1 = %f\n", (pow(A, 2) - 2 * A) / (2 * pow(A, 2) + 13 * A + 15));
	printf("p4.1 = %f\n", (pow(A, 2) - 2 * A) * 2 / (2 * pow(A, 2) + 13 * A + 15));

	printf("\n\np1.2 = %f\np2.2 = %f\np3.2 = %f\np4.2 = %f",
		A / B, A * C / B, A * C / B / D, A * C * E / D / B);
}
