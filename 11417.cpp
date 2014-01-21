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
#include <bitset>
#include <stdint.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout); 

	int n;

	while (scanf("%d", &n) != EOF && n)
	{
		int g = 0;
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j <= n; ++j)
				g += gcd(i, j);
		printf("%d\n", g);
	}

	return 0;
} 

