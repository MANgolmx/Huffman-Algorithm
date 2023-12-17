#include <iostream>

#pragma once
class Node
{
private:
	std::pair<std::string, int> pair;
	Node* parent;
	Node* childLeft;
	Node* childRight;

public:
	Node() 
	{
		pair.first = " ";
		pair.second = 100;
		parent = nullptr;
	}
	Node(int freq, std::string val, Node* par)
	{
		pair.first = val;
		pair.second = freq;
		parent = par;
	}
	Node(std::pair<std::string, int> npair, Node* par)
	{
		pair = npair;
		parent = par;
	}

	int GetFrequency();
	std::string GetValue();
	Node* GetParent();

	void SetFrequency(int freq);
	void SetValue(std::string val);
	void SetParent(Node* par);

	void AddLeftChild(std::string value, int freq);
	void AddRightChild(std::string value, int freq);

	void AddLeftChild(std::pair<std::string, int> lpair);
	void AddRightChild(std::pair<std::string, int> rpair);

	void AddLeftChild(Node* leftChild);
	void AddRightChild(Node* rightChild);

	void ChangeParent(std::string value, int freq);

	Node* GetLeftChild();
	Node* GetRightChild();

	~Node()
	{
		;
	}
};