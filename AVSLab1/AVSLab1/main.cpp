#include <iostream>

//	F[i] = A[i] + ( B[i] * C[i] ) + D[i] , i=1...8;

int main() 
{
	__int8 A[8] = { 4, 4, 4, 4, 1, 1, 1, 1};
	__int8 B[8] = { 2, 2, 2, 2, 3, 3, 3, 3};
	__int8 C[8] = { 8, 8, 8, 8, 7, 7, 7, 7};
	__int16 D[8] = { 5, 5, 5, 5, 9, 9, 9, 9};
	__int16 F[8] = {};

	__int64 bank = 0;

	short a;

	std::cout << "Enter array A:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cin >> a;
		A[i] = a;
	}
	std::cout << "\nEnter array B:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cin >> a;
		B[i] = a;
	}
	std::cout << "\nEnter array C:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cin >> a;
		C[i] = a;
	}
	std::cout << "\nEnter array D:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cin >> D[i];
	}
    __asm {
		pxor mm7, mm7

		movq mm0, B
		movq mm1, B

		movq mm2, C
		movq mm3, C

		; //B[i] * C[i]
		punpcklbw mm1, mm7
		punpcklbw mm3, mm7

		pmullw mm1, mm3

		movq bank, mm0
		movq mm3, bank

		punpckhbw mm3, mm7

		movq bank, mm2
		movq mm4, bank

		punpckhbw mm4, mm7

		pmullw mm3, mm4

		packuswb mm1, mm3

		; //A[i] + res

		movq mm0, A

		paddb mm0, mm1

		; //res + D[i]

		movq mm1, D
		movq mm2, D + 8

		movq bank, mm0
		movq mm3, bank
		movq mm4, bank

		punpcklbw mm3, mm7
		punpckhbw mm4, mm7

		paddw mm1, mm3
		;paddw mm1, mm4
		;paddw mm2, mm3
		paddw mm2, mm4



		; //mov to F
		movq F, mm1
		movq F + 8, mm2
		emms
	}
	/*std::cout << "Array A:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << (int)A[i] << " ";
	}
	std::cout << "\nArray B:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << (int)B[i] << " ";
	}
	std::cout << "\nArray C:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << (int)C[i] << " ";
	}
	std::cout << "\nArray D:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << (int)D[i] << " ";
	}*/
	std::cout << "\n\nAnswer, array F:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << F[i] << " ";
	}
	return 0;
}