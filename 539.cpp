#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

bool connected[25][25];
int n, m;

void dfs(int node, int depth, int &max_depth)
{
	if (depth > max_depth)
		max_depth = depth;

	for(int i = 0; i < n; ++i)
		if (connected[node][i])
		{
			connected[node][i] = connected[i][node] = false;
			dfs(i, depth + 1, max_depth);
			connected[node][i] = connected[i][node] = true;
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	while(true)
	{
		cin >> n >> m;
		if (!(n || m)) break;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				connected[i][j] = false;

		int a, b;
		for(int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			connected[a][b] = connected[b][a] = true;
		}

		int max_depth = 0;
		for(int i = 0; i < n; ++i)
			dfs(i, 0, max_depth);

		cout << max_depth << endl;
	}
}