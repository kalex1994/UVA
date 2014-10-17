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

vector<pair<int, pair<int, int>>> blocks;
#define x first
#define y second.first
#define z second.second

const int MAXV = 90;
const int INF = numeric_limits<int>::max() / 3;
int g[MAXV + 1][MAXV + 1];

void build_graph()
{
	for(size_t i = 0; i <= blocks.size(); ++i)
		for(size_t j = 0; j <= blocks.size(); ++j)
			g[i][j] = (i == j ? 0 : -INF);

	for(size_t i = 0; i < blocks.size(); ++i)
		for(size_t j = 0; j < blocks.size(); ++j)
		{
			auto &bi = blocks[i], &bj = blocks[j];
			if ((bi.x > bj.x && bi.y > bj.y) || (bi.x > bj.y && bi.y > bj.x))
				g[i][j] = bi.z;
		}
	for(size_t i = 0; i < blocks.size(); ++i)
		g[i][blocks.size()] = blocks[i].z;
}

void floyd_warshall()
{
	for(size_t k = 0; k <= blocks.size(); ++k)
		for(size_t i = 0; i <= blocks.size(); ++i)
			for(size_t j = 0; j <= blocks.size(); ++j)
				g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
}

int max_height()
{
	build_graph();
	floyd_warshall();
	int height = numeric_limits<int>::min();
	for(size_t i = 0; i <= blocks.size(); ++i)
		for(size_t j = 0; j <= blocks.size(); ++j)
			height = max(height, g[i][j]);
	return height;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n, d1, d2, d3, test = 1;
	while(scanf("%d", &n) && n)
	{
		blocks.clear();
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d%d", &d1, &d2, &d3);
			blocks.push_back(make_pair(d1, make_pair(d2, d3)));
			blocks.push_back(make_pair(d1, make_pair(d3, d2)));
			blocks.push_back(make_pair(d2, make_pair(d3, d1)));
		}
		printf("Case %d: maximum height = %d\n", test++, max_height());
	}
}