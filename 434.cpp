#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <iterator>

using namespace std;

int tests, K;
int frontView[8], rightView[8];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d:\\in.txt", "r", stdin);
	freopen("d:\\out.txt", "w", stdout);
#endif

	cin >> tests;
	while(tests--)
	{
		cin >> K;
		for(int i = 0; i < K; ++i) cin >> frontView[i];
		for(int i = 0; i < K; ++i) cin >> rightView[i];

		int minBlocks = 0, maxBlocks = 0;

		map<int, int> h1, h2;
		for(int i = 0; i < K; ++i)
			++h1[ frontView[i] ];
		for(int i = 0; i < K; ++i)
			++h2[ rightView[i] ];

		for(map<int, int>::iterator it = h1.begin(); it != h1.end(); ++it)
		{
			minBlocks += it->first * max(it->second, h2[it->first]);
			h2.erase(it->first);
		}
		for(map<int, int>::iterator it = h2.begin(); it != h2.end(); ++it)
			minBlocks += it->first * max(it->second, h1[it->first]);

		for(int i = 0; i < K; ++i)
			for(int j = 0; j < K; ++j)
				maxBlocks += min(frontView[j], rightView[i]);

		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", minBlocks, maxBlocks - minBlocks);
	}
	return 0;
}