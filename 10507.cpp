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

int N, M;
char ch, cell1, cell2;
bool connected[26][26];
bool isAwake[26];

bool isAllAwake()
{
	int count = 0;
	for(int i = 0; i < 26; ++i)
		if(isAwake[i])
			++count;
	return count == N;
}

int getYears()
{
	vector<int> wakedUp;
	int years = 0;

	while(true)
	{
		if (isAllAwake()) return years;
		wakedUp.clear();

		for(int i = 0; i < 26; ++i)
			if (!isAwake[i])
			{
				int count = 0;

				for(int j = 0; j < 26; ++j)
					if (connected[i][j] && isAwake[j])
						++count;

				if (count >= 3) wakedUp.push_back(i);					
			}
		
		if (wakedUp.empty()) return -1;	
		for(int i = 0; i < (int)wakedUp.size(); ++i)
			isAwake[wakedUp[i]] = true;
	
		++years;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> N)
	{
		cin >> M;

		memset(connected, false, sizeof(connected));
		memset(isAwake, false, sizeof(isAwake));

		for(int i = 0; i < 3; ++i)
		{
			cin >> ch;
			isAwake[ch - 'A'] = true;
		}
		while(M--)
		{
			cin >> cell1 >> cell2;
			connected[cell1 - 'A'][cell2 - 'A'] = true;
			connected[cell2 - 'A'][cell1 - 'A'] = true;
		}

		int years = getYears();
		if (years == -1) cout << "THIS BRAIN NEVER WAKES UP" << endl;
		else cout << "WAKE UP IN, " << years << ", YEARS" << endl;
	}
	return 0;
}
