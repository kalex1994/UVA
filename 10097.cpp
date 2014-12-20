#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
typedef pair<int, int> state;

int color[MAXN][MAXN];
int tokens[3];
int n;

void bfs(const state& start)
{
    queue<state> q;
    map<state, int> dist;

    q.push(start);
    dist[start] = 0;
    bool found = false;

    while(!q.empty())
    {
        state s = q.front(); q.pop();

        if (s.first == tokens[2] || s.second == tokens[2])
        {
            printf("Minimum Number of Moves = %d\n\n", dist[s]);
            found = true;
            break;
        }

        if (color[s.first][s.second] != -1)
        {
            state newstate(color[s.first][s.second], s.second);
            if (dist.find(newstate) == dist.end())
            {
                dist[newstate] = dist[s] + 1;
                q.push(newstate);
            }
        }

        if (color[s.second][s.first] != -1)
        {
            state newstate(color[s.second][s.first], s.first);
            if (dist.find(newstate) == dist.end())
            {
                dist[newstate] = dist[s] + 1;
                q.push(newstate);
            }
        }
    }

    if (!found)
        puts("Destination is Not Reachable !\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    int game = 1;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &color[i][j]);
                --color[i][j];
            }
        for(int i = 0; i < 3; ++i)
        {
            scanf("%d", &tokens[i]);
            --tokens[i];
        }

        printf("Game #%d\n", game++);
        bfs(state(tokens[0], tokens[1]));
    }
}
