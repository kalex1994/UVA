#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	ull m[30];
	m[0] = 1;
	for(int i = 1; i < 30; ++i)
		m[i] = m[i - 1] << 2;

	int tests;
	string s;

	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		cin >> s;
		reverse(s.begin(), s.end());

		ull value = 0;
		for(size_t i = 0; i < s.length(); ++i)
		{
			int ind = 0;
			switch(s[i])
			{
			case 'A':
				break;
			case 'C':
				ind = 1;
				break;
			case 'G':
				ind = 2;
				break;
			case 'T':
				ind = 3;
				break;
			}
			value += ind * m[i];
		}

		printf("Case %d: (%d:%lu)\n", test, s.length(), value);
	}
}