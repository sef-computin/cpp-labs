// lab17 task 4
#include <iostream>
void InputArray(int[10000], int);
typedef int (*CompareFunctionType)(void*, void*);
int FindMinimumIndex(int[], int, int, CompareFunctionType);
void Swap(int&, int&);
void SelectionSort(int[], int, CompareFunctionType);
void OutputArray(int[], int);
int Compare(void*, void*);
int CompareInt0to9(void*, void*);
int CompareInt9to0(void*, void*);
//
int main()
{
	int len, sort_type;
	int* Array;
	printf("0to9 (1) or 9to0 (2)\n");
	scanf_s("%d", &sort_type);
	printf("Array:\n");
	scanf_s("%d", &len);
	while (len > 10000) { printf("out of maximum range\n"); scanf_s("%d", &len); }
	Array = (int*)malloc(len * sizeof(int));
	const int kFunctionsCount = 2;
	CompareFunctionType compare_function_pointers[kFunctionsCount];
	compare_function_pointers[0] = &CompareInt0to9;
	compare_function_pointers[1] = &CompareInt9to0;
	InputArray(Array, len);
	SelectionSort(Array, len, compare_function_pointers[sort_type - 1]);
	OutputArray(Array, len);
	return 0;
}
void InputArray(int input_data[], int lenght) {
	for (int i = 0; i < lenght; i++) scanf_s("%d", &input_data[i]);
	printf("\n");
}
int FindMinimumIndex(int input_data[],
	int first_index, int last_index,
	CompareFunctionType compare_function_pointer) {
	int minindex = first_index;
	int min = input_data[first_index];
	for (int i = first_index + 1; i < last_index; i -= -1) {
		if ((*compare_function_pointer)(&input_data[i], &min) < 0) { min = input_data[i]; minindex = i; }
	} return minindex;
}
void Swap(int& first_element, int& second_element) {
	int temp = first_element;
	first_element = second_element;
	second_element = temp;
}
void SelectionSort(int input_data[], int lenght, CompareFunctionType compare_function_pointer) {
	for (int i = 0; i < lenght - 1; i++) {
		int min_index = FindMinimumIndex(input_data, i, lenght, compare_function_pointer);
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
	return *first_element_int_pointer - *second_element_int_pointer;
}

int CompareInt0to9(void* first_pointer, void* second_pointer) {
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *first_element_int_pointer - *second_element_int_pointer;
}
int CompareInt9to0(void* first_pointer, void* second_pointer) {
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *second_element_int_pointer - *first_element_int_pointer;
}