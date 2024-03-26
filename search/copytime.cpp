#include <iostream>

int copytime(int n, int x, int y)
{
	int l = 0, r = (n - 1) * (x > y ? x : y);
	int mid = 0;

	while (l + 1 < r)
	{
		mid = (l + r) / 2;
		if (mid / x + mid / y < n - 1)
			l = mid;
		else
			r = mid;
	}
	return r + (x < y ? x : y);
}
