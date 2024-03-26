#include <iostream>
#include <queue>
#include <stack>
#include <string>

bool isSubsequence(const std::string& a, const std::string& b)
{
	std::queue<char> q;
	for (int i = 0; i < a.size(); i++)
		q.push(a[i]);

	for (int i = 0; i < b.size(); i++)
	{
		if (q.front() == b[i])
			q.pop();
	}
	return q.size() == 0;
}

bool isSubseq(const std::string& a, const std::string& b)
{
	int ptr = 0;
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == a[ptr])
			ptr++;

		if (ptr == a.size() - 1)
			return true;
	}
	return false;
}