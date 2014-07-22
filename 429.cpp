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

int tests;
string line;
vector<string> words;
map< string, vector<string> > m;

int str_distance(const string& a, const string &b)
{
	int dist = 0;
	for(size_t i = 0; i < a.length(); ++i)
		if (a[i] != b[i])
			++dist;
	return dist;
}

void prepare()
{
	for(size_t i = 0; i + 1 < words.size(); ++i)
		for(size_t j = i + 1; j < words.size(); ++j)
			if (words[i].length() == words[j].length() && str_distance(words[i], words[j]) == 1)
			{
				m[words[i]].push_back(words[j]);
				m[words[j]].push_back(words[i]);
			}	
}

map<string, int> dist;
set<string> used;

void bfs(const string& start, const string& end)
{
	dist.clear();
	used.clear();

	queue<string> states;
	states.push(start);
	used.insert(start);

	while(!states.empty())
	{
		string s = states.front(); states.pop();

		for(size_t i = 0; i < m[s].size(); ++i)
			if (used.find(m[s][i]) == used.end())
			{
				used.insert(m[s][i]);
				states.push(m[s][i]);
				dist[m[s][i]] = dist[s] + 1;
				if (m[s][i] == end)
					break;
			}			
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	cin >> tests;
	cin.ignore(100, '\n');
	while(tests--)
	{
		words.clear();
		m.clear();

		while(getline(cin, line) && line != "*")
			words.push_back(line);
		prepare();
		while(getline(cin, line) && !line.empty())
		{
			istringstream iss(line);
			string a, b;
			iss >> a >> b;

			bfs(a, b);
			cout << a << " " << b << " " << dist[b] << endl;
		}

		if (tests)
			cout << endl;
	}
}