#include<bits/stdc++.h>
using namespace std;

const int N = 9;
int v[N * N][4];
int n, answer ;

void solve(int mask, int pos, int score)
{
    if (mask == (1 << N) - 1)
    {
        answer = max(answer, score);
        return;
    }
    if (pos == n)
        return;
    if (!(mask & ((1 << v[pos][0]) | (1 << v[pos][1]) | (1 << v[pos][2]))))
        solve(mask | (1 << v[pos][0]) | (1 << v[pos][1]) | (1 << v[pos][2]), pos + 1, score + v[pos][3]);
    solve(mask, pos + 1, score);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    int test = 1;
    while(cin >> n && n)
    {
        answer = -1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < 4; ++j)
                cin >> v[i][j];
            for(int j = 0; j < 3; ++j)
                --v[i][j];
        }
        solve(0, 0, 0);
        printf("Case %d: %d\n", test++, answer);
    }
}
