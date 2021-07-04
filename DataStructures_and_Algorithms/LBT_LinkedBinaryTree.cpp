#include "LBT_LinkedBinaryTree.h"


LinkedBinaryTree::LinkedBinaryTree()
: root(NULL), n(0)
{
}

int LinkedBinaryTree::Size() const 
{
	return n;
}
bool LinkedBinaryTree::IsEmpty() const
{
	return Size() == 0;
}

LinkedBinaryTree::Position LinkedBinaryTree::Root() const
{
	return Position(root);
}

/// <summary>
/// transforms p from an internal node (parent node) into an internal node (child node)
/// by creating 2 new external nodes and making them left and right children of p
/// </summary>
void LinkedBinaryTree::ExpandExternal(const Position& p)
{
	Node* newNode = p.node;				// p's new Node
	newNode->left = new Node;			// add new left child
	newNode->left->parent = newNode;	//newNode is its parent
	
	newNode->right = new Node;			// add also new right child
	newNode->right->parent = newNode;	//newNode is its parent
	n += 2;								//increase count
}

/// <summary>
/// w is p's associated node
/// and v is the parent of w
/// we assume that w is external and not a root node
/// 1. Case is w the child of the root, than remove w and its parent(the root)
/// that is how w's sibling become the new root
/// 2.case if not replace w's parent with its sibling
/// for this we find w's grandParent und check if v is grandParent left or right chuild
/// depending which set link for child of grandParent
/// after unlink w and v we delete thhese nodes
/// </summary>
LinkedBinaryTree::Position LinkedBinaryTree::RemoveAboveExternal(const Position& p)
{
	// get p's node and parent
	Node* w = p.node;
	Node* v = w->parent;

	Node* sibling = (w == v->left ? v->right : v->left);
	
	// child of root ? than make sibling root
	if (v == root)
	{
		root = sibling;
	}
	else
	{
		//w's grandParent
		Node* grandParent = v->parent;
		if (v == grandParent->left)			// replace parent by sibling
		{
			grandParent->left = sibling;
		}
		else
		{
			grandParent->right = sibling;
		}

		sibling->parent = grandParent;

	}
	delete w;
	delete v;
	n -= 2;
	return Position(sibling);


}

//traverse a tree and store node positions 
LinkedBinaryTree::PositionList LinkedBinaryTree::Positions() const
{
	PositionList pl;
	PreOrder(root, pl);						//preorder traversal
	return PositionList(pl);				//return resulting list

}

void LinkedBinaryTree::PreOrder(Node* node, PositionList& pl) const 
{
	pl.push_back(Position(node));
	if (node->left != NULL)						//traverse left subtree
	{
		PreOrder(node->left, pl);
	}
	if (node->right != NULL)					//traverse right subtree
	{
		PreOrder(node->right, pl);
	}
};

void LinkedBinaryTree::AddRoot() 
{
	root = new Node;
	n = 1; 
}



