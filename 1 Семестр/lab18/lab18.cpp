// lab18 task1
#include <iostream>

unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;

void SelectionSort(int input_array[], int lenght);
int FindMinimumIndex(int input_data[], int first_index, int last_index);
void Swap(int&, int&);
template <class OUT> void Output(OUT*, int);
void BubbleUpSort(int input_array[], int lenght);
void InsertSort(int input_array[], int lenght);
int CompareIndexes(void*, void*);

typedef void (*SortFunctionType)(int[],int);

int main() {
	int arr[10] = { 0,12,54,3,4,5,6,7,88,9 };

	SortFunctionType sort_functions[3] = {&BubbleUpSort,&SelectionSort, &InsertSort};

	std::cout << "0 = Bubble Sort\n1 = Selection Sort\n2 = Insert Sort\n" << std::endl;
	int sort_type; scanf_s("%d", &sort_type);
	
	(*sort_functions[sort_type])(arr, 10);
	Output(arr, 10);

	std::cout << "\ncopy_counter -> "<<copy_counter<<";\tcompare_counter -> "<<compare_counter;
	return 0;
}

int FindSorted(int input_array[], int lenght) {
	int n = 0;
	while (n < lenght) {
		++compare_counter;
		int min_index = FindMinimumIndex(input_array, n, lenght);
		if (min_index == n) { ++compare_counter; n++; }
		else break;
	}
	return n;
}

int FindMinimumIndex(int input_data[],
	int first_index, int last_index) {
	int minindex = first_index;
	int min = input_data[first_index];
	for (int i = first_index + 1; i < last_index; i -= -1) {
		if (input_data[i] < min) { ++compare_counter; min = input_data[i]; minindex = i; }
		copy_counter += (last_index - first_index + 1);
	} return minindex;
}

void Swap(int& first_element, int& second_element) {
	int temp = first_element;
	first_element = second_element;
	second_element = temp;
	copy_counter += 3;
}

void SelectionSort(int input_array[], int lenght) {
	std::cout << "SelectionSort\n";
	int* first_index = (int*)FindSorted(input_array, lenght);
	for (int i = (int)first_index; i < lenght - 1; i++) {
		int min_index = FindMinimumIndex(input_array, i, lenght);
		Swap(input_array[i], input_array[min_index]);
		copy_counter += (lenght-(int)first_index);
	}
}
void BubbleUpSort(int input_array[], int lenght) {
	std::cout << "BubbleSort\n";
	int* first_index = (int*)FindSorted(input_array, lenght);
	for (int i = (int)first_index; i < lenght; i++) {
		int min_index = FindMinimumIndex(input_array, i, lenght);
		if (CompareIndexes(&min_index, &i) == 0) continue;
		if (CompareIndexes(&min_index, &i) > 0) Swap(input_array[min_index], input_array[i]);
		copy_counter += (lenght - (int)first_index);
	}
}
void InsertSort(int input_array[], int lenght) {
	std::cout << "InsertSort\n";
	int* first_index = (int*)FindSorted(input_array, lenght);
	for (int i = (int)first_index+1; i < lenght; i++) {
		for (int j = (int)first_index; j < i; j++) if (input_array[j] > input_array[i]){
			++compare_counter;
			Swap(input_array[j], input_array[i]);
			continue;
			copy_counter += (i - (int)first_index+1);
		}
		copy_counter += (lenght - (int)first_index);
	}
}
template <class OUT> 
void Output(OUT* arr, int len) {
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i] << " ";
		copy_counter += (len + 1);
	}
}

int CompareIndexes(void* first_pointer, void* second_pointer)
{
	++compare_counter;
	int* first_int_pointer=(int*)first_pointer;
	int* second_int_pointer = (int*)second_pointer;
	return *first_int_pointer-*second_int_pointer;
}
