#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int len = 3;

typedef struct structure 
{
	//char str[len];
	string str;
	structure *Ladr;
};

bool digits_check(string);

int main() 
{
	structure* kon = NULL;

	int n;
	vector<string> vector_strings;
	cout << "enter number of strings: "; cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vector_strings.push_back(temp);
	}
	int intcount = 0;
	for (int i = 0; i < n; i++) 
	{
		if (digits_check(vector_strings[i])) 
		{
			string temp = vector_strings[i];
			vector_strings.erase(vector_strings.begin()+i);
			vector_strings.insert(vector_strings.begin(), temp);
			intcount++;
		}
	}
	
	for (int i = 0; i < intcount; i++) {
		for (int j = i+1; j < intcount; j++) {
			if (atoi(vector_strings[j].c_str()) < atoi(vector_strings[i].c_str()))
			{
				string temp = vector_strings[i];
				vector_strings[i] = vector_strings[j];
				vector_strings[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		structure* temp;
		temp = new(structure);
		temp->str = vector_strings[i];
		if (kon == NULL) { temp->Ladr = NULL; kon = temp; }
		else { temp->Ladr = kon; kon = temp; }
	}

	cout << endl;
	structure* temp;
	temp = kon;
	while (temp != NULL) { cout << temp->str << "\t"; temp = temp->Ladr; }
}

bool digits_check(string str) 
{
	try {
		int intstr = atoi(str.c_str());
		if ((int)(log10(intstr) + 1) == str.length()) { 
			return true; }
		else return false;
	}
	catch (exception) { return false; }

}


