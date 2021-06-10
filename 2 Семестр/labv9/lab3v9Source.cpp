#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "stdio.h"
#include <vector>

using namespace std;

struct sport {
	char surname[10];
	char country[5];
	short place;

	void Get_Data() 
	{
		cout << "surname: "; cin >> surname;
		cout << "country: "; cin >> country;
		cout << "place: "; cin >> place;
		cout << endl;
	}
	void Print() {
		cout << "surname: " << surname<<"\t";
		cout << "\tcountry: " << country<<"\t";
		cout << "\tplace: " <<place<<"\n";
	}
	sport() { memset(surname, 0, sizeof(surname));
	memset(country, 0, sizeof(country));
	place = 0;}
};

struct sport_country {
	char name[5];
	short golds, silvers, bronzes;

	void Print() {
		cout << "country: " << name << "\n";
		cout << "\tgold medals: " << golds << "\n";
		cout << "\tsilver medals: " << silvers << "\n";
		cout << "\tbronze medals: " << bronzes << "\n\n";
	}
	void Set_Name(char new_name[5]) {
		for (int i=0; i<5;i++) name[i] = new_name[i];
	}
	sport_country() {
		memset(name, 0, sizeof(name));
		golds = 0; silvers = 0; bronzes = 0;
	}
	sport_country(char name[5]) 
	{
		golds = 0; silvers = 0; bronzes = 0;
		Set_Name(name);
	}
};


int main() 
{	
	FILE* bin_sportsmen, *bin_country;
	bin_sportsmen = fopen("binary-sportsmen.dt", "wb");
	

	int n;
	cout << "number of sportsmen: "; cin >> n;
	
	vector<string> all_countries;
	
	sport guy = sport();

	int size = 15 * sizeof(char) + sizeof(short);
	int size_country = 5 * sizeof(char) + 3 * sizeof(short);

	for (int i = 0; i < n; i++) {
		guy.Get_Data();
		fwrite(&guy, size, 1, bin_sportsmen);

		guy = {};
	}
	fclose(bin_sportsmen);

	bin_country = fopen("binary-countries.dt", "wb+");
	fseek(bin_country, 0, SEEK_SET);
	bin_sportsmen = fopen("binary-sportsmen.dt", "rb");

	sport_country country_info;

	int positions = 0;
	for (int i = 0; i < n; ++i) 
	{
		bool flag = false;
		fread(&guy, size, 1, bin_sportsmen);
		for (int j = 0; j < all_countries.size(); j++) { 
			if (guy.country == all_countries[j])
			{
				flag = true;
				fseek(bin_country, j*size_country, SEEK_SET);
			}
		}
		if (!flag) { 
			fseek(bin_country, positions*size_country, SEEK_SET);
			++positions;
			all_countries.push_back(guy.country);
			country_info.Set_Name(guy.country);
			country_info.bronzes, country_info.silvers, country_info.golds = 0;
		}
		if (flag) {
			fread(&country_info, size_country, 1, bin_country);
			fseek(bin_country, -size_country, SEEK_CUR);
		}
		
		switch (guy.place) { case 1: country_info.golds += 1; break; case 2: country_info.silvers += 1; break; case 3: country_info.bronzes += 1; break; default:break; }

		fwrite(&country_info, size_country, 1, bin_country);
		fseek(bin_country, positions*size_country, SEEK_SET);
		guy = {};
		country_info = {};
	}
	fclose(bin_sportsmen);
	fclose(bin_country);

	cout << "all countries: \n";
	
	bin_country = fopen("binary-countries.dt", "rb");
	for (int i = 0; i < positions; i++) 
	{
		fread(&country_info, size_country, 1, bin_country);
		country_info.Print();
		cout << endl;
		country_info = {};
	}

	unsigned short country_num;
	cout << "\nchoose country number:  "; cin >> country_num; --country_num;
	fseek(bin_country, country_num * size_country, SEEK_SET);
	fread(&country_info, size_country, 1, bin_country);
	country_info.Print();
	fclose(bin_country);

	return 0; 
}

/*
void Show_Sportsmen(FILE* bin_sportsmen,int size,int n, sport structure)
{
	bin_sportsmen = fopen("binary-sportsmen.dt", "rb");
	for (int i = 0; i < n; i++)
	{
		fread(&structure, size, 1, bin_sportsmen);
		structure.Print();
		cout << endl;
		structure = {};
	}
}
*/