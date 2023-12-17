#include "Tree.h"

void Tree::PrintNode(Node* currentNode, int depth)
{
	if (currentNode == nullptr)
		return;

	PrintNode(currentNode->GetRightChild(), depth + 1);
		
	for (int i = 0; i < depth; ++i)
		std::cout << "   ";

	std::cout << currentNode->GetValue() << ":" << currentNode->GetFrequency() << std::endl;

	PrintNode(currentNode->GetLeftChild(), depth + 1);
}

Node* Tree::GetTree()
{
	return tree;
}

void Tree::PrintTree()
{
	PrintNode(tree);
}
