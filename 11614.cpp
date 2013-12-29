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

	typedef unsigned long ul;
	ul tests, n;

	scanf("%llu", &tests);
	while (tests--)
	{
		scanf("%llu", &n);
		ul x = (ul)((-1.0 + sqrt(1.0 + 8.0 * n)) / 2.0);
		printf("%llu\n", x);
	}

	return 0;
}

