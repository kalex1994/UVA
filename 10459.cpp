#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
vector<int> adjList[MAXN];
int n;
int distTo[MAXN];
int edgeTo[MAXN];

bool readTestCase()
{
    if (scanf("%d", &n) != 1)
        return false;

    for(int i = 0; i < n; ++i)
        adjList[i].clear();

    int k, neighbour;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &k);
        for(int j = 0; j < k; ++j)
        {
            scanf("%d", &neighbour);
            adjList[i].push_back(neighbour - 1);
        }
    }
    return true;
}

void bfs(int start)
{
    fill(distTo, distTo + n, INT_MAX);

    queue<int> q;
    q.push(start);
    distTo[start] = 0;
    edgeTo[start] = -1;

    while(!q.empty())
    {
        int v = q.front(); q.pop();

        for(auto neighbour : adjList[v])
            if (distTo[neighbour] == INT_MAX)
            {
                distTo[neighbour] = distTo[v] + 1;
                edgeTo[neighbour] = v;
                q.push(neighbour);
            }
    }
}

void solve()
{
    set<int> best_nodes, worst_nodes;

    bfs(0);
    int farest_node = distance(distTo, max_element(distTo, distTo + n));

    for(int i = 0; i < n; ++i)
        if (distTo[i] == distTo[farest_node])
            worst_nodes.insert(i);

    bfs(farest_node);

    int max_dist = *max_element(distTo, distTo + n);
    for(int i = 0; i < n; ++i)
    {
        if(distTo[i] == max_dist )
        {
            worst_nodes.insert(i);

            vector<int> path;
            for(int v = i; v != -1; v = edgeTo[v])
                path.push_back(v);

            int size = path.size();
            if (size % 2 == 1)
                best_nodes.insert(path[size / 2]);
            else
            {
                best_nodes.insert(path[size / 2 - 1]);
                best_nodes.insert(path[size / 2]);
            }
        }
    }

    printf("Best Roots  :");
    for (auto v : best_nodes)
        printf(" %d", v + 1);
    printf("\nWorst Roots :");
    for (auto v : worst_nodes)
        printf(" %d", v + 1);
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    while(readTestCase())
        solve();
}
