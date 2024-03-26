#include <iostream>
#include <vector>
#include "print.hpp"

std::vector<int> zeroLast(std::vector<int>& v)
{
	int zero_it = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
			std::swap(v[i], v[zero_it]);

		if (v[zero_it] != 0)
			zero_it++;
	}
	return v;
}