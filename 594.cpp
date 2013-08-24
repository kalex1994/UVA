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
	
	int n, k;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d converts to ", n);
		k = 0;
		for(int i = 0; i < 4; ++i)
		{
			k |= n & 0x000000FF;
			if (i != 3)
				k = k << 8;
			n = n >> 8;
		}
		printf("%d\n", k);
	}
	return 0;
}
