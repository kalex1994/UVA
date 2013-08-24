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

	ios::sync_with_stdio(false);

	int dat[256];
	unsigned long long sum;
	int tests, ch, price, K, M;

	cin >> tests;
	while(tests--)
	{
		memset(dat, 0, sizeof(dat));
		sum = 0;

		cin >> K; cin.get();
		while(K--)
		{
			ch = cin.get();
			cin >> price;
			cin.get();
			dat[ ch ] = price;
		}

		cin >> M; cin.get();
		while(M--)
		{
			while(true)
			{
				ch = cin.get();
				if (ch == EOF || ch == '\n') break;
				sum += dat[ ch ];
			}
		}
		printf("%lld.%02lld$\n", sum / 100, sum % 100);
	}
	return 0;
}




