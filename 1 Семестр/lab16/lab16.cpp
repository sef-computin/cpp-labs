#include <iostream>
#include "math.h"
//простое - квадраты
//не простое - кубы

//нерекурсивная
bool checkPrime_nonRec(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) { return false; }
	}
	return true;
}


//рекурсивная
bool checkPrime_Rec(int x, int i) {
	if (i == x / 2) return true;
	if (x % i == 0)	return false;
	else checkPrime_Rec(x, i + 1);
}


int main()
{
	bool prime;
	int num;
	printf("Enter number\t");
	scanf_s("%d", &num);
	printf("Output from non-recursive function -> \"");
	
	if (checkPrime_nonRec(num)) {
		prime = true; printf("Prime number\"");
	}
	else {
		prime = false; printf("NOT a Prime number\"");
	}
	
	printf("\nOutput from recursive function -> \"");
	if (checkPrime_Rec(num, 2)) printf("Prime number\"");
	else printf("NOT a Prime number\"");
	printf("\n\n");

	//доп задание
	int grade;
	if (prime) grade = 2;
	else grade = 3;
	int n = 1;
	while (pow(n, grade) <= num) { printf(">> %d -> %.1lf\n", n, pow(n, grade)); n++;}
	printf("\n\n\n\n");

}