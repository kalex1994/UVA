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

enum WEIGHT {LIGHT, HEAVY};

struct Weighting
{
	vector<int> leftSide, rightSide;
	char result;

	bool isBad(int c, WEIGHT weight)
	{
		bool inLeft = find(leftSide.begin(), leftSide.end(), c) != leftSide.end();
		bool inRight = find(rightSide.begin(), rightSide.end(), c) != rightSide.end();

		if (!inLeft && !inRight) return true;
		if (inLeft)
		{
			if (weight == LIGHT && result == '<') return true;
			if (weight == HEAVY && result == '>') return true;
		}
		else if (inRight)
		{
			if (weight == LIGHT && result == '>') return true;
			if (weight == HEAVY && result == '<') return true;
		}
		return false;
	}
};

int N, K;
vector<Weighting> weightings;

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
		weightings.clear();

		cin >> N >> K;

		for(int i = 0; i < K; ++i)
		{
			int count;
			cin >> count;

			Weighting w;
			w.leftSide.assign(count, 0);
			w.rightSide.assign(count, 0);

			for(int i = 0; i < count; ++i) cin >> w.leftSide[i];
			for(int i = 0; i < count; ++i) cin >> w.rightSide[i];
			cin >> w.result;

			weightings.push_back(w);
		}

		set<int> possiblyBad;
		for(int i = 1; i <= N; ++i)
		{
			bool bad = true;
			for(int j = 0; j < (int)weightings.size(); ++j)
				if (!weightings[j].isBad(i, LIGHT))
					bad = false;

			if (bad) possiblyBad.insert(i);

			bad = true;
			for(int j = 0; j < (int)weightings.size(); ++j)
				if (!weightings[j].isBad(i, HEAVY))
					bad = false;

			if (bad) possiblyBad.insert(i);
		}

		if (possiblyBad.empty() || possiblyBad.size() > 1) cout << "0" << endl;
		else cout << *possiblyBad.begin() << endl;
		if (tests) cout << endl;
	}
	return 0;
}




