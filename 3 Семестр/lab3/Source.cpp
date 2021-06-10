#include <iostream>
#include "stdio.h"
#include "stdlib.h"

#include "Header.h"

using namespace std;
int main() 
{
	//вариант 9 - сравнить число закрывающих и открывающих скобок
	char str[256];
	cin.getline(str, 256);
	cout << "\nYou wrote: " << strlen(str) << " symbols\n";
	String a = String(str);
	cout << "You typed : "; a.PrintString();
	cout << "quantity of \'(\' : " << a.HowManySymbols('(') << endl;
	cout << "quantity of \')\' : " << a.HowManySymbols(')') << endl;
	


	return 0;
}