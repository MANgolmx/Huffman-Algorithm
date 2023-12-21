#include <iostream>
#include <map>
#include "Node.h"

#pragma once
class Tree
{
private:
	void _PrintNode(Node* currentNode, int depth = 0);

	Node* _SearchNode(Node* currentNode, std::string key);

	void _PrintPathToEndNode(Node* currentNode, std::vector<int>& path);
	void _SavePathToEndNodes(FILE* file, Node* currentNode, std::vector<int>& path);

	int _CalculateEndNodeCount(Node* currentNode);

	std::map<char, std::string> _BuildMap(Node* currentNode, const std::string& currentPath);

public:
	Node* tree;

	Tree()
	{
		tree = new Node();
	}

	void PrintTree();

	Node* FindNode(std::string key);

	void PrintPathToEndNodes();
	void SavePathToEndNodes();

	void PrintEndNodeCount();

	std::map<char, std::string> BuildMap();

	~Tree()
	{
		;
	}
};