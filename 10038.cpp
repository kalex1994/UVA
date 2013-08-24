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

int n;
int sequence[3010];
bitset<3010> values;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
			cin >> sequence[i];

		if (n == 1) 
		{
			cout << "Jolly" << endl;
			continue;
		}
		else if (n == 0)
		{
			cout << "Not jolly" << endl;
			continue;
		}

		for(int i = 1; i < n; ++i)
			values.reset(i);

		for(int i = 1; i < n; ++i)
			values.set( abs(sequence[i] - sequence[i - 1]) );

		bool isJolly = true;

		for(int i = 1; i < n; ++i)
			if ( !values.test(i) )
				isJolly = false;

		if (isJolly) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}
