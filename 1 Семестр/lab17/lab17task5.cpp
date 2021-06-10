#include <iostream>
template <class DATA>
	void SortMinToMax(int width, DATA* data_array) {
		DATA temp;
		for (int i = 0; i < width; i++) {
			DATA min = data_array[i];
			int min_index = i;
			for (int j = i; j < width; j++) {
				if (min > data_array[j]) { min = data_array[j]; min_index = j; }
			}
			temp = data_array[min_index];
			data_array[min_index] = data_array[i];
			data_array[i] = temp;
		}
	}
template <class OUT>
void Output(int width, OUT array) {
	for (int i = 0; i < width; i++) std::cout << array[i] << " ";
}


void InputInt(int[], int);
void InputChar(char[],int);
int main() 
{
	int lenght;
	scanf_s("%d", &lenght);
	const int kLenght = 100;
	int my_int_array[kLenght];
	char my_char_array[100];
	printf("Input Int:\n");
	InputInt(my_int_array, lenght);
	printf("input Char:\n");
	InputChar(my_char_array, lenght);
	SortMinToMax(lenght, my_char_array);
	SortMinToMax(lenght, my_int_array);
	printf("int array:  "); Output(lenght, my_int_array);
	printf("\tchar array:  "); Output(lenght, my_char_array);
	
}
void InputInt(int input_array[], int lenght) {
	for (int i = 0; i < lenght; i++) scanf_s("%d", &input_array[i]);
}
void InputChar(char input_array[], int lenght) {
	for (int i = 0; i < lenght; i++) std::cin >> input_array[i];
}

