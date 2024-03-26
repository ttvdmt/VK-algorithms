#include <iostream>

int bs_sqrt(int elem)
{
	int l = 0, r = elem;
	int mid = 0;

	while (l <= r)
	{
		mid = (l + r) / 2;
		if (mid * mid > elem) {
			r = mid - 1;
			continue;
		}
		if (mid * mid < elem) {
			l = mid + 1;
			continue;
		}
		return mid;
	}
	return r;
}
