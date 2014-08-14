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

char digits[40];
int n;

void encode(string abbreviation, int ST)
{
	stringstream ss;
	for (char ch : abbreviation)
		ss << ST + (int)(ch - 'A');

	n = 0;
	for (char ch : ss.str())
		digits[n++] = ch - '0';
}

int yuanfen()
{
	while (n > 2)
	{
		if (n == 3 && digits[0] == 1 && digits[1] == 0 && digits[2] == 0)
			break;
		for (int i = 0; i + 1 < n; ++i)
			digits[i] = (digits[i] + digits[i + 1]) % 10;
		--n;
	}
	
	if (n == 3) return 100;
	else return 10 * digits[0] + digits[1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	string abbreviation;

	while (cin >> abbreviation)
	{
		bool found = false;
		for (int ST = 0; ST <= 10000; ++ST)
		{
			encode(abbreviation, ST);
			if (yuanfen() == 100)
			{
				cout << ST << endl;
				found = true;
				break;
			}
		}
		if (!found)
			cout << ":(" << endl;
	}
}