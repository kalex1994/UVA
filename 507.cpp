#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

int stops[20000 + 5];
int n, tests;

pair<int, int> getMaxRange()
{
	int start = -1, end = -1, actStart = 0, sum = 0, maxSum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += stops[i];

		if (sum == maxSum)
		{
			if (start == -1)
			{
				start = actStart;
				end = i;
			}
			else if ((i - actStart) > (end - start))
			{
				start = actStart;
				end = i;
			}
		}
		if (sum > maxSum)
		{
			start = actStart;
			end = i;
			maxSum = sum;
		}
		if (sum < 0)
		{
			sum = 0;
			actStart = i + 1;
		}
	}
	if (maxSum == 0) return make_pair(-1, -1);
	return make_pair(start, end);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cin >> n;
		--n;
		for (int i = 0; i < n; ++i)
			cin >> stops[i];

		pair<int, int> ans = getMaxRange();

		if (ans.first < 0) printf("Route %d has no nice parts\n", test);
		else printf("The nicest part of route %d is between stops %d and %d\n", test, ans.first + 1, ans.second + 2);
	}
	return 0;
}