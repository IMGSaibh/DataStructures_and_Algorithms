#include <iostream>
#include<string>
#include "Algorithmen.h"

using namespace std;

int main(void)
{
	char letters[5] { 'B', 'V', 'C', 'A', 'A', };
	Algorithmen algo;
	algo.InsertionSort(letters, 5);

	//print
	for (size_t i = 0; i < 5; i++)
		std::cout << letters[i];



	return 0;
}
