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
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, n, m;
	string candidate, party;
	map<string, string> p;
	map<string, int> votes;
	bool first = true;

	cin >> tests;
	while (tests--)
	{
		if (first) first = false;
		else cout << endl;

		p.clear();
		votes.clear();

		cin >> n; cin.ignore(100, '\n');
		while (n--)
		{
			getline(cin, candidate);
			getline(cin, party);
			p[candidate] = party;
		}
		cin >> m; cin.ignore(100, '\n');
		while (m--)
		{
			getline(cin, candidate);
			++votes[candidate];
		}

		vector<pair<int, string>> result;
		for (auto it = votes.begin(); it != votes.end(); ++it)
			result.push_back(make_pair(it->second, it->first));

		sort(result.rbegin(), result.rend());

		if (result[0].first == result[1].first)
			cout << "tie" << endl;
		else
			cout << p[result[0].second] << endl;
	}
}