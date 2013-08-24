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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	int n, m, tests, disqualified;
	string tournament;

	cin >> tests;
	while(tests--)
	{
		cin >> n >> m;
		tournament.assign(1 << n, '1');

		while(m--)
		{
			cin >> disqualified;
			tournament[disqualified - 1] = '0';
		}

		int walkoverMatches = 0;
		while(tournament.size() != 1)
		{
			string nextRound = "";
			
			for(int i = 0; i < (int)tournament.size(); i += 2)
				if (tournament[i] == '1' && tournament[i + 1] == '1') nextRound += '1';
				else if (tournament[i] == '0' && tournament[i + 1] == '0') nextRound += '0';
				else 
				{
					nextRound += '1';
					++walkoverMatches;
				}

				tournament = nextRound;
		}
		cout << walkoverMatches << endl;
	}
	return 0;
}
