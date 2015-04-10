#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;
const int MAXN = 35;
const int MAXM = 25;
const int MAXRODS = 305;
int t1, t2, n;

int m[MAXN];
int c1[MAXN][MAXM], c2[MAXN][MAXM];
int dp[MAXN][MAXRODS];
int parent[MAXN][MAXRODS];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    while(scanf("%d%d", &t1, &t2) && (t1 || t2))
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &m[i]);
            for(int j = 1; j <= m[i]; ++j)
                scanf("%d", &c1[i][j]);
            for(int j = 1; j <= m[i]; ++j)
                scanf("%d", &c2[i][j]);
        }

        for(int i = 0; i < MAXN; ++i)
            for(int j = 0; j < MAXRODS; ++j)
                dp[i][j] = INF;
        for(int j = 0; j <= m[0]; ++j)
        {
            dp[0][j] = c1[0][j] + c2[0][m[0] - j];
            parent[0][j] = -1;
        }

        for(int i = 1; i < n; ++i)
            for(int j = 0; j <= t1; ++j)
                for(int k = 0; k <= m[i]; ++k)
                    if (j - k >= 0)
                    {
                        int value = c1[i][k] + c2[i][m[i] - k] + dp[i - 1][j - k];
                        if (value < dp[i][j])
                        {
                            dp[i][j] = value;
                            parent[i][j] = k;
                        }
                    }
        printf("%d\n", dp[n - 1][t1]);

        deque<int> solution;
        int rods = t1;
        for (int site = n - 1; site > 0; --site)
        {
            solution.push_back(parent[site][rods]);
            rods -= parent[site][rods];
        }
        printf("%d", rods);
        for (auto it = solution.rbegin(); it != solution.rend(); ++it)
            printf(" %d", *it);
        printf("\n\n");
    }
}
