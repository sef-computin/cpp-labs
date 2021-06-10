#include <iostream>
#include "math.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	do {
		printf("Введите длину массива, n<=25\t");
		scanf_s("%d", &n);
	} while (n > 25);

	double Xn[25];

	printf("Пропишите элементы массива\n");
	double sum = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("\n#%d ", i + 1);
		scanf_s("%lf", &Xn[i]);
		sum += Xn[i];
	}
	double algebr = sum / n;
	double maxmove = 0;
	int maxmoveindex = -1;
	for (i = 0; i < n; i++) {
		if (fabs(Xn[i] - algebr) > maxmove) { 
			maxmove = fabs(Xn[i] - algebr);
			maxmoveindex = i+1;
		}
	}
	printf("\n\nСреднее арифметическое --> %lf\nМаксимальный сдвиг --> %lf\nЭлемент номер %d", algebr, maxmove, maxmoveindex);
}