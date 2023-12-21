#include <iostream>
#include <vector>

#pragma once

class Vector
{

public:
	std::vector<std::pair<std::string, float>> vector;

	Vector() { ; }
	Vector(std::vector<std::pair<std::string, float>> vec) { vector = vec; }
	
	void AddPair(std::string first, float second);
	void SortVector();

	void CombinePairs(std::string firstKey, std::string secondKey);

	void PrintVector();

	~Vector() { ; }
};