#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;

bool used_each_digit(int n1, int n2)
{
	int digits = n1 <= 9999 || n2 <= 9999 ? 1 : 0;
	while (n1)
	{
		digits |= 1 << (n1 % 10);
		n1 /= 10;
	}
	while (n2)
	{
		digits |= 1 << (n2 % 10);
		n2 /= 10;
	}
	return digits == (1 << 10) - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n;
	bool first = true;

	while (cin >> n && n)
	{
		if (first) first = false;
		else putchar('\n');

		bool flag = false;
		for (int i = 1234; i <= 98765 / n; ++i)
		{
			int p = n * i;
			if (used_each_digit(i, p))
			{
				flag = true;
				printf("%05d / %05d = %d\n", p, i, n);
			}
		}
		if (!flag)
			printf("There are no solutions for %d.\n", n);
	}
}