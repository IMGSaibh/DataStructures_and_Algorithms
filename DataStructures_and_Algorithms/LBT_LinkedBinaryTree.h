#pragma once
#include <list>

typedef int BT_Elem;
class LinkedBinaryTree
{
	protected:
		struct Node
		{
			BT_Elem elem;
			Node* parent;
			Node* left;
			Node* right;
			//constructer
			Node() : elem(), parent(nullptr), left(nullptr), right(nullptr) {}
		};
	public:
		//class Position represents a position in the tree
		class Position
		{
			private:
				Node* node;
			public:
				//constructor
				Position (Node* _node = nullptr) : node(_node) {}
				//overloading dereferencing operator to access nodes elem
				BT_Elem& operator*() { return node->elem; }
				Position Parent() const { return Position(node->parent); };
				Position Left() const { return Position(node->left); };
				Position Right() const { return Position(node->right); };
				bool IsRoot() const { return node->parent == nullptr; };
				bool IsExternal() const { return node->left == nullptr && node->right == nullptr; };

				friend class LinkedBinaryTree;

		};
		typedef std::list<Position> PositionList;

	public:
		LinkedBinaryTree();
		void AddRoot();
		int Size() const;
		bool IsEmpty() const;
		Position Root() const;
		PositionList Positions() const;
		void ExpandExternal(const Position& p);
		Position RemoveAboveExternal(const Position& p);
	
	protected:
		void PreOrder(Node* node, PositionList& pl) const;
	private:
		Node* root;
		//number of nodes in tree
		int n;

};








