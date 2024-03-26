#pragma once
#include <iostream>
#include <vector>

void print(const std::vector<int>& v)
{
	for (auto n : v)
	{
		std::cout << n << ' ';
	}
	std::cout << std::endl;
}