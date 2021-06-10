#include <iostream>
template<class IN> void Input(IN input_data, int lenght);
template <class OUT> void Output(OUT, int);

typedef int (*CompareFunctionType)(void*, void*);

int FindMinimumIndex(int[], int, int, CompareFunctionType);
void Swap(int&, int&);
template<class SORT>void SelectionSort(SORT*, int, CompareFunctionType);


int CompareInt0to9(void*, void*);
int CompareInt9to0(void*, void*);
//
int main()
{
	typedef int datatype;
	int len, sort_type;
	int array[10];
	printf("MinToMax (1) or MaxToMin (2)\n");
	scanf_s("%d", &sort_type);
	const int kFunctionsCount = 2;
	scanf_s("%d", &len);
	CompareFunctionType compare_function_pointers[kFunctionsCount];
	compare_function_pointers[0] = &CompareInt0to9;
	compare_function_pointers[1] = &CompareInt9to0;
	Input(array, len);
	SelectionSort(array, len, compare_function_pointers[sort_type-1]);
	Output(array, len);
	return 0;
}
template<class IN>
void Input(IN array, int width) {
	for (int i = 0; i < width; i++) std::cin >> array[i];
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
template<class SORT>void SelectionSort(SORT* input_data, int lenght, CompareFunctionType compare_function_pointer);
void SelectionSort(SORT* input_data[], int lenght, CompareFunctionType compare_function_pointer) {
	for (int i = 0; i < lenght - 1; i++) {
		int min_index = FindMinimumIndex(input_data, i, lenght, compare_function_pointer);
		Swap(input_data[i], input_data[min_index]);
	}
}
template<class OUT>
void Output(OUT array, int width) {
	for (int i = 0; i < width; i++) std::cout << array[i] << ",";
	printf("\n");
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