#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	int R, N, test = 1;

	while (scanf("%d%d", &R, &N) != EOF && (R || N))
	{
		if (N * 27 < R) printf("Case %d: impossible\n", test++);
		else if (N >= R) printf("Case %d: 0\n", test++);
		else printf("Case %d: %d\n", test++, (R - N) % N == 0 ? (R - N) / N : (R - N) / N + 1);
	}

	return 0;
}

