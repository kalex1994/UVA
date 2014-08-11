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

struct player
{
	string name;
	int attack, defense;
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	player team[10];
	int tests;

	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		for (int i = 0; i < 10; ++i)
			cin >> team[i].name >> team[i].attack >> team[i].defense;
	
		sort(team, team + 10, [](const player &a, const player &b)
		{
			if (a.attack != b.attack) return a.attack > b.attack;
			if (a.defense != b.defense) return a.defense < b.defense;
			return a.name < b.name;
		});

		auto cmp_by_name = [](const player &a, const player &b) { return a.name < b.name; };
		sort(team, team + 5, cmp_by_name);
		sort(team + 5, team + 10, cmp_by_name);

		printf("Case %d:\n", test);
		printf("(%s, %s, %s, %s, %s)\n", team[0].name.c_str(), team[1].name.c_str(), team[2].name.c_str(), team[3].name.c_str(),
			team[4].name.c_str());
		printf("(%s, %s, %s, %s, %s)\n", team[5].name.c_str(), team[6].name.c_str(), team[7].name.c_str(), team[8].name.c_str(),
			team[9].name.c_str());
	}
}