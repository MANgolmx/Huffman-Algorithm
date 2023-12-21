#include <iostream>

#pragma once
class Node
{
private:
	std::pair<std::string, float> pair;
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
	Node(float freq, std::string val, Node* par)
	{
		pair.first = val;
		pair.second = freq;
		parent = par;
	}
	Node(std::pair<std::string, float> npair, Node* par)
	{
		pair = npair;
		parent = par;
	}

	float GetFrequency();
	std::string GetValue();
	char GetLeafNodeValue();
	Node* GetParent();

	void SetFrequency(float freq);
	void SetValue(std::string val);
	void SetParent(Node* par);

	void AddLeftChild(std::string value, float freq);
	void AddRightChild(std::string value, float freq);

	void AddLeftChild(std::pair<std::string, float> lpair);
	void AddRightChild(std::pair<std::string, float> rpair);

	void AddLeftChild(Node* leftChild);
	void AddRightChild(Node* rightChild);

	void ChangeParent(std::string value, float freq);

	Node* GetLeftChild();
	Node* GetRightChild();

	~Node()
	{
		;
	}
};