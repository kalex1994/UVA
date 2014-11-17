#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 55;
typedef long long ll;

int n, k, m;
ll dp[MAXN][MAXN][MAXN];

ll solve(int pos, int bars, int len)
{
	if (pos == 0 || bars == 0) return dp[pos][bars][len] = 0;
	if (pos == bars) return dp[pos][bars][len] = 1;

	if (dp[pos][bars][len] != -1)
		return dp[pos][bars][len];

	if (len > 0)
		return dp[pos][bars][len] = solve(pos - 1, bars, len - 1) + solve(pos - 1, bars - 1, m);
	else
		return dp[pos][bars][len] = solve(pos - 1, bars - 1, m);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\hallgato\\IN.txt", "r", stdin);
	freopen("D:\\hallgato\\OUT.txt", "w", stdout);
#endif

	while (scanf("%d%d%d", &n, &k, &m) == 3)
	{
		--m;
		for (int a = 0; a <= n; ++a)
		for (int b = 0; b <= k; ++b)
		for (int c = 0; c <= m; ++c)
			dp[a][b][c] = -1;
		cout << solve(n, k, m) << endl;
	}
}