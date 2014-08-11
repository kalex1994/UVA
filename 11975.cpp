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

int n, l;
int drawn[75];
int ticket[5][5];
int v[4];

bool corners()
{
	int *begin = drawn;
	int *end = drawn + 35;
	if (find(begin, end, ticket[0][0]) != end && find(begin, end, ticket[0][4]) != end &&
		find(begin, end, ticket[4][0]) != end && find(begin, end, ticket[4][4]) != end)
		return true;
	return false;
}

bool midlane()
{
	int *begin = drawn;
	int *end = drawn + 40;
	for (int col = 0; col < 5; ++col)
		if (find(begin, end, ticket[2][col]) == end)
			return false;
	return true;
}

bool diagonals()
{
	int *begin = drawn;
	int *end = drawn + 45;
	for (int row = 0, col = 0; row < 5 && col < 5; ++row, ++col)
	{
		if (find(begin, end, ticket[row][col]) == end)
			return false;
		if (find(begin, end, ticket[row][4 - col]) == end)
			return false;
	}
	return true;
}

bool table()
{
	int *begin = drawn;
	int *end = drawn + n;
	for (int row = 0; row < 5; ++row)
		for (int col = 0; col < 5; ++col)
			if (find(begin, end, ticket[row][col]) == end)
				return false;
	return true;
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
		if (test > 1) cout << endl;
		printf("Case %d:\n", test);

		cin >> n >> l;

		for (int i = 0; i < 75; ++i)
			drawn[i] = -1;
		for (int i = 0; i < n; ++i)
			cin >> drawn[i];
		for (int i = 0; i < 4; ++i)
			cin >> v[i];
		for (int i = 0; i < l; ++i)
		{
			for (int row = 0; row < 5; ++row)
				for (int col = 0; col < 5; ++col)
					cin >> ticket[row][col];

			int money = 0;
			if (corners()) money += v[0];
			if (midlane()) money += v[1];
			if (diagonals()) money += v[2];
			if (table()) money += v[3];
			cout << money << endl;
		}
	}
}