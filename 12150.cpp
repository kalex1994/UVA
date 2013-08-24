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

struct car
{
	int actualPosition;
	int number;
	int positionChanged;
	int initialPosition;

	car(int actPos, int num, int posChanged)
	{
		this->actualPosition = actPos;
		this->number = num;
		this->positionChanged = posChanged;
	}
};

bool cmp(const car &a, const car &b)
{
	return a.initialPosition < b.initialPosition;
}

vector<car> race;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n, number, positionChanged;

	while(cin >> n && n)
	{
		race.clear();

		for(int i = 1; i <= n; ++i)
		{
			cin >> number >> positionChanged;
			race.push_back(car(i, number, positionChanged));
		}

		bool isValid = true;
		set<int> usedPositions;

		for(int i = 0; i < (int)race.size(); ++i)
		{
			int initialPosition = race[i].actualPosition + race[i].positionChanged;
			if (initialPosition < 1 || initialPosition > n)
			{
				isValid = false;
				break;
			}
			if (usedPositions.count(initialPosition))
			{
				isValid = false;
				break;;
			}
			usedPositions.insert(initialPosition);
			race[i].initialPosition = initialPosition;
		}

		if (!isValid) cout << -1 << endl;
		else
		{
			sort(race.begin(), race.end(), cmp);
			for(int i = 0; i < (int)race.size(); ++i)
			{
				if (i > 0) cout << " ";
				cout << race[i].number;
			}
			cout << endl;
		}
	}
	return 0;
}




