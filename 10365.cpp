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

int minimum_surface(int n)
{
	int min_surface = INT_MAX;
	for (int length = 1; length <= (int)sqrt(n); ++length)
	if (n % length == 0)
	{
		int k = n / length;
		for (int width = 1; width <= (int)sqrt(k); ++width)
		if (k % width == 0)
		{
			int height = k / width;
			int surface = 2 * width * height + 2 * width * length + 2 * length * height;
			min_surface = min(min_surface, surface);
		}
	}
	return min_surface;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n;

	cin >> tests;
	while (tests--)
	{
		cin >> n;
		cout << minimum_surface(n) << endl;
	}
}