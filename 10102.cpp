#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int N;
vector< vector<char> > grid;

int main()
{
	while (cin >> N)
	{
		grid.assign(N, vector<char>(N));

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> grid[i][j];

		int dist = INT_MIN;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			if (grid[i][j] == '1')
			{
				int closest = INT_MAX;
				for (int p = 0; p < N; ++p)
					for (int q = 0; q < N; ++q)
						if (grid[p][q] == '3')
							closest = min(closest, abs(p - i) + abs(q - j));
				dist = max(dist, closest);
			}
		cout << dist << endl;
	}
}