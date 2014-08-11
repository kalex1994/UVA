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

typedef long long ll;

bool is_square[50000 + 1];

void init()
{
	fill(is_square, is_square + 50000 + 1, false);
	for (int i = 0; i < 224; ++i)
		is_square[i * i] = true;
}

bool is_sum_of_2_square(int k, int &s1, int &s2)
{
	for (int i = 0; i <= (int)sqrt(k); ++i)
	if (is_square[k - i * i])
	{
		s1 = i;
		s2 = (int)sqrt(k - i * i);
		return true;
	}
	return false;
}

bool is_sum_of_3_square(int k, int &s1, int &s2, int &s3)
{
	for (int i = 0; i <= (int)sqrt(k); ++i)
	{
		if (is_sum_of_2_square(k - i * i, s2, s3))
		{
			s1 = i;
			return true;
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int s1, s2, s3, tests, k;

	init();

	cin >> tests;
	while (tests--)
	{
		cin >> k;
		if (is_sum_of_3_square(k, s1, s2, s3))
			cout << s1 << " " << s2 << " " << s3 << endl;
		else
			cout << -1 << endl;
	}
}