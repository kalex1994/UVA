#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>

using namespace std;

enum COLOR { RED, BLUE };

vector<int> floors[2];
int floorCount, f, answer;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;

	cin >> tests;
	while(tests--)
	{
		floors[0].clear(); floors[1].clear();

		cin >> floorCount;
		while(floorCount--)
		{
			cin >> f;
			if (f < 0) floors[RED].push_back(-f);
			else floors[BLUE].push_back(f);
		}

		sort(floors[RED].begin(), floors[RED].end());
		sort(floors[BLUE].begin(), floors[BLUE].end());

		if (floors[RED].empty() && floors[BLUE].empty()) answer = 0;
		else if (floors[RED].empty() || floors[BLUE].empty()) answer = 1;
		else
		{
			COLOR currentColor = floors[RED].back() > floors[BLUE].back() ? RED : BLUE;
			COLOR otherColor = currentColor == RED ? BLUE : RED;
			answer = 0;

			while(true)
			{
				if (floors[currentColor].empty()) break;
				++answer;

				while( !floors[currentColor].empty() && !floors[otherColor].empty() && floors[currentColor].back() > floors[otherColor].back())
					floors[currentColor].pop_back();

				currentColor = currentColor == RED ? BLUE : RED;
				otherColor = currentColor == RED ? BLUE : RED;
			}
		}
		cout << answer << endl;
	}
	return 0;
}




