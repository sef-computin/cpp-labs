#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <vector>


class Number {
public:
	std::vector<unsigned int> digits_before;
	std::vector<unsigned int> digits_after;
	//bool neg;
	
	short len_before;
	short len_after;

	Number() {
		digits_before = {0};
		digits_after = {0};
		len_before = 0;
		len_after = 0;
	}
};

struct longarithmetics {
	FILE* file;
	int* len;
};



Number custom_read(char* file_name) 
{
	FILE* file;
	file = fopen(file_name, "r");
	int count = 0;
	bool flag = true;
	Number number = Number();
	char sym;
	printf("=================================================================================\n");
	printf("value = ");
	while (!feof(file)) 
	{
		fread(&sym, sizeof(char), 1, file);
		if (sym == '.') {
			flag = !flag;
			printf(".");
			continue;
		}
		if (number.len_before > 9) {
			number.digits_before.push_back(0);
		}
		if (number.len_after > 9) {
			number.digits_before.push_back(0);
		}
		if (flag) 
		{
			number.digits_before[number.len_before/9]+=((int)sym)*pow(10, 9 - (number.len_before++%10)); //проверить
		}
		else {
			number.digits_after[number.len_after / 9] += ((int)sym) * pow(10, 9 - (number.len_before++ / 9));
		}
		printf("%c", sym);
	}
	printf("\n=================================================================================\n");
	fclose(file);
	printf("\n");
	for (int i = 0; i < number.digits_before.size(); i++) 
	{
		printf("%d", number.digits_before[i]);
	}


	
	return number;
}