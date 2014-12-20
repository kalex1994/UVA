#include<bits/stdc++.h>
using namespace std;

const int MAXK = 15;
const int MAXN = 105;

long double dp[MAXK][MAXN][MAXK];
long double p[MAXK][MAXN];
long double answer[MAXK][MAXN];
int k, n;

long double solve(int k, int n, int last)
{
    if (dp[k][n][last] > -1.0)
        return dp[k][n][last];

    if (n == 1)
        return dp[k][n][last] = 1.0;

    long double ans = 0.0;
    if (last > 0)
        ans += solve(k, n - 1, last - 1);
    ans += solve(k, n - 1, last);
    if (last < k)
        ans += solve(k, n - 1, last + 1);

    return dp[k][n][last] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    for(int k = 0; k < MAXK; ++k)
        for(int n = 0; n < MAXN; ++n)
            p[k][n] = pow(k, n);

    memset(dp, -1.0, sizeof(dp));
    memset(answer, -1.0, sizeof(answer));

    while(scanf("%d%d", &k, &n) == 2)
    {
        if (answer[k][n] > -1.0)
            printf("%.5Lf\n", answer[k][n]);
        else
        {
            double tight = 0;
            for(int last = 0; last <= k; ++last)
                tight += solve(k, n, last);
            answer[k][n] = tight / p[k + 1][n] * 100.0;
            printf("%.5Lf\n", answer[k][n]);
        }
    }
}
