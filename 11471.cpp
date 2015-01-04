#include<bits/stdc++.h>
using namespace std;

const int ROWS = 4;
const int COLS = 3;
const int N = ROWS * COLS;
const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

string tiles[N];
bool visited[N];
int grid[ROWS][COLS];
unsigned long long answer;

bool can_place(int pos, int tile_index)
{
    int row = pos / COLS;
    int col = pos % COLS;

    if (row == 0 && col == 0) return true;
    if (row == 0) return tiles[grid[row][col - 1]][RIGHT] == tiles[tile_index][LEFT];
    if (col == 0) return tiles[grid[row - 1][col]][DOWN] == tiles[tile_index][UP];
    return tiles[grid[row][col - 1]][RIGHT] == tiles[tile_index][LEFT] &&
           tiles[grid[row - 1][col]][DOWN] == tiles[tile_index][UP];
}

void dfs(int pos, int tile_index)
{
    if (pos + 1 == N)
    {
        ++answer;
        return;
    }

    grid[pos / COLS][pos % COLS] = tile_index;

    set<string> uniq;
    for(int i = 0; i < 12; ++i)
        if (!visited[i] && can_place(pos + 1, i) && uniq.count(tiles[i]) == 0)
        {
            uniq.insert(tiles[i]);
            visited[i] = true;
            dfs(pos + 1, i);
            visited[i] = false;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    freopen("E:\\OUT.txt", "w", stdout);
#endif

    unsigned long long fact[13];
    fact[0] = 1llu;
    for(int i = 1; i <= 12; ++i)
        fact[i] = i * fact[i - 1];

    int tests;
    cin >> tests;
    for(int test = 1; test <= tests; ++test)
    {
        answer = 0;

        map<string, int> count;
        for(int i = 0; i < 12; ++i)
        {
            cin >> tiles[i];
            ++count[tiles[i]];
        }

        set<string> uniq;
        for(int i = 0; i < 12; ++i)
            if (uniq.count(tiles[i]) == 0)
            {
                uniq.insert(tiles[i]);
                visited[i] = true;
                dfs(0, i);
                visited[i] = false;
            }

        for(auto entry : count)
            answer *= fact[entry.second];

        printf("Case %d: %llu\n", test, answer);
    }
}
