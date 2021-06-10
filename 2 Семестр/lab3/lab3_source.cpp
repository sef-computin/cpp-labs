#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <iostream>
using namespace std;

struct ticket 
{
	char station[10];

	short zone;
	float price_normal;
	float price_child;

};

int main() 
{
	float A;
	int n;
	FILE* binary_file;
	binary_file = fopen("binary-file.dt", "wb");
	cout << "define A "; cin >> A;
	cout << "number of stations "; cin >> n;
	int k = n;
	
	ticket tick = ticket();
	while (n!=0) 
	{
		cout << endl;
		cout << "station - "; cin >> tick.station;
		cout << "zone - "; cin >> tick.zone;
		tick.price_normal = A * tick.zone; 
		tick.price_child = tick.price_normal/4;
		fwrite(&tick, sizeof(int) + 10*sizeof(char) + sizeof(short) + 2*sizeof(float), 1, binary_file);
		tick = {}; --n;
	}
	fclose(binary_file);

	binary_file = fopen("binary-file.dt", "rb");

	cout << endl;

	while (k!=0) 
	{
		fread(&tick, sizeof(int) + 10 * sizeof(char) + sizeof(short) + 2 * sizeof(float), 1, binary_file);
		cout << "station: " << tick.station << "\t zone: " << tick.zone << "\t price for adults: " << tick.price_normal << "\t price for kids: " << tick.price_child<<endl;
		tick = {};
		k--;
	}

	//cout << "print the number of a station"; cin >> n;
	//fseek(binary_file,(n-1)* (sizeof(int) + 10 * sizeof(char) + sizeof(short) + 2 * sizeof(float)), SEEK_SET);
	//fread(&tick, sizeof(int) + 10 * sizeof(char) + sizeof(short) + 2 * sizeof(float), 1, binary_file);
	//cout << "station: " << tick.station << "\t zone: " << tick.zone << "\t price for adults: " << tick.price_normal << "\t price for kids: " << tick.price_child << endl;
	tick = {};
	fclose(binary_file);
	return 0;
}

