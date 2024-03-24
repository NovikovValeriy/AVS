#include <iostream>

int main() {
	__int8 A[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	__int8 B[8] = { 3, 3, 5, 7, 2, 1, 8, 5 };
	__int8 C[8] = { 2, 2, 1, 1, 3, 2, 1, 2 };
	__int16 D[8] = { 3, 2, 1, 2, 3, 4, 5, 1 };
	__int16 F[8] = {};

	short a;
	/*std::cout << "Enter array A:\n";
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
	}*/

	// F[i] = A[i] + ( B[i] * C[i] ) + D[i] , i=1...8;
	__asm {
		xorps xmm0, xmm0
		xorps xmm1, xmm1
		xorps xmm2, xmm2
		xorps xmm3, xmm3
		xorps xmm4, xmm4
		xorps xmm5, xmm5
		xorps xmm6, xmm6

		movups xmm0, A
		punpcklbw xmm0, xmm7

		movups xmm1, B
		punpcklbw xmm1, xmm7

		movups xmm2, C
		punpcklbw xmm2, xmm7

		movups xmm3, D

		pmullw xmm1, xmm2

		addps xmm0, xmm1
		addps xmm0, xmm3

		movups F, xmm0
	}
	std::cout << "Array A:\n";
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
	}
	std::cout << "\n\nAnswer, array F:\n";
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << F[i] << " ";
	}
	std::cout << "\n\n";
	return 0;
	return 0;
}