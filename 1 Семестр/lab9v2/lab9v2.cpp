
#include <iostream>
#include <iomanip>
#include "math.h"

int main()
{
	float A, B, H;
	float fx1, fx2;
	printf("Enter A and B  (|A| < pi/2 and |B| < pi/2):   ");
	scanf_s("%f %f", &A, &B);
	printf("Enter H:   ");
	scanf_s("%f", &H);

	std::cout << std::setw(10) << std::left << "X"
		<< std::setw(20) << "Tan(x)"
		<< std::setw(20) << "F1(x)"
		<< std::setw(20) << "F2(x)"
		<< std::setw(25) << "Abs"
		<< std::setw(15) << "Rel"
		<< std::endl;


	float absol;

	for (; A <= B; A += H) {

		fx1 = A + (pow(A, 3) / 3) + 2 * pow(A, 5) / 15 + 17 * pow(A, 7) / 315 + 62 * pow(A, 9) / 2835;


		absol = tan(A) - fx1;
		std::cout << std::setw(10) << std::left << A
			<< std::setw(20) << tan(A)
			<< std::setw(20) << fx1
			<< std::setw(20) << A + (A * A * A / 3) + 2 * A * A * A * A * A / 15 + 17 * A * A * A * A * A * A * A / 315 + 62 * A * A * A * A * A * A * A * A * A / 2835
			<< std::setw(25) << absol
			<< std::setw(15) << abs(absol / tan(A) * 100) << " %"
			<< std::endl;
	}


}
