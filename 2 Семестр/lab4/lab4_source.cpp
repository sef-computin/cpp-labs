#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void write_file(string path, char[10], short, short*);


class My_Exception
{public :
	My_Exception(string message) 
	{
		cerr << message;
	}

};


int main() 
{
	try {
		char surname[15];
		short student_count;

		string path = "students-info.tx";
		string path2 = "students-best.txt";

		bool flag;
		cout << "Add info? "; cin >> flag;
		if (flag) {
			cout << "Enter number of students >> "; cin >> student_count;
			if (student_count < 0) { throw My_Exception("number cannot be negative"); }

			short exams, * res;

			for (int i = 0; i < student_count; i++) {
				cin >> surname >> exams;
				res = new short[exams];
				for (int j = 0; j < exams; ++j) cin >> res[j];
				write_file(path, surname, exams, res);
				delete[] res;

			}
		}
		double average = 0;
		int count = 0;
		short count_marks = 0;

		fstream file;
		file.open(path, ios::in);
		if (file.fail()) { throw My_Exception("Reading file error"); }

		while (true)
		{
			file >> surname;
			if (file.eof()) break;
			file >> count;
			for (int j = 0; j < count; j++)
			{
				short mark;
				file >> mark;
				if (mark > 2) { average += mark; count_marks++; }
			}
		}
		average /= count_marks;


		file.clear();
		file.seekg(0);

		bool f_flag;
		fstream resfile;
		resfile.open(path2, ios::out);
		if (resfile.fail()) { throw My_Exception("Opening file for writing error"); }
		resfile << "List of students above average. AVERAGE = " << average << endl;


		while (true)
		{
			double individual = 0;
			count_marks = 0;
			f_flag = false;
			file >> surname;
			if (file.eof()) break;
			file >> count;
			for (int j = 0; j < count; j++)
			{
				short mark;
				file >> mark;
				if (mark > 2) { individual += mark; count_marks++; }
				else f_flag = true;
			}
			if ((individual / count_marks > average) && (!f_flag)) { resfile << surname << endl; }
		}

		file.close();
		resfile.close();
	}
	catch (My_Exception & ex) { cout << endl << "Program ended with an exception"; }

	cerr << "\n\n\n";

	return 0;
}

void write_file(string path, char name[10], short exams, short* res) {
	fstream file;
	file.open(path, ios::app);
	if (file.fail()) { throw My_Exception("Opening file for writing error"); }
	file << name <<" "<< exams;
	for (int i = 0; i < exams;++i)file <<" "<< res[i] ;
	file << endl;
	file.close();
}