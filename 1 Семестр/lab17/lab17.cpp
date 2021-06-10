// lab17
#include <iostream>
typedef int (*CompareFunctionType)(void*, void*);
void SwapChar(char*, char*);
void Swap(void*, void*, int);
template <class OUT> void Output(int , OUT );
template<class IN> void Input(int , IN );
template<typename MINTOMAX>void SortMinToMax(int, MINTOMAX*);
template<typename MAXTOMIN>void SortMaxToMin(int, MAXTOMIN*);
template<class SORT>void SelectionSort(SORT*, int, int);

//
int main()
{
	
	int sort_type;
	printf("1) MinToMax\n2) MaxToMin\n");
	scanf_s("%d", &sort_type);
	
	const int kFunctionsCount = 2;
	
	CompareFunctionType compare_function_pointers[kFunctionsCount];

	const int kLenght = 100;

	//доп задание -- объявление массива double (для удобства через typedef)
	typedef double mytype;
	mytype my_array[kLenght];
	//

	int my_int_array[kLenght];
	char my_char_array[100];
	int len;
	scanf_s("%d", &len);
	printf("int:\n");
	Input(len, my_int_array);
	printf("char\n");
	Input(len, my_char_array);

	// доп задание -- ввод массива double
	printf("double:\n");
	Input(len, my_array);
	//

	SelectionSort(my_int_array, len, sort_type);
	SelectionSort(my_char_array, len, sort_type);
	
	// доп задание -- сортировка массива double 
	SelectionSort(my_array, len, sort_type);
	//

	printf("int:  ");
	Output(len, my_int_array);
	printf("char:  ");
	Output(len, my_char_array);
	
	// доп задание вывод массива double
	printf("double:  ");
	Output(len, my_array);
	//

	return 0;
}

void SwapChar(char* first_pointer, char* second_pointer) { 
	char temp = *first_pointer;  
	*first_pointer = *second_pointer;  
	*second_pointer = temp;  
} 
void Swap(void* first_pointer, void* second_pointer, int width) { 
	for (int byte_number = 0; byte_number < width;++byte_number) { 
		SwapChar((char*)first_pointer + byte_number, 
			(char*)second_pointer + byte_number); 
	}
}

int FindMinimumIndex(void* data_array, int width, 
		CompareFunctionType compare_function_pointer, 
		int first_index, int last_index) {
	char* bytevise_array = (char*)data_array;   
	int minimum_index = first_index;   
	int minimum_byte_number = minimum_index * width;   
	int current_byte_number = 0;
	for (int element_number = first_index; element_number <= last_index; ++element_number) { 
		current_byte_number = element_number * width;     
		if ((*compare_function_pointer)(&bytevise_array[current_byte_number], &bytevise_array[minimum_byte_number]) < 0) { 
			minimum_byte_number = current_byte_number; 
		} 
	}   
	minimum_index = minimum_byte_number / width;   
	return minimum_index;
}
template<class SORT>
void SelectionSort(SORT* data_array, int len, int sort_type) 
{
	switch (sort_type) {
	case 1: {SortMinToMax(len, data_array); break; }
	case 2: SortMaxToMin(len, data_array);
	};
}

template<class MINTOMAX>
void SortMinToMax(int width, MINTOMAX* data_array) {
	MINTOMAX temp;
	for (int i = 0; i < width; i++) {
		MINTOMAX min = data_array[i];
		int min_index = i;
		for (int j = i; j < width; j++) {
			if (min > data_array[j]) { min = data_array[j]; min_index = j; }
		}
		temp = data_array[min_index];
		data_array[min_index] = data_array[i];
		data_array[i] = temp;
	}
}

template <class MAXTOMIN>
void SortMaxToMin(int width, MAXTOMIN* data_array) {
	MAXTOMIN temp;
	for (int i = 0; i < width; i++) {
		MAXTOMIN max = data_array[i];
		int max_index = i;
		for (int j = i; j < width; j++) {
			if (max < data_array[j]) { max = data_array[j]; max_index = j; }
		}
		temp = data_array[max_index];
		data_array[max_index] = data_array[i];
		data_array[i] = temp;
	}
}

/*
template<class COMP>
int Compare(void* first_pointer, void* second_pointer) {
	COMP* first_element_pointer = (COMP*)first_pointer;
	COMP* second_element_pointer = (COMP*)second_pointer;
	return *first_element_pointer - *second_element_pointer;
}
*/

template<class IN>
void Input(int width, IN array) {
	for (int i = 0; i < width; i++) std::cin >> array[i];
}
template<class OUT>
void Output(int width, OUT array) {
	for (int i = 0; i < width; i++) std::cout << array[i] << " ";
	printf("\n");
}
