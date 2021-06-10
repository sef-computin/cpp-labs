#include "header.h"
#include <fstream>

int main(int argc, char* argv[])
{
	
	char* filename;
	if (argc < 2) {
		printf("Missing argument. Default filename will be given\n");
		filename = (char*)"test.txt";
	} else {
		filename = argv[1];
	}
	Number Bignumber = custom_read(filename);
	//printf("lenght = %d\n", *longnumber.len);
	
	return 0;
}