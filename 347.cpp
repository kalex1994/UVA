#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <cstdio>

using namespace std;

int n;

inline bool hasUniqueDigits()
{
	register int temp = n, digits = 0;
	while (temp)
	{
		if (digits & (1 << (temp % 10))) return false;
		digits |= (1 << (temp % 10));
		temp /= 10;
	}
	return true;
}

bool isRunAround()
{
	if (!hasUniqueDigits()) return false;

	int digits = floor(log10(n)) + 1;
	int visited = 0;
	int pos = 0;

	while (true)
	{
		if (pos == 0 && (visited & 1)) break;
		if (visited & (1 << pos)) return false;
		visited |= 1 << pos;
		pos = (pos + (int)floor(n / pow(10, digits - pos - 1)) % 10) % digits;
	}
	if (visited == (1 << digits) - 1) return true;
	return false;
}

int main()
{
	for (int test = 1; scanf("%d", &n) && n; ++test)
	{
		do
			++n;
		while (!isRunAround());

		printf("Case %d: %d\n", test, n);
	}
}