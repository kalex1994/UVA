#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdint.h>
using namespace std;

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	int n, k, p1, p2, winner, loser;
	bool first = true;
	string s1, s2;
	vector<int> players;

	while (cin >> n && n)
	{
		vector< pair<int, int> > players(n);
		cin >> k;

		int games = k*n*(n - 1) / 2;
		for (int i = 0; i < games; ++i)
		{
			cin >> p1 >> s1 >> p2 >> s2;

			if (s1 == s2) continue;

			if (s1[0] == 'r' && s2[0] == 's') { winner = p1; loser = p2; }
			else if (s1[0] == 's' && s2[0] == 'r') { winner = p2; loser = p1; }
			else if (s1[0] == 'p' && s2[0] == 'r') { winner = p1; loser = p2; }
			else if (s1[0] == 'r' && s2[0] == 'p') { winner = p2; loser = p1; }
			else if (s1[0] == 's' && s2[0] == 'p') { winner = p1; loser = p2; }
			else if (s1[0] == 'p' && s2[0] == 's') { winner = p2; loser = p1; }

			++players[winner - 1].first;
			++players[loser - 1].second;
		}

		if (first) first = false;
		else putchar('\n');

		for (size_t i = 0; i < players.size(); ++i)
		{
			if (players[i].first + players[i].second == 0) puts("-");
			else printf("%0.3lf\n", (double)players[i].first / (double)(players[i].first + players[i].second));
		}
	}
	return 0;
} 

