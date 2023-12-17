#include <iostream>
#include <algorithm>
#include "Vector.h"

void Vector::AddPair(std::string first, int second)
{
    std::pair<std::string, int> newPair = std::make_pair(first, second);
    vector.push_back(newPair);
}

void Vector::SortVector() {
    std::sort(vector.begin(), vector.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });
}

void Vector::CombinePairs(std::string firstKey, std::string secondKey)
{
    auto it1 = std::find_if(vector.begin(), vector.end(),
        [&](const auto& pair) { return pair.first == firstKey; });

    int sum = it1->second;
    vector.erase(it1);

    auto it2 = std::find_if(vector.begin(), vector.end(),
        [&](const auto& pair) { return pair.first == secondKey; });

    sum += it2->second;
    vector.erase(it2);

    this->AddPair(firstKey + secondKey, sum);
}

void Vector::PrintVector()
{
    for (const auto& pair : vector) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    std::cout << std::endl;
}
