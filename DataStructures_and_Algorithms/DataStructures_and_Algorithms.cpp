#include "Algorithms.h"
#include "SLL_StringLinkedList.h"
#include "DLL_DoublyLinkedList.h"
#include "CLL_CircularlyLinkedList.h"

using namespace std;

int main(void)
{
	/*
		Insertion Sort
	*/
	char letters[5] { 'B', 'V', 'C', 'A', 'A', };
	Algorithms algo;
	algo.InsertionSort(letters, 5);

	//print
	for (size_t i = 0; i < 5; i++)
		std::cout << letters[i];

	std::cout << endl;

	/*
		Singly Linked List
	*/
	SLinkedList<string> sllist;
	sllist.AddElemAtFirstT("First");
	sllist.AddElemAtFirstT("Second");

	string first = sllist.GetFirstT();
	
	cout << first << endl;

	sllist.RemoveFirstT();
	first = sllist.GetFirstT();
	cout << first << endl;
	cout << "Singly Linked List end" << endl;
	std::cout << endl;


	/*
		Doubly Linked List
	*/
	DLinkedList dllList;
	dllList.AddElemAtFirst("D_First");
	dllList.AddElemAtFirst("D_Second");
	dllList.AddElemAtFirst("D_Third");
	dllList.AddElemAtLast("D_Fourth");
	string dll_first = dllList.GetFirst();
	string dll_last = dllList.GetLast();
	cout << "first elem " << dll_first << endl;
	cout << "last elem " << dll_last << endl;
	std::cout << endl;

	//reverse a list
	dllList.ListReverse(dllList);

	string firstReverse = dllList.GetFirst();
	string lastReverse = dllList.GetLast();
	cout << "first elem reverse " << firstReverse << endl;
	cout << "last elem reverse " << lastReverse << endl;
	cout << "Doubly Linked List end" << endl;
	std::cout << endl;




	/*
		Circularly Linked List
	*/

	cout << "Circularly Linked List start" << endl;
	CLinkedList playList;
	playList.Add("Would - Alice in Chains");
	playList.Add("How soon is now - The Smiths");
	playList.Add("Dont Stop me Now - Queens");

	playList.Advance();
	playList.Advance();
	playList.Add("Beat It - Micheal Jackson");

	// first elem in cllist
	string cll_Front = playList.Back();
	cout << cll_Front << endl;


	return 0;
}
