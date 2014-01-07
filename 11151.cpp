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

const int MAX_LENGTH = 1000 + 5;
int dp[MAX_LENGTH][MAX_LENGTH];
char s[MAX_LENGTH];
int tests;

int longest_palindrome(int l, int r)
{
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 1;
	if (l + 1 == r) return dp[l][r] = s[l] == s[r] ? 2 : 1;
	if (s[l] == s[r]) return dp[l][r] = 2 + longest_palindrome(l + 1, r - 1);
	else return dp[l][r] = max(longest_palindrome(l + 1, r), longest_palindrome(l, r - 1));
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);

	scanf("%d%*c", &tests);
	while (tests--)
	{
		gets(s);
		size_t len = strlen(s);
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j)
				dp[i][j] = -1;
		printf("%d\n", longest_palindrome(0, len - 1));
	}

	return 0;
} 

