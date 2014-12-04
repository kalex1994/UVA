#include <bits/stdc++.h>
using namespace std;

const int DR[] = {-1, 1, 0, 0};
const int DC[] = {0, 0, -1, 1};
const int MAXN = 100;
char grid[MAXN][MAXN];
int n;

int count_x(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return 0;
    char color = grid[r][c];
    grid[r][c] = '.';

    if (color == '.')
        return 0;
    else
    {
        int cnt = 0;
        for(int i = 0; i < 4; ++i)
            cnt += count_x(r + DR[i], c + DC[i]);
        return color == 'x' ? 1 + cnt : cnt;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    int tests;

    cin >> tests;
    for(int test = 1; test <= tests; ++test)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> grid[i][j];

        int alive_ships = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if (grid[i][j] != '.')
                    if (count_x(i, j) != 0)
                        ++alive_ships;

        printf("Case %d: %d\n", test, alive_ships);
    }
}
