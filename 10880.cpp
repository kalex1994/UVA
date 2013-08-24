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
	
long long N, C, R, caseNumber = 1;
set<long long> cookies;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	cin >> N;
	while(N--)
	{
		cookies.clear();
		cin >> C >> R;
		printf("Case #%d:",caseNumber++);

		if (C == R) 
		{
			printf(" 0\n");
			continue;
		}
		else
		{
			long long eaten = C - R;
			if (eaten < R) 
			{
				cout << endl;
				continue;
			}
			for(long long i = 1; i <= (long long)floor(sqrt(double(eaten))); ++i)
				if (eaten % i == 0)
				{
					long long j = eaten / i;
					if (i > R) cookies.insert(i);
					if (j > R) cookies.insert(j);
				}
		}

		for(set<long long>::const_iterator it = cookies.begin(); it != cookies.end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	return 0;
}


