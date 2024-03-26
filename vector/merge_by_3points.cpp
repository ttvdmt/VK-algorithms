#include <vector>
#include <iostream>
#include "print.hpp"

std::vector<int> merge_sorted_vector(std::vector<int> v1, std::vector<int> v2)
{
	int pointer1 = v1.size() - v2.size() - 1;
	int pointer2 = v2.size() - 1;
	int pointer3 = v1.size() - 1;

	while (pointer2 >= 0)
	{
		if (pointer1 >= 0 && v1[pointer1] > v2[pointer2]) {
			v1[pointer3] = v1[pointer1];
			pointer1--;
		}
		else {
			v1[pointer3] = v2[pointer2];
			pointer2--;
		}
		pointer3--;
	}
	return v1;
}