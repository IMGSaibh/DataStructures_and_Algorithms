#include "Algorithmen.h"

Algorithmen::Algorithmen()
{
}


void Algorithmen::InsertionSort(char* letter, int n)
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

Algorithmen::~Algorithmen()
{
}
