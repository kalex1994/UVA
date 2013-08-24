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

long long n, k, butts, cigarettes;

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	while(cin >> n >> k)
	{
		butts = cigarettes = 0;
		while(n != 0)
			if (n >= k)
			{
				butts =  n / k;
				cigarettes += (n - (n % k));
				n %= k;
				n += butts;
			}
			else
			{
				cigarettes += n;
				n = 0;
			}
		cout << cigarettes << endl;
	}
	return 0;
}


