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
	
	int n, m, k, v, number;
	map<int, vector<int> > occurences;

	while(cin >> n >> m)
	{
		occurences.clear();

		for(int i = 0; i < n; ++i)
		{
			cin >> number;
			occurences[number].push_back(i + 1);
		}

		while(m--)
		{
			cin >> k >> v;
			if (!occurences.count(v)) cout << 0 << endl;
			else if (occurences[v].size() < k) cout << 0 << endl;
			else cout << occurences[v][k - 1] << endl;
		}
	}
	return 0;
}
