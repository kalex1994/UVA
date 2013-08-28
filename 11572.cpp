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

	map<int, int> lastOccurence;
	int snowFlake, tests, n, begin, answer;

	cin >> tests;
	while(tests--)
	{
		lastOccurence.clear();
		begin = 0;
		answer = 1;

		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			cin >> snowFlake;
			if (lastOccurence.count(snowFlake) && lastOccurence[snowFlake] >= begin)
				begin = lastOccurence[snowFlake] + 1;
			lastOccurence[snowFlake] = i;
			answer = max(answer, i - begin + 1);
		}
		cout << answer << endl;
	}
	return 0;
}
