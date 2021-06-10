#include <iostream>

int main() 
{
	setlocale(LC_ALL, "Russian");
	
	//Способ 1 (do while)

	float capital = 10000;
	double percentage = 3.;
	int count = 0;
	double persum = 0;
	do 
	{
		if (percentage > 3.5) percentage = 3.5;
		printf("Процент - %.4lf%%;\t", percentage);
		persum += percentage;
		capital += (capital / 100) * percentage;
		if (percentage < 3.5) percentage *= 1.05;
		count++;
		printf("Сумма вклада - $%.1f\n", capital);
	} while (capital <= 20000);
	printf("\nСредний процент = %lf\n", persum/count);
	if (count % 10 < 5 && count % 10 > 0) {
		printf("\nУ Пети будет $20k на вкладе через %d год\n", count);
	}
	else printf("\nУ Пети будет $20k на вкладе через %d лет\n", count);

	// Способ 2 (for)

	capital = 10000;
	percentage = 3.;
	count = 0;
	for ( ; capital < 20000; count++) 
	{
		if (percentage > 3.5) percentage = 3.5;
		capital += (capital / 100) * percentage;
		if (percentage < 3.5) percentage *= 1.05;
	}
	if (count % 10 < 5 && count % 10 > 0) {
		printf("\nУ Пети будет $20k на вкладе через %d год\n", count);
	}
	else printf("\nУ Пети будет $20k на вкладе через %d лет\n", count);

	// Способ 3 (Бесконечный цикл)

	capital = 10000;
	percentage = 3.;
	count = 0;
	while (true)
	{
		if (percentage > 3.5) percentage = 3.5;
		capital += (capital / 100) * percentage;
		if (percentage < 3.5) percentage *= 1.05;
		count++;
		if (capital >= 20000) {
			if (count % 10 < 5 && count % 10 > 0) {
				printf("\nУ Пети будет $20k на вкладе через %d год\n", count);
			}
			else printf("\nУ Пети будет $20k на вкладе через %d лет\n", count);
			return 0;
		}
	}
}