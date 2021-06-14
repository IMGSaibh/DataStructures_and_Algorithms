#pragma once
#include <iostream>

// a singly link list, in its simplest form, is a collection of nodes
// eachh node stores a pointer to the next node
// if pointer to the next node is null, tail of the node was reached

class StringNode
{
private:
	std::string elem;
	StringNode* next;

	//proividing access for StringLinkedList
	friend class StringLinkedList;

};

class StringLinkedList
{
	public:
		StringLinkedList();
		~StringLinkedList();

		bool IsEmpty() const;
		
		// get front element
		const std::string& GetFirst() const;

		void AddElemAtFirst(const std::string& e);
		void RemoveFirst();

	private:
		// points to head of the list
		StringNode* head; 
};

