#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
#include <array>
#include <regex>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
using namespace std;

const int MAXN = 20;

vector<int> adjList[MAXN];
bool reachable[MAXN];
int fire;

void dfs(int root, int visited)
{
	visited |= (1 << root);
	for(int child : adjList[root])
	{
		reachable[child] = true;
		if ((visited & (1 << child)) == 0)
			dfs(child, visited);
	}
}

bool readInput()
{
	int a, b;

	if(!(cin >> fire))
		return false;
	--fire;

	for(int i = 0; i < MAXN; ++i)
		adjList[i].clear();

	while(cin >> a >> b && (a || b))
	{
		--a; --b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	for(int i = 0; i < MAXN; ++i)
		sort(adjList[i].begin(), adjList[i].end());

	return true;
}

vector<int> path;
int pathcount;

void solve(int node)
{
	if (node == fire)
	{
		for(size_t i = 0; i < path.size(); ++i)
			cout << (i == 0 ? "" : " ") << path[i] + 1;
		cout << endl;
		++pathcount;
		return;
	}

	if (!reachable[node])
		return;

	for(int child : adjList[node])
		if (find(path.begin(), path.end(), child) == path.end())
		{
			path.push_back(child);
			solve(child);
			path.pop_back();
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int test = 1;
	while (readInput())
	{
		printf("CASE %d:\n", test++);
		path = {0};
		fill(reachable, reachable + MAXN, false);
		dfs(fire, 0);
		pathcount = 0;
		solve(0);
		printf("There are %d routes from the firestation to streetcorner %d.\n", pathcount, fire + 1);
	}
}