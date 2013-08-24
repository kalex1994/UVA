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

	int n, cost, k;

	while(cin >> n, n)
	{
		priority_queue<int> numbers;
		while(n--)
		{
			cin >> k;
			numbers.push(-k);
		}

		cost = 0;
		while(true)
		{
			int a = -numbers.top(); numbers.pop();
			if (numbers.empty()) break;
			int b = -numbers.top(); numbers.pop();

			cost += a + b;
			numbers.push( -1 * (a + b) );
		}
		cout << cost << endl;
	}
	return 0;
}
