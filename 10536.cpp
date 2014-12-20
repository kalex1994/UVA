#include<bits/stdc++.h>
using namespace std;

const int N = 4;
const int NN = N * N;

int dp[1 << NN][2];
set<int> masks;

inline int ind(int r, int c) { return r * N + c; }

void create_masks()
{
    for(int i = 0; i < N; ++i)
    {
        int mask = 0;
        for(int j = 0; j + 1 < N; ++j)
        {
            mask |= 1 << ind(i, j);
            masks.insert(mask);
        }
        mask = 0;
        for(int j = N - 1; j > 0; --j)
        {
            mask |= 1 << ind(i, j);
            masks.insert(mask);
        }
    }
    for(int j = 0; j < N; ++j)
    {
        int mask = 0;
        for(int i = 0; i + 1 < N; ++i)
        {
            mask |= 1 << ind(i, j);
            masks.insert(mask);
        }
        mask = 0;
        for(int i = N - 1; i > 0; --i)
        {
            mask |= 1 << ind(i, j);
            masks.insert(mask);
        }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            masks.insert(1 << ind(i, j));
}

int solve(int state, int player)
{
    if (dp[state][player] > -1)
        return dp[state][player];

    if (state == (1 << NN) - 1)
        return player;

    bool can_win = false;
    for(int mask : masks)
        if (!(state & mask))
            if (solve(state | mask, 1 - player) == player)
                can_win = true;
    return dp[state][player] = can_win ? player : 1 - player;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    freopen("E:\\OUT.txt", "w", stdout);
#endif

    create_masks();
    memset(dp, -1, sizeof(dp));

    int tests, state;
    char ch;

    cin >> tests;
    while(tests--)
    {
        state = 0;
        for(int i = 0; i < NN; ++i)
        {
            cin >> ch;
            if (ch == 'X')
                state |= 1 << i;
        }
        if (dp[state][0] == -1)
            solve(state, 0);
        cout << (dp[state][0] == 0 ? "WINNING" : "LOSING") << endl;
    }
}
