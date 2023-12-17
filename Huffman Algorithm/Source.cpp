#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include "Tree.h"
#include "Node.h" 

using namespace std;

int firstFreq, secondFreq;
string firstFreqStr, secondFreqStr;

void FindMinElements(const map<string, int> frequencies)
{
	firstFreq = secondFreq = 101;
	for (const auto& i : frequencies) {
		if (i.second < firstFreq) {
			firstFreqStr = i.first;
			firstFreq = i.second;
		}
		if (i.second < secondFreq && i.second != firstFreq) {
			secondFreqStr = i.first;
			secondFreq = i.second;
		}
	}
}

void FindMaxElements(const map<string, int> frequencies)
{
	firstFreq = secondFreq = -1;
	for (const auto& i : frequencies) {
		if (i.second > firstFreq) {
			firstFreqStr = i.first;
			firstFreq = i.second;
		}
		if (i.second > secondFreq && i.second != firstFreq) {
			secondFreqStr = i.first;
			secondFreq = i.second;
		}
	}
}

void PrintMap(const map<string, int> frequencies)
{
	for (const auto& i : frequencies) {
		cout << i.first << " " << i.second << endl;
	}
}

void UpdateFrequencies(map<string, int>* frequencies)
{
	frequencies->erase(firstFreqStr);
	frequencies->erase(secondFreqStr);
	(*frequencies)[firstFreqStr + secondFreqStr] = firstFreq + secondFreq;
}

int main()
{
	vector<pair<string, int> > frequencies;

	frequencies = 5; 
	frequencies["b"] = 9; 
	frequencies["c"] = 12;
	frequencies["d"] = 13;
	frequencies["e"] = 16;
	frequencies["f"] = 45;
	
	//Tree huffmanTree = Tree();

	FindMinElements(frequencies);

	UpdateFrequencies(&frequencies);

	sortMap(frequencies);

	PrintMap(frequencies);

	//huffmanTree.PrintTree();

	return 0;
}