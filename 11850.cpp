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
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n;
	vector<int> stations;

	while(cin >> n, n)
	{
		stations.assign(n,0);
		for(int i = 0; i < n; ++i)
			cin >> stations[i];

		sort(stations.begin(), stations.end());

		bool flag = true;
		for(int i = 0; i < n; ++i)
			if (stations[i] + 200 < stations[i+1])
			{
				flag = false;
				break;
			}
		if (2 * (1422 - stations.back()) > 200) flag = false;

		if (flag) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}




