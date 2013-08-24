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

	int k, m;

	while(cin >> k >> m)
	{
		long double d = 43200.0 / fabs((long double)(k - m));
		long double kd = d * (86400.0 - (long double)k) / 86400.0;
		int mins = (int)floor(1440.0 * fmod((double)kd + 1e-7,0.5) + 0.5); 
		printf("%d %d %02d:%02d\n",k, m, 1 + (mins / 60 + 11) % 12, mins % 60);
	}
	return 0;
}


