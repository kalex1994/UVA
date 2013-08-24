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

int created[15], needed[15];
int S;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int caseNumber = 1;

	while(cin >> S && S >= 0)
	{
		created[0] = S;
		for(int i = 1; i <= 12; ++i) cin >> created[i];
		for(int i = 1; i <= 12; ++i) cin >> needed[i];

		printf("Case %d:\n",caseNumber++);
		for(int i = 1; i <= 12; ++i)
		{
			if (S >= needed[i])
			{
				S -= needed[i];			
				cout << "No problem! :D" << endl;
			}
			else
				cout << "No problem. :(" << endl;

			S += created[i];
		}
	}
	return 0;
}




