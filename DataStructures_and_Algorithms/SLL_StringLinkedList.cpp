#include "SLL_StringLinkedList.h"

StringLinkedList::StringLinkedList()
: head(NULL)
{
}
bool StringLinkedList::IsEmpty() const
{
	return head == NULL;
}
const std::string& StringLinkedList::GetFirst() const
{
	return head->elem;
}
void StringLinkedList::AddElemAtFirst(const std::string& e) 
{
	// create new node
	StringNode* newNode = new StringNode;
	
	// store data
	newNode->elem = e;
	
	// head now follows newNode
	newNode->next = head;
	
	// newNode is now the head
	head = newNode;
}
void StringLinkedList::RemoveFirst()
{	
	// save current head
	StringNode* old = head; 

	// skip over old head
	head = old->next; 

	// delete the old head
	delete old; 
}
StringLinkedList::~StringLinkedList()
{
	while (!IsEmpty())
	{
		RemoveFirst();
	}
}

