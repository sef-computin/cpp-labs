#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

void Write_File(string, string, double);
void Write_File(string, string);
void Read_File(string);

int main() 
{
	double middle=0.;
	int len;
	int n;
	cout << "Enter number of cities" << endl;
	cin >> len;
	fstream file;
	file.open("cities.txt", ios::app);
	for (int i = 0; i < len; i++) {
		cout << i + 1 << ". ";
		//char* city = new char;
		string city;
		double temperature;
		cin >> city >> temperature;
		middle += temperature;
		file << city << " - " << temperature << endl;
	}
	file.close();
	
	cout << "> writing completed" << endl;

	ifstream ifile;
	
	middle /= len;

	ifile.open("cities.txt");
	if (!ifile.fail()) 
	{
		string word;
		vector<string>phrase;
		n = 0;
		while (ifile >> word) { n++; if (n % 3 == 0) middle += atoi(word.c_str()); }
		ifile.clear();
		ifile.seekg(0);

		middle /= len;
		n = 3;
		while (ifile>>word) 
		{
			phrase.push_back(word);
			n--;
			if (n == 0) {
				if (atoi(phrase[2].c_str()) > middle) { Write_File("cities-high.txt", phrase[0]); }
				else Write_File("cities-low.txt", phrase[0]);
				phrase.clear();
				n = 3;
			}
		}
	}
	ifile.close();
	cout << "> sorting completed";
	return 0;
}


void Write_File(string path, string city, double temp) 
{
	fstream file;
	file.open(path, ios::app);
	if (file) { file << city << " - " << temp << endl; }
	file.close();
}
void Write_File(string path, string city) {
	fstream file;
	file.open(path, ios::app);
	if (file) { file << city << endl; }
	file.close();
}

void Read_File(string path) 
{
	fstream file;
	file.open(path, ios::in);
	string a;
	if (!file.fail())
	{
		while (!file.eof())
		{
			file >> a; cout << a << endl;
		}
	}
	file.close();
}

string Read_String(string path, int needed_string) 
{
	int n = 0;
	fstream file;
	file.open(path, ios::in);
	if (!file.fail()) 
	{
		while (!file.eof()) 
		{
			if (n == needed_string) {
				string buff;
				file >> buff;
				file.close();
				return buff;
			}
			++n;
		}
		cout << "> End of file reached. index is out of range\n";
		file.close();
		return "";
	}
	cout << "> There seems to be an error";
	file.close();
	return "";
}
