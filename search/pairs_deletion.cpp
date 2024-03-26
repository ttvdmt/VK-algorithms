#include <iostream>
#include <string>

std::string pairs_deletion(const std::string& s)
{
	std::string tmp{s[0]};
	int ptr = 0;

	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == tmp[ptr] && ptr >= 0) {
			tmp.pop_back();
			ptr--;
		}
		else {
			ptr++;
			tmp += s[i];
		}
	}
	return tmp;
}