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


/********************************************
	Generic Singly Linked List implementation
*********************************************/

template <class T>
class SLinkedList;

template <class T>
class SNode
{
	private:
		T elem;
		SNode<T>* next;
		friend class SLinkedList<T>;

};

template <class T>
class SLinkedList
{
	public:
		SLinkedList() 
		: head(NULL)
		{  
		};
		~SLinkedList() 
		{
			while (!IsEmptyT())
			{
				RemoveFirstT();
			}
		};
		bool IsEmptyT()  const
		{ 
			return head == NULL; 
		};
		const T& GetFirstT() const 
		{ 
			return head->elem; 
		};
		void AddElemAtFirstT(const T& e) 
		{
			SNode<T>* newNode = new SNode<T>();
			newNode->elem = e;
			newNode->next = head;
			head = newNode;
		};
		void RemoveFirstT() 
		{
			SNode<T>* old = head;
			head = old->next;
			delete old;
		};

	private:
		SNode<T>* head;
};

