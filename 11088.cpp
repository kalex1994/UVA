#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;

bool visited[1 << MAXN];
int points[MAXN];
int n, answer;

void solve(int mask, int teams)
{
    if (visited[mask])
        return;
    visited[mask] = true;

    answer = max(answer, teams);

    for(int i = 0; i < n; ++i)
    if (!(mask & (1 << i)))
        for(int j = i + 1; j < n; ++j)
        if(!(mask & (1 << j)))
            for(int k = j + 1; k < n; ++k)
            if(!(mask & (1 << k)))
            {
                int m = (1 << i) | (1 << j) | (1 << k);
                if (points[i] + points[j] + points[k] >= 20)
                    solve(mask | m, teams + 1);
            }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    freopen("E:\\OUT.txt", "w", stdout);
#endif

    int test = 1;
    while(cin >> n && n)
    {
        for(int i = 0; i < n; ++i)
            cin >> points[i];

        answer = 0;
        solve(0, 0);

        printf("Case %d: %d\n", test++, answer);
        memset(visited, false, sizeof(visited));
    }
}
