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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n, p;
	int bars[20];
	bool found;

	cin >> tests;
	while (tests--)
	{
		cin >> n >> p;
		for (int i = 0; i < p; ++i)
			cin >> bars[i];

		found = false;
		for (int i = 0; i < 1 << p; ++i)
		{
			int sum = 0;
			for (int j = 0; j < p; ++j)
				if (i & (1 << j))
					sum += bars[j];
			if (sum == n)
			{
				found = true;
				break;
			}		
		}

		if (found)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}