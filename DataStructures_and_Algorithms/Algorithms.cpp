#include "Algorithms.h"

Algorithms::Algorithms()
{
}
void Algorithms::InsertionSort(char* letter, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		char current = letter[i];
		
		//start with previous char
		int j = i - 1;

		while ((j >= 0) && (letter[j] > current))
		{
			letter[j + 1] = letter[j];
			j--;
		}

		// place for sorted char
		letter[j + 1] = current;
	}
}
//fast read only vector iterator
int Algorithms::VectorSum(const std::vector<int>& vec)
{
	std::vector<int>::const_iterator constIt;
	int sum = 0;
	for (constIt = vec.begin(); constIt != vec.end(); constIt++)
	{
		sum += *constIt;
	}
	return sum;
}

Algorithms::~Algorithms()
{
}
