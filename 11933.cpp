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
	
	long n;

	while(cin >> n, n)
	{
		long a = 0, b = 0;
		bool oddPosition = true;

		for(int i = 0; i <= 31; ++i)
			if (n & (1 << i))
			{
				if (oddPosition)
				{
					oddPosition = false;
					a |= 1 << i;
				}
				else
				{
					oddPosition = true;
					b |= 1 << i;
				}
			}
		cout << a << " " << b << endl;
	}
	return 0;
}
