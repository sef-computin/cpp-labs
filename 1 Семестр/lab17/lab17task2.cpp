//lab17 task 2
#include <iostream>
void InputArray(int[10000], int);
int FindMinimumIndex(int[], int, int);
void Swap(int&, int&);
void SelectionSort(int[], int);
void OutputArray(int[], int);
int Compare(void*, void*);
//
int main()
{
	int len;
	int* Array;
	printf("Array:\n");
	scanf_s("%d", &len);
	while (len > 10000) { printf("out of maximum range\n"); scanf_s("%d", &len); }
	Array = (int*)malloc(len * sizeof(int));
	InputArray(Array, len);
	SelectionSort(Array, len);
	OutputArray(Array, len);
	return 0;
}
void InputArray(int input_data[], int lenght) {
	for (int i = 0; i < lenght; i++) scanf_s("%d", &input_data[i]);
	printf("\n");
}
int FindMinimumIndex(int input_data[],
				int first_index, int last_index) {
	int minindex = first_index;
	int min = input_data[first_index];
	for (int i = first_index + 1; i < last_index; i -= -1) {
		if (Compare(&input_data[i], &min) < 0) { min = input_data[i]; minindex = i; }
	} return minindex;
}
void Swap(int& first_element, int& second_element) {
	int temp = first_element;
	first_element = second_element;
	second_element = temp;
}
void SelectionSort(int input_data[], int lenght) {
	for (int i = 0; i < lenght - 1; i++) {
		int min_index = FindMinimumIndex(input_data, i, lenght);
		Swap(input_data[i], input_data[min_index]);
	}
}
void OutputArray(int input_data[], int lenght) {
	printf("%d\n", lenght);
	for (int i = 0; i < lenght; i++) printf("%d\n", input_data[i]);
}
int Compare(void* first_pointer, void* second_pointer) { 
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *first_element_int_pointer-*second_element_int_pointer; 
}

