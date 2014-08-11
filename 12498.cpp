#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

string maze[50];
int r, c;
const int INF = 9999999;

int solve()
{
	int answer = INF;

	for (int k = 0; k < c; ++k)
	{
		int sum = 0;
		for (int i = 0; i < r; ++i)
		{
			int dist = INF;
			for (int j = 0; j < c; ++j)
				if (maze[i][j] == '0')
					dist = min(dist, abs(j - k));
			if (dist == INF)
				return -1;
			sum += dist;
		}
		answer = min(answer, sum);
	}
	return answer;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cin >> r >> c;
		for (int i = 0; i < r; ++i)
			cin >> maze[i];
		printf("Case %d: %d\n", test, solve());
	}	
}