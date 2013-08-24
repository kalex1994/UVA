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

enum DAY {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

inline void nextDay(DAY &d)
{
	d = (DAY)(( d + 1 ) % 7);
}

int simulationDays, P;
vector<int> hartals;

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
		hartals.clear();
		cin >> simulationDays >> P;

		hartals.resize(P);
		for(int i = 0; i < P; ++i)
			cin >> hartals[i];

		DAY currentDay = SUNDAY;
		int answer = 0;

		for(int i = 1; i <= simulationDays; ++i)
		{
			if (currentDay != FRIDAY && currentDay != SATURDAY)
			{
				for(int j = 0; j < P; ++j)
					if (i % hartals[j] == 0)
					{
						++answer;
						break;
					}
			}
			nextDay(currentDay);
		}
		cout << answer << endl;
	}	
	return 0;
}




