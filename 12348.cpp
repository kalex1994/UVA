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

int n, m;
int sets[111];

bool has_solution()
{
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		bool flag = true;
		for (int i = 0; i < m; ++i)
		{
			bool red = false, blue = false;
			for (int j = 0; j < n; ++j)
			if (sets[i] & (1 << j))
			{
				if (mask & (1 << j))
					red = true;
				else
					blue = true;
			}
			if (!(red && blue))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int k;
	string line;

	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i)
			sets[i] = 0;
		cin.ignore(100, '\n');

		for (int i = 0; i < m; ++i)
		{
			getline(cin, line);
			istringstream iss(line);
			int num;

			while (iss >> num)
				sets[i] |= (1 << (num - 1));
		}

		if (has_solution())
			putchar('Y');
		else
			putchar('N');
	}
}