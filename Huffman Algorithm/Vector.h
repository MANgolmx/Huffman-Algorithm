#include <iostream>
#include <vector>

#pragma once

class Vector
{

public:
	std::vector<std::pair<std::string, int>> vector;

	Vector() { ; }
	
	void AddPair(std::string first, int second);
	void SortVector();

	void CombinePairs(std::string firstKey, std::string secondKey);

	void PrintVector();

	~Vector() { ; }
};