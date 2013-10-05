#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <iterator>

using namespace std;

int tests, N, S, Q, Qi, cargo;
vector< deque<int> > stations;

bool isAllStationEmpty()
{
	for(int i = 0; i < N; ++i)
		if (!stations[i].empty())
			return false;
	return true;
}

inline void goToNextStation(int &currentStation)
{
	currentStation = (currentStation + 1) % N;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d:\\in.txt", "r", stdin);
	freopen("d:\\out.txt", "w", stdout);
#endif

	cin >> tests;
	while(tests--)
	{
		stations.clear();

		cin >> N >> S >> Q;
		for(int i = 0; i < N; ++i)
		{
			stations.push_back(deque<int>());
			cin >> Qi;
			for(int j = 0; j < Qi; ++j)
			{
				cin >> cargo;
				stations.back().push_back(cargo-1);
			}
		}

		int minutes = 0;
		int currentStation = 0;
		stack<int> carrier;
		while(true)
		{
			while (!carrier.empty())
			{
				if (carrier.top() != currentStation)
				{
					if ((int)stations[currentStation].size() < Q)
						stations[currentStation].push_back(carrier.top());
					else
						break;
				}					
				carrier.pop();
				++minutes;
			}
			while ((int)carrier.size() < S && !stations[currentStation].empty())
			{
				carrier.push( stations[currentStation].front() );
				stations[currentStation].pop_front();
				++minutes;
			}
			if (isAllStationEmpty() && carrier.empty()) break;

			goToNextStation(currentStation);
			minutes += 2;
		}
		cout << minutes << endl;
	}
	return 0;
}