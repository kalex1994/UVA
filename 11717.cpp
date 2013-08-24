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

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	int tests, n, idle, activate;
	vector<int> instructions;
	
	cin >> tests;
	for(int t = 1; t <= tests; ++t)
	{
		instructions.clear();

		cin >> n >> idle >> activate;
		for(int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			instructions.push_back(num);
		}
		
		int last = 0, switches = 0, misses = 0;
		for(int i = 0; i < (int)instructions.size(); ++i)
		{
			if (last > instructions[i])
			{
				++misses;
				continue;
			}

			if (instructions[i] - last >= idle)
			{
				++switches;
				last = instructions[i] + activate;
			}
			else
				last = instructions[i];
		}
		printf("Case %d: %d %d\n",t,switches,misses);
	}
	return 0;
}


