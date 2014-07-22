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

const int MAX_SIZE = 700;

int n;
string node1, node2;
vector<int> g[MAX_SIZE];

inline int encode(const string& s)
{
	return (s[0] - 'A') * 26 + (s[1] - 'A');
}

inline string decode(int k)
{
	string result = "";
	result += k / 26 + 'A';
	result += k % 26 + 'A';
	return result;
}


int parent[MAX_SIZE];
bool visited[MAX_SIZE];

void bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty())
	{
		int node = q.front(); q.pop();

		for(size_t i = 0; i < g[node].size(); ++i)
			if (!visited[g[node][i]])
			{
				parent[g[node][i]] = node;
				visited[g[node][i]] = true;
				q.push(g[node][i]);
			}
	}
}

void print_solution(int end)
{
	vector<int> solution;
	for(int act = end; act != -1; act = parent[act])
		solution.push_back(act);
	if (solution.size() == 1)
		cout << "No route" << endl;
	else
	{
		for(size_t i = solution.size() - 1; i > 0; --i)
			cout << decode(solution[i]) << " " << decode(solution[i-1]) << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	bool first = true;

	while(cin >> n)
	{
		if (first) first = false;
		else cout << endl;

		for(int i = 0; i < n; ++i)
		{
			cin >> node1 >> node2;
			int code1 = encode(node1);
			int code2 = encode(node2);
			g[code1].push_back(code2);
			g[code2].push_back(code1);
		}

		cin >> node1 >> node2;
		int start = encode(node1);
		int end = encode(node2);
		for(int i = 0; i < MAX_SIZE; ++i)
		{
			parent[i] = -1;
			visited[i] = false;
		}
		bfs(start, end);
		print_solution(end);

		for(int i = 0; i < MAX_SIZE; ++i)
			g[i].clear();
	}

}