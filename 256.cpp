#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <limits>
#include <set>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	char buff[10];
	map<int, int> m;
	m[2] = 10;
	m[4] = 100;
	m[6] = 1000;
	m[8] = 10000;

	int digits;
	while(cin >> digits)
	{
		for(int i = 0; i < 10000; ++i)
		{
			int p = i * i;
			sprintf(buff, "%d", p);
			if (strlen(buff) > digits)
				break;
			int q = p / m[digits] + p % m[digits];
			if (q * q == p)
			{
				printf(digits == 2 ? "%02d" : digits == 4 ? "%04d" : digits == 6 ? "%06d" : "%08d", p);
				putchar('\n');
			}
		}
	}
}