#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <conio.h>
#include "Tree.h"
#include "Node.h" 
#include "Vector.h"

using namespace std;

pair<string, float> _firstMin, _secondMin;

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

string ReadFile(string fileName)
{
	FILE* textFile;
	if (fopen_s(&textFile, fileName.c_str(), "rt") != 0)
	{
		perror("File was not open");
		return "";
	}
	
	string text;
	char buffer[256];

	while (fgets(buffer, sizeof(buffer), textFile) != nullptr) {
		for (size_t i = 0; buffer[i] != '\0'; ++i) {
			if (buffer[i] != '\n' && !std::isspace(static_cast<unsigned char>(buffer[i]))) {
				text += buffer[i];
			}
		}
	}

	fclose(textFile);
	return text;
}

void CodeFile(string fileName, string text, map<char, string> table)
{
	string encodedText = "";
	for (char c : text) {
		encodedText += table.at(c);
	}
	
	FILE* textFile;
	if (fopen_s(&textFile, fileName.c_str(), "ab") != 0)
	{
		perror("File was not open");
		return;
	}

	fprintf(textFile, " %s", encodedText.c_str());

	fclose(textFile);
}

void DecodeFile(string fileName, string outputFile)
{
	string text;



}

int main()
{
	Vector frequencies;

	list<Vector> freqList;

	string text;

	int choice = 0, input;
	bool inMenu = true;

	//Menu
	while (inMenu)
	{
		system("cls");
		if (choice == 0)
			printf("---> ");
		printf("Load file\n");
		if (choice == 1)
			printf("---> ");
		printf("Input text\n");
		input = _getch();

		if (input == 224) //Arrows
		{
			input = _getch();
			switch (input) {
			case 72: //UP
				if (choice > 0)
					choice--;
				break;
			case 80: //DOWN
				if (choice < 1)
					choice++;
				break;
			}
		}
		else if (input == 13) //ENTER
		{
			system("cls");
			switch (choice)
			{
			case 0:
				cout << "Input your file name: ";
				getline(cin, text);
				text = ReadFile(text);
				break;
			case 1:
				cout << "Input your text: ";
				getline(cin, text);
				break;
			}
			inMenu = false;
		}
	}


	//Count characters
	map<char, int> chacterCount;

	for (char ch : text) {
		chacterCount[ch]++;
	}

	//Calculate char probabilities
	int textSize = text.size();

	for (const auto& entry : chacterCount) {
		float probability = (float)entry.second / textSize * 100;
		frequencies.AddPair(string(1, entry.first), probability);
	}

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
	//for (auto& freq : freqList) {
	//	freq.PrintVector();
	//}

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

		frequencies = freqList.back();
		freqList.pop_back();
	}

	//Print Huffman tree and Node paths
	//huffmanTree.PrintTree();

	cout << endl;
	huffmanTree.PrintEndNodeCount();
	huffmanTree.PrintPathToEndNodes();

	huffmanTree.SavePathToEndNodes();

	CodeFile("code.hca", text, huffmanTree.BuildMap());

	return 0;
}