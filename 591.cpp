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

	int n, h, dataSet = 1, sum;
	vector<int> heights;

	while(cin >> n, n)
	{
		heights.clear();

		sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> h;
			sum += h;
			heights.push_back(h);
		}

		int mid = sum / n;

		int answer = 0;
		for(int i = 0; i < (int)heights.size(); ++i)
			if (heights[i] > mid)
				answer += heights[i] - mid;

		printf("Set #%d\n",dataSet++);
		printf("The minimum number of moves is %d.\n\n", answer);
	}
	return 0;
}




