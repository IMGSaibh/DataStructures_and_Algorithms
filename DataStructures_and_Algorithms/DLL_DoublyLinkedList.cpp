#include "DLL_DoublyLinkedList.h"


DLinkedList::DLinkedList()
:header(new DNode),
trailer(new DNode)
{
	header->next = trailer;
	trailer->prev = header;
}

DLinkedList::~DLinkedList()
{
	//remove all nodes
	while (!IsEmpty())
		RemoveFirst();

	//delete special nodes
	delete header;
	delete trailer;
}

bool DLinkedList::IsEmpty() const
{
	//check if no node is between header and trailer
	return header->next == trailer;
}

const Elem& DLinkedList::GetFirst()
{
	return trailer->next->elem;
}

const Elem& DLinkedList::GetLast()
{
	return trailer->prev->elem;
}

void DLinkedList::AddElemAtFirst(const Elem& e)
{
	Add(header->next, e);
}

void DLinkedList::AddElemAtLast(const Elem& e)
{
	Add(trailer->prev, e);
}

void DLinkedList::RemoveFirst()
{
	Remove(header->next);
}

void DLinkedList::RemoveLast()
{
	Remove(trailer->prev);
}


/// <summary>
/// insert node before a specific Node
/// </summary>
/// <param name="nodeAfter">Node that will be the next Node of inserted Node</param>
/// <param name="e"></param>
void DLinkedList::Add(DNode* nodeAfter, const Elem& e)
{
	DNode* newNode = new DNode;
	newNode->elem = e;

	// link newNode between nodeAfter and nodeAfter->prev
	newNode->next = nodeAfter;
	newNode->prev = nodeAfter->prev;

	//next of the node before the newNode links to newNode
	nodeAfter->prev->next = newNode;

	nodeAfter->prev = newNode;

}

void DLinkedList::Remove(DNode* node)
{
	DNode* prevNode = node->prev;
	DNode* nextNode = node->next;

	//unlink node from list
	prevNode->next = nextNode;
	nextNode->prev = prevNode;

	delete node;

}
