
#include <iostream>
#include "stdio.h"
#include "math.h"

int main()
{
	float A1, A, B, H;
	float fx1,fx2;
	printf("Enter A and B:   ");
	scanf_s("%f %f", &A1,&B);
	printf("Enter H:   ");
	scanf_s("%f", &H);

	float absol;
	printf("     X              tan(x)         F1(x)         F2(x)         Abs         Rel, percents\n");

	
	for (A = A1; A <= B; A += H) {
		
		fx1 = A + (pow(A, 3) / 3) + 2 * pow(A, 5) / 15 + 17 * pow(A, 7) / 315 + 62 * pow(A, 9) / 2835;
		absol = tan(A) - fx1;

		printf("%10.2f     %10.4f     %10.4f     %10.4f     %10.4f     %10.4f %%\n", A, tan(A), fx1, 
			A * (1 + A * A * ((1. / 3.) + A*A*(2. / 15. + A*A*(17./315. + 62 * A * A / 2835.)))),
			absol, abs((absol / tan(A)) * 100));
	}
}
