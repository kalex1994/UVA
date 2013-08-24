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
#include<cfloat>

using namespace std;

vector< vector<int> > wall;

void init()
{
	wall.clear();
	for(int i = 1; i <= 9; ++i)
		wall.push_back( vector<int>(i, 0) );
}

void read()
{
	for(int i = 0; i < (int)wall.size(); ++i)
		if (i % 2 == 0)
			for(int j = 0; j < (int)wall[i].size(); ++j)
				if (j % 2 == 0)
					cin >> wall[i][j];
}

void solve()
{
	for(int i = 0; i < (int)wall.size() - 1; ++i)
		if (i % 2 == 0)
			for(int j = 0; j < (int)wall[i].size(); ++j)
				if (j % 2 == 0)
				{
					int &x = wall[i + 2][j + 1];
					int &y = wall[i + 1][j];
					int &z = wall[i + 1][j + 1];
					int k = wall[i + 2][j];
					int p = wall[i + 2][j + 2];

					x = (wall[i][j] - k - p) / 2;
					y = k + x;
					z = x + p;
				}
}

void print()
{
	for(int i = 0; i < wall.size(); ++i)
	{
		for(int j = 0; j < wall[i].size(); ++j)
		{
			if (j > 0) cout << ' ';
			cout << wall[i][j];
		}
		cout << endl;
	}
}

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
		init();
		read();
		solve();
		print();
	}

	return 0;
}
