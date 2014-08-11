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

	int start_grid[25];
	int finishing_grid[25];
	int n;

	while (cin >> n)
	{
		for (int i = 0; i < n; ++i) cin >> start_grid[i];
		for (int i = 0; i < n; ++i) cin >> finishing_grid[i];

		int overtakes = 0;
		for (int i = 0; i < n; ++i)
		{
			int index = find(finishing_grid, finishing_grid + n, start_grid[i]) - finishing_grid;

			for (int j = 0; j < i; ++j)
				for (int k = index + 1; k < n; ++k)
					if (start_grid[j] == finishing_grid[k])
						++overtakes;
		}
		cout << overtakes << endl;
	}
}