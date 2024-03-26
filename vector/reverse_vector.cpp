#include <iostream>
#include <vector>
#include "print.hpp"

void reverse(std::vector<int>& v)
{
	int left = 0;
	int right = v.size() - 1;

	while (left < right)
	{
		std::swap(v[left], v[right]);
		left++;
		right--;
	}
}

void reverse(std::vector<int>& v, int left, int right)
{
	if (left >= v.size() || right >= v.size() || left < 0 || right < 0)
		return;

	while (left < right)
	{
		std::swap(v[left], v[right]);
		left++;
		right--;
	}
}

void swap_ranges(std::vector<int>& v, int k)
{	
	if (k >= v.size() || k < 0)
		return;
	
	int n = v.size();

	reverse(v, 0, n - 1);
	reverse(v, 0, k % n - 1);
	reverse(v, k % n, n - 1);
}