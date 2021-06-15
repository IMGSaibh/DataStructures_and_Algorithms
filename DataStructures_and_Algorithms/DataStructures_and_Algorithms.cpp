#include "Algorithms.h"
#include "SLL_StringLinkedList.h"
#include "DLL_DoublyLinkedList.h"

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

	//Singly Linked List
	SLinkedList<string> sllist;
	sllist.AddElemAtFirstT("First");
	sllist.AddElemAtFirstT("Second");

	string first = sllist.GetFirstT();
	cout << first << endl;

	sllist.RemoveFirstT();
	first = sllist.GetFirstT();
	cout << first << endl;
	cout << "Singly Linked List end" << endl;


	//Doubly Linked List
	DLinkedList dllList;
	dllList.AddElemAtFirst("D_First");
	dllList.AddElemAtFirst("D_Second");
	dllList.AddElemAtFirst("D_Third");
	first = dllList.GetFirst();
	cout << first << endl;

	return 0;
}
