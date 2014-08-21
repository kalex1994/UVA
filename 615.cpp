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
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
using namespace std;

const int MAX_SIZE = 50000;
vector<int> adjList[MAX_SIZE];
map<int, int> nodes;
int n = 0;

void dfs(int root, bool* visited)
{
	visited[root] = true;
	for(int child : adjList[root])
		dfs(child, visited);
}

bool is_tree()
{
	if (n == 0)
		return true;

	int root = -1;
	int in_degree[MAX_SIZE];
	bool visited[MAX_SIZE];

	fill(in_degree, in_degree + n, 0);
	for(int i = 0; i < n; ++i)
		for(int child : adjList[i])
			++in_degree[child];

	for(int i = 0; i < n; ++i)
		if (in_degree[i] == 0)
		{
			if (root == -1)
				root = i;
			else
				return false;
		}
		else if (in_degree[i] != 1)
			return false;
	if (root < 0)
		return false;

	fill(visited, visited + n, false);
	dfs(root, visited);
	for(int i = 0; i < n; ++i)
		if(!visited[i])
			return false;
	return true;
}

bool readInput()
{
	int node1, node2;

	if (n > 0)
		for(int i = 0; i < n; ++i)
			adjList[i].clear();
	nodes.clear();
	n = 0;

	while(cin >> node1 >> node2)
	{
		if (node1 < 0 && node2 < 0)
			return false;
		if (node1 == 0 && node2 == 0)
			break;
		if (nodes.find(node1) == nodes.end())
			nodes[node1] = n++;
		if (nodes.find(node2) == nodes.end())
			nodes[node2] = n++;
		adjList[nodes[node1]].push_back(nodes[node2]);
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int index = 1;
	while(readInput())
	{
		if (is_tree())
			printf("Case %d is a tree.\n", index++);
		else
			printf("Case %d is not a tree.\n", index++);

	}
}