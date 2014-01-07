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

int dp[100 + 5][100 + 5];

int lcs(int i, int j, const char* a, const char* b)
{
	if (i < 0 || j < 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (a[i] == b[j]) return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b);
	return dp[i][j] = max(lcs(i - 1, j, a, b), lcs(i, j - 1, a, b));
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	char a[100 + 5], b[100 + 5];
	int case_num = 1;

	while (true)
	{
		gets(a);
		if (a[0] == '#') break;
		gets(b);
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: you can visit at most %d cities.\n", case_num++, lcs(strlen(a) - 1, strlen(b) - 1, a, b));
	}

	return 0;
} 

