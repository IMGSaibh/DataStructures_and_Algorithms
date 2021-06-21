#pragma once
#include <iostream>


/*	
	CLL has no end or start. Only next pointer.
	First element is referenced by cursor, Cursor is the special node
	cursor allows traversing the CLL. Back is follwed by Front

	(front)			(back/cursor)(front)
	elem_1 -> elem_2 -> elem_3 -> elem_1

	could be used for digital audioplayer
*/

typedef std::string CElem;
class CNode
{
	CElem elem;
	CNode* next;

	friend class CLinkedList;
};

class CLinkedList
{
	public:
		CLinkedList();
		~CLinkedList();
		bool IsEmpty();
		const CElem& Front() const;
		const CElem& Back() const;
		void Advance();
		void Add(const CElem& e);
		void Remove();
	private:
		CNode* cursor;

};

