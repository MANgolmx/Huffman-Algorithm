#include <iostream>
#include "Node.h"

#pragma once
class Tree
{
private:
	Node* tree;

	void PrintNode(Node* currentNode, int depth = 0);

public:

	Tree()
	{
		tree = new Node();
	}

	Node* GetTree();

	void PrintTree();

	~Tree()
	{
		;
	}
};