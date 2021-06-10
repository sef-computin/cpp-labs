// Доп. задание: Вывести результат в десятичном виде

#include <iostream>
#include "math.h"

void input(short[30], int);

void main()
{
	// статическое выделение
	
	//const int nmax = 30;
	//short Y[nmax];
	int k;
	/*printf("Enter k >> ");
	scanf_s("%d", &k);

	input(Y, k);

	printf("\nCalculating S\n");
	printf("S: ");
	*/short current;
	/*current = Y[0];
	for (int i = 1; i < k; i++) {
		for (int j = 0; j < Y[i]; j++) {
			printf("%d ", current);
		}
		if (current > 0) current = 0;
		else current = 1;
	}
	printf("\n");
	*/

	// динамическое выделение
	short* A;
	printf("Enter k >> ");
	scanf_s("%d", &k);

	A = (short*)malloc(k * sizeof(short));

	input(A, k);

	// доп задание: результат в десятичном виде
	int len = 0;
	for (int i = 1; i < k; i++) { len += A[i]; }
	len--;
	int n = 1;
	int res = 0;
	short element = A[0];
	int i = 0;
	while(n<k)
	{
		for (int j = 0; j < A[n]; j++) { res += element * pow(2, len - i); i++; }
		if (element == 1) element = 0;
		else element = 1;
		n++;
	}
	//доп задание 


	printf("\nCalculating S\n");
	printf("S: ");
	current = A[0];
	for (int i = 1; i < k; i++) {
		for (int j = 0; j < A[i]; j++) {
			printf("%hd ", current);
		}
		if (current > 0) current = 0;
		else current = 1;
	}
	printf("\nRES = %d", res);
	printf("\n\n\n\n");
	delete[] A;
}


void input(short Y[], int lenght)
{
	for (int i = 0; i < lenght; i++) {
		printf("Y[%d] = ", i); scanf_s("%hd", &Y[i]);
	}
}
