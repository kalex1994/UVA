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

	int tests, n, need, caseNumber = 1;
	int fuel[100001];

	cin >> tests;
	while(tests--)
	{
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> fuel[i];
		for(int i = 0; i < n; ++i)
		{
			cin >> need;
			fuel[i] -= need;
		}

		int sum = 0;
		for(int i = 0; i < n; ++i)
			sum += fuel[i];

		printf("Case %d: ", caseNumber++);
		if (sum < 0)
			cout << "Not possible" << endl;
		else
		{
			for(int i = 0; i < n; ++i)
				if (fuel[i] >= 0)
				{
					int index = i;
					bool found = true;
					sum = 0;
					for(int j = 0; j < n; ++j)
					{
						sum += fuel[index];
						if (sum < 0)
						{
							found = false;
							break;
						}
						index = (index + 1) % n;
					}
					if (found)
					{
						cout << "Possible from station " << i + 1 << endl;
						break;
					}
				}
		}
	}
	return 0;
}
