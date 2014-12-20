#include<bits/stdc++.h>
using namespace std;

const int N = 12;
int dp[1 << N];

int solve(int mask)
{
    if (dp[mask] > -1)
        return dp[mask];

    int ans = __builtin_popcount(mask);
    for(int i = 0; i + 1 < N; ++i)
        if ((mask & (1 << i)) && (mask & (1 << (i + 1))))
        {
            if (i - 1 >= 0 && !(mask & (1 << (i - 1))))
            {
                int temp = mask;
                temp &= ~(1 << (i + 1));
                temp &= ~(1 << i);
                temp |= (1 << (i - 1));
                ans = min(ans, solve(temp));
            }
            if (i + 2 < N && !(mask & (1 << (i + 2))))
            {
                int temp = mask;
                temp &= ~(1 << i);
                temp &= ~(1 << (i + 1));
                temp |= (1 << (i + 2));
                ans = min(ans, solve(temp));
            }
        }
    return dp[mask] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    fill(dp, dp + (1 << N), -1);

    int n, mask;
    string s;

    cin >> n;
    while(n--)
    {
        cin >> s;
        mask = 0;

        for(int i = 0; i < (int)s.length(); ++i)
            if (s[i] == 'o')
                mask |= (1 << i);
        cout << solve(mask) << endl;
    }
}
