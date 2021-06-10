#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include "Header.h"
using namespace std;


int main(int argc, char* argv[])
{
	char* filename;
	char* filename_res;
	char* filename_error;
	if (argc < 2) {
		printf("Missing arguments. Default filenames will be given\n");
		filename = (char*)"test.txt";
		filename_res = (char*)"res.txt";
		filename_error = (char*)"errors.txt";
	}
	else {
		filename = argv[1];
		filename_res = argv[2];
		filename_error = argv[3];
	}
	
	BigNumber Bignumber;

	string number;

	string fullpart;
	string fraction;

	fstream ifile;
	ifile.open(filename, ios::in);

	getline(ifile, number);

	cout << "\n" << number << "\n";
	bool flag = true;
	for (int i = 0; i < number.size(); i++) 
	{
		char c = number[i];
		if (c == '.') { flag = false; continue; }
		if (flag) { fullpart.push_back(c); }
		else { fraction.push_back(c); }
	}
	Bignumber.read(fullpart, fraction);
	
	string a;

	getline(ifile, a);
	
	int degree;
	degree = stoi(a);
	cout << "Degree ^ " << degree<<"\nResult:  ";

	Bignumber = BigDegree(Bignumber, degree);

	Bignumber.showcase();

	FILE* ofile;
	ofile = fopen(filename, "w");
	string res = Bignumber.ToString();
	fwrite(&res, sizeof(res), 1, ofile);
	fclose(ofile);
	ifile.close();
	return 0;
}