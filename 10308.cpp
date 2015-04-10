#include<bits/stdc++.h>
using namespace std;

const int MAXN  = 10005;
vector<pair<int,int>> adjList[MAXN];
int n;
int distTo[MAXN];

bool readInput()
{
    char line[100];
    bool end_of_input = false;
    n = 0;
    while(true)
    {
        if (!gets(line))
        {
            end_of_input = true;
            break;
        }
        if (strlen(line) == 0)
            break;
        int v1, v2, weight;
        ++n;
        sscanf(line, "%d %d %d", &v1, &v2, &weight);
        --v1; --v2;
        adjList[v1].push_back(make_pair(v2, weight));
        adjList[v2].push_back(make_pair(v1, weight));
    }
    ++n;
    return end_of_input;
}

void clean()
{
    for(int i = 0; i < n; ++i)
        adjList[i].clear();
}

void dfs(int v)
{
    for(auto edge : adjList[v])
        if (distTo[edge.first] == INT_MAX)
        {
            distTo[edge.first] = distTo[v] + edge.second;
            dfs(edge.first);
        }
}

void DFS(int v)
{
    fill(distTo, distTo + n, INT_MAX);
    distTo[v] = 0;
    dfs(v);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    bool end_of_input = false;
    do
    {
        end_of_input = readInput();
        DFS(0);
        int farest = distance(distTo, max_element(distTo, distTo + n));
        DFS(farest);
        printf("%d\n", *max_element(distTo, distTo + n));
        clean();
    }while(!end_of_input);
}
