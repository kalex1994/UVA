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
#include <functional>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdint.h>
using namespace std;

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	int t, a, b, sum;

	cin >> t;
	for (int test = 1; test <= t; ++test)
	{
		cin >> a >> b;
		sum = 0;
		for (int i = a; i <= b; ++i)
			if (i % 2 == 1)
				sum += i;
		printf("Case %d: %d\n", test, sum);
	}

	return 0;
} 

