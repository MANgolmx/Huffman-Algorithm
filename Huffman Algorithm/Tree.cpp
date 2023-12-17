#include <vector>
#include "Tree.h"

void Tree::_PrintNode(Node* currentNode, int depth)
{
	if (currentNode == nullptr)
		return;

	_PrintNode(currentNode->GetRightChild(), depth + 1);
		
	for (int i = 0; i < depth; ++i)
		std::cout << "   ";

	std::cout << currentNode->GetValue() << ":" << currentNode->GetFrequency() << std::endl;

	_PrintNode(currentNode->GetLeftChild(), depth + 1);
}

Node* Tree::_SearchNode(Node* currentNode, std::string key)
{
	if (currentNode == nullptr || currentNode->GetValue() == key)
		return currentNode;

	Node* leftResult = _SearchNode(currentNode->GetLeftChild(), key);
	if (leftResult != nullptr)
		return leftResult;

	return _SearchNode(currentNode->GetRightChild(), key);
}

void Tree::_PrintPathToEndNode(Node* currentNode, std::vector<int>& path)
{
    if (currentNode != nullptr)
    {
        path.push_back(0);
        _PrintPathToEndNode(currentNode->GetLeftChild(), path);
        path.pop_back();

        path.push_back(1);
        _PrintPathToEndNode(currentNode->GetRightChild(), path);
        path.pop_back();

        if (currentNode->GetLeftChild() == nullptr && currentNode->GetRightChild() == nullptr)
        {
            std::cout << "Node with value " << currentNode->GetValue() << " - Path: ";
            for (int i : path) {
                std::cout << i;
            }
            std::cout << std::endl;
        }
    }
}

void Tree::_SavePathToEndNodes(FILE* file, Node* currentNode, std::vector<int>& path)
{
    if (currentNode != nullptr)
    {
        path.push_back(0);
        _SavePathToEndNodes(file, currentNode->GetLeftChild(), path);
        path.pop_back();

        path.push_back(1);
        _SavePathToEndNodes(file, currentNode->GetRightChild(), path);
        path.pop_back();

        if (currentNode->GetLeftChild() == nullptr && currentNode->GetRightChild() == nullptr)
        {
            fprintf(file, "%s ", currentNode->GetValue().c_str());
            for (int i : path) {
                fprintf(file, "%i", i);
            }
            fprintf(file, " ");
        }
    }
}

int Tree::_CalculateEndNodeCount(Node* currentNode)
{
    if (currentNode == nullptr)
        return 0;

    if (currentNode->GetLeftChild() == nullptr && currentNode->GetRightChild() == nullptr)
        return 1;

    return _CalculateEndNodeCount(currentNode->GetLeftChild()) + _CalculateEndNodeCount(currentNode->GetRightChild());
}

void Tree::PrintTree()
{
	_PrintNode(tree);
}

Node* Tree::FindNode(std::string key)
{
	return _SearchNode(tree, key);
}

void Tree::PrintPathToEndNodes()
{
	std::vector<int> path;
	_PrintPathToEndNode(tree, path);
}

void Tree::SavePathToEndNodes()
{
	std::vector<int> path;
	
    FILE* file;
    
	if (fopen_s(&file, "code.txt", "wt") != 0)
	{
		perror("Error opening file");
		return;
	}

    fprintf(file, "%i ", _CalculateEndNodeCount(tree));
	_SavePathToEndNodes(file, tree, path);
	fclose(file);
}

void Tree::PrintEndNodeCount()
{
    std::cout << _CalculateEndNodeCount(tree) << std::endl;
}
