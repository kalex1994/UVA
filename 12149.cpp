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

	int sums[100 + 5] = { 0 };
	for (int i = 1; i <= 100; ++i)
		sums[i] += sums[i - 1] + i * i;

	int n;
	while (scanf("%d", &n), n)
		printf("%d\n", sums[n]);
	return 0;
}

