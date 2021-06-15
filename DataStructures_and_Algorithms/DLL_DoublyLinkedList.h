#pragma once
#include"SLL_StringLinkedList.h"
/*
	insert a node at any position within a doubly linked list
	it is convenient to add special nodes at both ends of a doubly linked list

	[headerNode] before head
	[trailerNode] after tail

	those nodes have only next (header) or prev (trailer) pointer
	they provide quick access to the first and last Node of linked list

	<<< An empty list would have these sentinels pointing to each other >>>

	One of the major
	advantages of providing sentinel nodes is to avoid handling of special cases, which
	would otherwise be needed.
*/

//define a type for linked list
// i use string for now

typedef std::string Elem;
class DNode
{	
	private:
		Elem elem;
		DNode* prev;
		DNode* next;
		friend class DLinkedList;
};


class DLinkedList
{
	public:
		DLinkedList();
		~DLinkedList();
		bool IsEmpty() const;
		const Elem& GetFirst();
		const Elem& GetLast();
		void AddElemAtFirst(const Elem& e);
		void AddElemAtLast(const Elem& e);
		void RemoveFirst();
		void RemoveLast();
	private:
		DNode* header;
		DNode* trailer;
	protected:
		void Add(DNode* nodeAfter, const Elem& e);
		void Remove(DNode* node);
};


