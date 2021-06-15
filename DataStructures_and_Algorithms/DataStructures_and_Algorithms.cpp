#include "Algorithms.h"
#include "SLL_StringLinkedList.h"

using namespace std;

int main(void)
{
	char letters[5] { 'B', 'V', 'C', 'A', 'A', };
	Algorithms algo;
	algo.InsertionSort(letters, 5);

	//print
	for (size_t i = 0; i < 5; i++)
		std::cout << letters[i];

	std::cout << endl;

	SLinkedList<string> sllist;
	sllist.AddElemAtFirstT("First");
	sllist.AddElemAtFirstT("Second");

	string first = sllist.GetFirstT();
	cout << first << endl;

	sllist.RemoveFirstT();
	first = sllist.GetFirstT();
	cout << first << endl;

	return 0;
}
