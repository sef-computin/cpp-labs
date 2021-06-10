#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct student {
	string surname;
	short marks[3];
	student* Ladr;
	student* Radr;
};
struct studentbin {
	char* surname;
	short marks[3];
	studentbin() 
	{
		surname = (char*)malloc(15);
	}
	void Print() 
	{
		cout << endl;
		cout <<setw(15)<< surname << "   ";
		for (int i = 0; i < 3; i++)cout << marks[i]<<' ';
		cout << endl;
	}
};

student* Find(student*, student*, string*);
void view(student*);

int main() {
	student* nach=NULL, *kon=NULL;
	fstream file;
	file.open("students.txt", ios::in);
	if (!file.fail()) {
		while (!file.eof()) {
			student* temp;
			temp = new(student);
			file >> temp->surname;
			for (int i = 0; i < 3; i++) file >> temp->marks[i];
			if (nach == NULL) {
				nach = temp;
				kon = temp;
				temp->Ladr = NULL;
				temp->Radr = NULL;
			} else {
				student* index = Find(nach, kon, &(temp->surname));
				if (index == NULL) {
					temp->Radr = NULL;
					temp->Ladr = kon;
					kon->Radr = temp;
					kon = temp;
				}
				else if (index == nach) {
					index->Ladr = temp;
					nach = temp;
					temp->Radr = index;
				} 
				else{
					index->Ladr->Radr = temp;
					temp->Ladr = index->Ladr;
					index->Ladr = temp;
					temp->Radr = index;
				}
				
			}
			view(nach);
		}
	}
	file.close();

	FILE* bin;
	bin = fopen("students-bin.dt", "wb");
	student* temp = nach;
	int size = 15 + 3 * sizeof(short);
	while (temp != NULL) 
	{
		studentbin d = studentbin();
		strcpy(d.surname, temp->surname.c_str());
		copy(begin(temp->marks),end(temp->marks), d.marks);
		fwrite(&d, size, 1, bin);
		temp = temp->Radr;
	}
	fclose(bin);

	bin = fopen("students-bin.dt", "rb");
	studentbin d = studentbin();
	while (fread(&d, size, 1, bin))
	{
		d.Print();
	}
	fclose(bin);
	
	return 0;
}

student* Find(student* nach, student* kon, string* name)
{
	student* temp = nach;
	while ((temp->surname < *name) && (temp != kon)) { temp = temp->Radr; }
	if (temp == kon) return NULL;
	else return temp;
}


void view(student* nach)
{
	student* temp;
	temp = nach;
	cout << "[LIST] ";
	while (temp != NULL) {
		cout << temp->surname << "    ";
		temp = temp->Radr;
	}
	cout << endl << endl;
}
