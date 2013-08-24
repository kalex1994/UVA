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

int frequency[256];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, R, C, M, N;

	cin >> tests;
	for(int t = 1; t <= tests; ++t)
	{
		memset(frequency, 0, sizeof(frequency));
		cin >> R >> C >> M >> N;

		char ch;
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
			{
				cin >> ch;
				++frequency[ch];
			}

		int maxFrequency = 0;
		for(int i = 0; i < 256; ++i)
			if (frequency[i] > maxFrequency)
				maxFrequency = frequency[i];

		int answer = 0;
		for(int i = 0; i < 256; ++i)
			if (frequency[i] == maxFrequency)
				answer += M * frequency[i];
			else
				answer += N * frequency[i];

		printf("Case %d: %d\n", t, answer);
	}
	return 0;
}




