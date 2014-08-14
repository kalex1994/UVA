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

typedef unsigned long long ull;

vector<ull> numbers[18];

void make_numbers(int digits)
{
	for (int i = 0; i < (1 << digits); ++i)
	{
		ull n = 0;
		for (int j = digits - 1; j >= 0; --j)
			n = n * 10 + ((i & (1 << j)) ? 2 : 1);			
		numbers[digits].push_back(n);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	for (int i = 1; i <= 17; ++i)
		make_numbers(i);

	int tests, p, q;

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cin >> p >> q;

		ull k = 1 << q;
		ull a = 0, b = 0;

		for (size_t i = 0; i < numbers[p].size(); ++i)
			if (numbers[p][i] % k == 0)
			{
				if (a == 0) 
					a = numbers[p][i];
				b = numbers[p][i];
			}

		if (a == 0)
			printf("Case %d: impossible\n", test);
		else if (a == b)
			printf("Case %d: %llu\n", test, a);
		else
			printf("Case %d: %llu %llu\n", test, a, b);
	}
}