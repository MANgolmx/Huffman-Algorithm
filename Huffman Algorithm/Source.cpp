#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include "Tree.h"
#include "Node.h" 
#include "Vector.h"

using namespace std;

pair<string, int> _firstMin, _secondMin;

void FindMin(Vector& vec)
{
	_firstMin.second = _secondMin.second = 100;

	for (const auto& element : vec.vector) {
		if (element.second < _firstMin.second) {
			_secondMin = _firstMin;
			_firstMin = element;
		}
		else if (element.second < _secondMin.second && element.second != _firstMin.second) {
			_secondMin = element;
		}
	}
}

int main()
{
	Vector frequencies;

	list<Vector> freqList;

	//Input start frequencies
	frequencies.AddPair("a", 5);
	frequencies.AddPair("b", 9);
	frequencies.AddPair("c", 12);
	frequencies.AddPair("d", 13);
	frequencies.AddPair("e", 16);
	frequencies.AddPair("f", 45);
	

	//Generate all of the temperary frequencies for the Huffman tree
	freqList.push_back(frequencies);
	
	while (frequencies.vector.size() > 1) 
	{
		FindMin(frequencies);

		frequencies.CombinePairs(_firstMin.first, _secondMin.first);

		frequencies.SortVector();

		freqList.push_back(frequencies);
	}

	//Print all of the temperary frequencies
	for (auto& freq : freqList) {
		freq.PrintVector();
	}


	//Initialize Tree
	Tree huffmanTree = Tree();
	huffmanTree.tree->SetValue(freqList.back().vector.back().first);
	freqList.pop_back();

	//Generate Huffman Tree
	while (!freqList.empty())
	{
		FindMin(freqList.back());

		Node* parentNode = huffmanTree.FindNode(_firstMin.first + _secondMin.first);

		parentNode->AddLeftChild(_firstMin);
		parentNode->AddRightChild(_secondMin);

		freqList.pop_back();
	}

	//Print Huffman tree and Node paths
	huffmanTree.PrintTree();

	huffmanTree.PrintEndNodeCount();
	huffmanTree.PrintPathToEndNodes();

	huffmanTree.SavePathToEndNodes();

	return 0;
}