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

	int tests;
	int number_of_days, days_remember;
	string names;

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cin >> number_of_days >> days_remember >> names;

		int recognized = 0;
		for (int i = 0; i < number_of_days; ++i)
			for (int j = 1; j <= days_remember && i - j >= 0; ++j)
			if (names[i] == names[i - j])
			{
				++recognized;
				break;
			}
		printf("Case %d: %d\n", test, recognized);
	}
}