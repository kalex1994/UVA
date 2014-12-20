#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull start_grid[3][3];
ull destination_grid[3][3] = {
    {1ull, 2ull, 3ull},
    {4ull, 5ull, 6ull},
    {7ull, 8ull, 9ull}
};

inline int index(int row, int col)
{
    return row * 3 + col;
}

inline ull get_mask(int row, int col)
{
    return 0xFull << (4 * index(row, col));
}

inline ull save_state(ull grid[3][3])
{
    ull state = 0ull;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            state |= (grid[i][j] << (4lu * index(i, j)));
    return state;
}

inline void extract_state(ull state, ull grid[3][3])
{
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            grid[i][j] = ((state & get_mask(i, j)) >> (4 * index(i, j)));
}

void shift_left(int row, ull grid[3][3])
{
    ull temp = grid[row][0];
    grid[row][0] = grid[row][1];
    grid[row][1] = grid[row][2];
    grid[row][2] = temp;
}

void shift_down(int col, ull grid[3][3])
{
    ull temp = grid[2][col];
    grid[2][col] = grid[1][col];
    grid[1][col] = grid[0][col];
    grid[0][col] = temp;
}

unordered_map<ull, pair<char, int>> op;
unordered_map<ull, ull> parent;
unordered_map<ull, ull> dist;

void bfs(ull start)
{
    queue<ull> q;
    unordered_set<ull> visited;
    ull grid[3][3];

    q.push(start);
    visited.insert(start);
    dist[start] = 0;
    while(!q.empty())
    {
        ull state = q.front(); q.pop();
        for(int row = 0; row < 3; ++row)
        {
            extract_state(state, grid);
            shift_left(row, grid);
            ull new_state = save_state(grid);
            if (visited.find(new_state) == visited.end())
            {
                parent[new_state] = state;
                op[new_state] = make_pair('H', row + 1);
                dist[new_state] = dist[state] + 1;
                visited.insert(new_state);
                q.push(new_state);
            }
        }
        for(int col = 0; col < 3; ++col)
        {
            extract_state(state, grid);
            shift_down(col, grid);
            ull new_state = save_state(grid);
            if (visited.find(new_state) == visited.end())
            {
                parent[new_state] = state;
                op[new_state] = make_pair('V', col + 1);
                dist[new_state] = dist[state] + 1;
                visited.insert(new_state);
                q.push(new_state);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    ull destination = save_state(destination_grid);
    bfs(destination);

    bool flag = true;
    while(true)
    {
        for(int i = 0; flag && i < 3; ++i)
            for(int j = 0; flag && j < 3; ++j)
            {
                cin >> start_grid[i][j];
                if (start_grid[i][j] == 0ull)
                {
                    flag = false;
                    break;
                }
            }
        if (!flag)
            break;

        ull state = save_state(start_grid);

        if (parent.find(state) != parent.end())
        {
            ull curr = state;
            cout << dist[state] << " ";
            while(parent.find(curr) != parent.end())
            {
                cout << op[curr].first << op[curr].second;
                curr = parent[curr];
            }
            cout << endl;
        }
        else
        {
            if (state == destination) cout << 0 << endl;
            else cout << "Not solvable" << endl;
        }
    }
}
