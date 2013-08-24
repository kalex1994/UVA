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

int S, B, L, R;
int leftbuddy[100010], rightbuddy[100010];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(scanf("%d %d",&S, &B) && (S || B))
	{
		for(int i = 1; i <= S; ++i)
		{
			leftbuddy[i] = i - 1;
			rightbuddy[i] = i + 1;
		}
		rightbuddy[S] = 0;

		for(int i = 0; i < B; ++i)
		{
			scanf("%d %d", &L, &R);

			if (!leftbuddy[L]) printf("%d ", leftbuddy[L]);
			else printf("* ");

			if (!rightbuddy[R]) printf("%d\n", rightbuddy[R]);
			else puts("*");

			rightbuddy[ leftbuddy[L] ] = rightbuddy[R];
			leftbuddy[ rightbuddy[R] ] = leftbuddy[L];
		}
		puts("-");
	}
	return 0;
}




