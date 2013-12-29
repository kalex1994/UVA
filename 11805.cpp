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

	int n, k, p, tests, res;

	scanf("%d", &tests);
	for (int c = 1; c <= tests; ++c)
	{
		scanf("%d%d%d", &n, &k, &p);
		printf("Case %d: %d\n", c, ((res = (k + p) % n) == 0 ? n : res));
	}
	return 0;
}

