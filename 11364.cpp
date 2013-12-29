#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;

typedef unsigned long ul;

int main()
{
	int tests;

	cin >> tests;
	while (tests--)
	{
		int n, min_value = 999, max_value = -999;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			min_value = min(k, min_value);
			max_value = max(k, max_value);
		}
		cout << (max_value - min_value) * 2 << endl;
	}
	return 0;
}