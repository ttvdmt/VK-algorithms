#include <vector>
#include <iostream>
#include "print.hpp"

std::vector<int> merge_sorted_vector(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<int> tmp;
	int i = 0;
	int j = 0;

	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] < v2[j]) {
			tmp.push_back(v1[i]);
			i++;
		}
		else {
			tmp.push_back(v2[j]);
			j++;
		}
	}

	for (i; i < v1.size(); i++)
		tmp.push_back(v1[i]);
	for (j; j < v2.size(); j++)
		tmp.push_back(v2[j]);

	return tmp;
}