#include "CLL_CircularlyLinkedList.h"

CLinkedList::CLinkedList()
:cursor(NULL)
{
}

CLinkedList::~CLinkedList()
{
	while (!IsEmpty())
	{
		Remove();
	}
}

bool CLinkedList::IsEmpty()
{
	return cursor == NULL;
}

const CElem& CLinkedList::Front() const
{
	return cursor->elem;
}

const CElem& CLinkedList::Back() const
{
	return cursor->next->elem;
}

//advances the cursor to be the next element
void CLinkedList::Advance()
{
	cursor = cursor->next;
}

// insert a node
void CLinkedList::Add(const CElem& e)
{
	CNode* newCNode = new CNode;
	newCNode->elem = e;

	if (cursor == NULL)					//list empty ?
	{
		newCNode->next = newCNode;		//newCNode points to its self
		cursor = newCNode;				//Cursor points to newCNode

	}
	else
	{
		//list not empty than link newCNode to after cursor
		newCNode->next = cursor->next;
		cursor->next = newCNode;
	}
}

//check if node is not empty bevor invoke this function
//to cases here
// 1 case = if remove node is the last node. this can be checked when Node points to its self.
// in this case cursor points to NULL
// 2 case = link the cursor next pointer to skip the removed node
// we delete the node in this case
void CLinkedList::Remove()
{
	CNode* oldCNode = cursor->next;
	if (oldCNode == cursor)
	{
		cursor = NULL;
	}
	else
	{
		cursor->next = oldCNode->next;
	}
	delete oldCNode;
}
