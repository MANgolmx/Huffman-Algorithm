#include <iostream>

#pragma once
class Node
{
private:
	int frequency;
	std::string value;
	Node* parent;
	Node* childLeft;
	Node* childRight;

public:
	Node() 
	{
		frequency = 100;
		value = " ";
		parent = nullptr;
	}
	Node(int freq, std::string val, Node* par)
	{
		frequency = freq;
		value = val;
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