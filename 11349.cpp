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
	
	long long matrix[110][110];
	int tests, N, caseNumber = 1;

	scanf("%d", &tests);
	while(tests--)
	{
		scanf("%*[^0-9]%d", &N);

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				cin >> matrix[i][j];

		bool symmetric = true;

		for(int i = 0; i < N && symmetric; ++i)
			for(int j = 0; j < N && symmetric; ++j)
			{
				if (matrix[i][j] < 0 || matrix[i][j] != matrix[N - i - 1][N - j - 1])
					symmetric = false;
			}

		printf("Test #%d: ", caseNumber++);
		if (symmetric) 
			puts("Symmetric.");
		else 
			puts("Non-symmetric.");
	}
	return 0;
}




