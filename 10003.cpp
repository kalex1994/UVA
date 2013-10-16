#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SIZE 55

int memo[MAX_SIZE][MAX_SIZE];
int cuts[MAX_SIZE];
int l, n;

int solve(int start, int end)
{
	if (memo[start][end] != -1) return memo[start][end];
	if (start + 1 == end) return memo[start][end] = 0;

	int minCut = INT_MAX;
	for (int i = start + 1; i < end; ++i)
		minCut = min(minCut, solve(start, i) + solve(i, end) + cuts[end] - cuts[start]);
	return memo[start][end] = minCut;
}

int main()
{
	while (cin >> l && l)
	{
		cin >> n;

		cuts[0] = 0;
		cuts[n + 1] = l;
		for (int i = 1; i <= n; ++i)
			cin >> cuts[i];

		memset(memo, -1, sizeof(memo));
		printf("The minimum cutting is %d.\n", solve(0, n + 1));
	}
}