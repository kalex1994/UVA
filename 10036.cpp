#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXK = 105;
int numbers[MAXN];
int dp[MAXN][MAXK];
int n, k, t;

int is_divisible(int sum, int pos)
{
    if (dp[pos][sum] > -1)
        return dp[pos][sum];

    if (pos == n)
        return dp[pos][sum] = (sum % k == 0);

    return dp[pos][sum] = is_divisible((sum + numbers[pos] % k) % k, pos + 1) ||
            is_divisible((sum - numbers[pos] % k) % k, pos + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i)
            scanf("%d", &numbers[i]);
        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < MAXK; ++j)
                dp[i][j] = -1;

        if (is_divisible(numbers[0] % k, 1))
            puts("Divisible");
        else
            puts("Not divisible");
    }
}
