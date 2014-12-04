#include <bits/stdc++.h>
using namespace std;

const int MAXR = 505;
const int MAXC = 505;

struct node
{
    bool north, east, south, west;
    node(bool n = false, bool e = false, bool s = false, bool w = false) : north(n), east(e), south(s), west(w) {}
};

node rotate(const node& n)
{
    node ret;
    if (n.north) ret.east = true;
    if (n.east) ret.south = true;
    if (n.south) ret.west = true;
    if (n.west) ret.north = true;
    return ret;
}

node grid[4][MAXR][MAXC];
int rows, cols;

struct state
{
    int row;
    int col;
    int rotation;
    state(int r, int c, int rot) : row(r), col(c), rotation(rot) {}
    bool operator<(const state& other) const
    {
        if (row != other.row) return row < other.row;
        if (col != other.col) return col < other.col;
        return rotation < other.rotation;
    }
};

void solve()
{
    queue<state> q;
    map<state, int> dist;

    state start(0, 0, 0);
    q.push(start);
    dist[start] = 0;

    while(!q.empty())
    {
        state s = q.front(); q.pop();

        if (s.row + 1 == rows && s.col + 1 == cols)
        {
            break;
        }

        int r = s.row;
        int c = s.col;
        int rot = s.rotation;
        node& n = grid[rot][r][c];

        if (n.north)
        {
            if (r - 1 >= 0)
            {
                state newstate(r - 1, c, (rot + 1) % 4);
                if (dist.find(newstate) == dist.end())
                {
                    dist[newstate] = dist[s] + 1;
                    q.push(newstate);
                }
            }
        }
        if (n.east)
        {
            if (c + 1 < cols)
            {
                state newstate(r, c + 1, (rot + 1) % 4);
                if (dist.find(newstate) == dist.end())
                {
                    dist[newstate] = dist[s] + 1;
                    q.push(newstate);
                }
            }
        }
        if (n.south)
        {
            if (r + 1 < rows)
            {
                state newstate(r + 1, c, (rot + 1) % 4);
                if (dist.find(newstate) == dist.end())
                {
                    dist[newstate] = dist[s] + 1;
                    q.push(newstate);
                }
            }
        }
        if (n.west)
        {
            if (c - 1 < cols)
            {
                state newstate(r, c - 1, (rot + 1) % 4);
                if (dist.find(newstate) == dist.end())
                {
                    dist[newstate] = dist[s] + 1;
                    q.push(newstate);
                }
            }
        }
    }

    int ans = numeric_limits<int>::max();
    for(const pair<state, int>& s : dist)
        if (s.first.row + 1 == rows && s.first.col + 1 == cols)
            ans = min(ans, s.second);
    if (ans == numeric_limits<int>::max())
        cout << "no path to exit" << endl;
    else
        cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    while(cin >> rows >> cols)
    {
        string s;
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
            {
                if (i + 1 == rows && j + 1 == cols)
                    break;
                cin >> s;
                grid[0][i][j] = node();
                for(char ch : s)
                {
                    switch(ch)
                    {
                    case 'N':
                        grid[0][i][j].north = true;
                        break;
                    case 'E':
                        grid[0][i][j].east = true;
                        break;
                    case 'S':
                        grid[0][i][j].south = true;
                        break;
                    case 'W':
                        grid[0][i][j].west = true;
                        break;
                    }
                }
            }

        for(int rot = 1; rot < 4; ++rot)
            for(int i = 0; i < rows; ++i)
                for(int j = 0; j < cols; ++j)
                    grid[rot][i][j] = rotate(grid[rot - 1][i][j]);

        solve();
    }
}
