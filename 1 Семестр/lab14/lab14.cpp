#include <iostream>
#include "math.h"

void main() 
{

	int m;
	
	const int mmax = 10;
	
	//int F[mmax][mmax];

	printf("Enter Matrix width  ");
	scanf_s("%d", &m);

	int **F = new int*[m];
	for (int i = 0; i < m; i++) F[i] = new int[m];
	
	printf("Enter values\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) { scanf_s("%d", &F[i][j]); }
	}
	

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) { printf("%i  ", F[i][j]); }
		printf("\n");
	}

	int maxbelow = F[1][0];
	int res = 0;
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) { if(F[i][j]>maxbelow) maxbelow = F[i][j]; }
	}

	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) { if (F[i][j] > maxbelow) { res += F[i][j]; count++; } }
	}
	if (count == 0) printf("Not possible");
	else printf("\n\nResult equals %d\n\n\n\n\n\n", res);
	for (int i = 0; i < m; i++) delete[] F[i];
	delete[] F;
}