#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
vector<int> adjList[MAXN];

int nodes, edges, v, u;

bool is_bicolorable(int start)
{
    int color[MAXN];
    fill(color, color + nodes, -1);
    queue<int> q;

    q.push(start);
    color[start] = 0;

    while(!q.empty())
    {
        int node = q.front(); q.pop();
        for(auto child : adjList[node])
        {
            if (color[child] < 0)
            {
                color[child] = 1 - color[node];
                q.push(child);
            }
            else if (color[child] == color[node])
                return false;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    while(cin >> nodes && nodes != 0)
    {
        for(int i = 0; i < nodes; ++i)
            adjList[i].clear();

        cin >> edges;
        for(int i = 0; i < edges; ++i)
        {
            cin >> v >> u;
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        cout << (is_bicolorable(0) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }
}
