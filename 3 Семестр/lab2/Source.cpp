#include <iostream>
#include <string>
#include <fstream>

#include <vector>

using namespace std;


vector<int> GnomeSort(vector<int> line) 
{
	int index = 0;
	while (index < line.size()) {
		if (index == 0) index++;
		if (line[index] >= line[index - 1]) { //if the element is greater than previous one
			index++;
		}
		else {
			swap(line[index], line[index - 1]);
			index--;
		}
	}
	return line;
}

int main(int argc, char* argv[])
{
	bool sort_flag = false;
	char* filename_input;
	char* filename_res;
	if (argc < 2) {
		printf("Missing arguments. Default filenames will be given\n");
		filename_input = (char*)"input.txt";
		filename_res = (char*)"result.txt";
	}
	else {
		filename_input = argv[1];
		filename_res = argv[2];
		if (argv[3] == "-t")sort_flag = false;
	}
	

	fstream file;
	fstream res_file;
	vector<int> arr;
	file.open(filename_input, ios::in);
	res_file.open(filename_res, ios::out);
	string a;
	if (!file.fail())
	{
		while (getline(file, a))
		{
			string temp = "";
			for (int i = 0; i < a.size(); i++)
			{
				if (isdigit(a[i])) temp.push_back(a[i]);
				if ((a[i] == ' ')&&(temp!=""))
				{
					arr.push_back(stoi(temp));
					temp = "";
				}
			}
			if (sort_flag) arr = GnomeSort(arr);
			for (int i = 0; i < arr.size(); i++) 
			{
				res_file << arr[i] << ' ';
			}
			res_file << '\n';
			arr = {};
		}
		
	}
	res_file.close();
	file.close();
	
	return 0;
}


