#include <iostream>
#include <stack>
#include <string>

bool isPalindrome(const std::string& s)
{
	std::stack<char> stack;

	for (int i = 0; i < s.size(); i++)
		stack.push(s[i]);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != stack.top())
			return false;

		stack.pop();
	}
	return true;
}

bool isPalind(const std::string& s)
{
	int l = 0, r = s.size() - 1;

	while (l <= r)
	{
		if (s[l] != s[r])
			return false;

		l++;
		r--;
	}
	return true;
}