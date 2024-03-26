#include <vector>
#include <iostream>
#include "print.hpp"

std::vector<int> evenFirst(std::vector<int>& v)
{
	int even_it = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 == 0) {
			std::swap(v[i], v[even_it]);
			even_it++;
		}
	}
	return v;
}