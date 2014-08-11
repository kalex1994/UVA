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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n;
	int sales[1000];

	cin >> tests;
	while (tests--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> sales[i];

		int sum = 0;
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (sales[j] <= sales[i])
					++sum;

		cout << sum << endl;
	}
}