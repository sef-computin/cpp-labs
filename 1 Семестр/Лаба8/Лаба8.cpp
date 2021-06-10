// Лаба8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	float x, y1, y2, y3;
	printf("enter x:  ");
	scanf_s("%f", &x);
	x = -x;
	if (x == 0) { printf("function undefined\n\n\n"); return 0; }
	
	//y1 - if else без логики
	else {
		if (abs(x) <= 1) { y1 = 0; }
		else {
			if (abs(x) <= 2) { y1 = 1 / (x / abs(x)); }
			else { y1 = 2 / (x / (abs(x))); }
		}
	}

	//y2 - if и логика
	if (abs(x)<=1) {y2 = 0;}
	if (abs(x)>1 && abs(x)<=2) {y2=1/(x/abs(x));}
	if (abs(x)>2) { y2 = 2/(x/abs(x));}

	//y3 - тернарный оператор
	y3 = (abs(x)<=1)?0:(abs(x)<=2)?(1/(x/abs(x))):(2/(x/(abs(x))));

	//вывод
	printf("y1 = %.2f\ny2 = %.2f\ny3 = %.2f\n\n\n", y1, y2, y3);
}