#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>
#include<cfloat>

using namespace std;

class UnionFind
{
private:
	vector<int> height, parent, setSize;
	int acorns, disjointSets;
public:
	UnionFind(int N)
	{
		height.assign(N, 0);
		setSize.assign(N, 1);
		parent.resize(N);
		for(int i = 0; i < N; ++i)
			parent[i] = i;
		disjointSets = acorns = N;
	}

	inline int findSet(int x)
	{
		return parent[x] == x ? x : (parent[x] = findSet(parent[x]));
	}

	inline bool isSameSet(int x, int y)
	{
		return findSet(x) == findSet(y);
	}

	inline int getAcorns() const
	{
		return acorns;
	}

	inline int getTrees() const
	{
		return disjointSets - acorns;
	}

	void setUnion(int x, int y)
	{
		if (!isSameSet(x, y))
		{
			--disjointSets;
			int r1 = findSet(x), r2 = findSet(y);

			if (setSize[r1] == 1 && setSize[r2] == 1) acorns -= 2;
			else if (setSize[r1] == 1 || setSize[r2] == 1) --acorns;

			if (height[r2] > height[r1])
			{
				parent[r1] = r2;
				setSize[r2] += setSize[r1];
			}
			else
			{
				parent[r2] = r1;
				setSize[r1] += setSize[r2];
				if (height[r1] == height[r2])
					++height[r1];
			}
		}
	}
};

int tests;
vector< pair<char, char> > edges;
map<char, int> nodes;
int countOfNodes;
char buffer[1000], node1, node2;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	scanf("%d%*c", &tests);
	while(tests--)
	{
		edges.clear();
		nodes.clear();

		while(gets(buffer) && buffer[0] != '*')
		{
			sscanf(buffer, "(%c,%c)", &node1, &node2);
			edges.push_back( make_pair(node1, node2) );
		}

		gets(buffer);
		char *token = strtok(buffer, ",");
		countOfNodes = 0;
		while(token != NULL)
		{
			nodes[token[0]] = countOfNodes++;
			token = strtok(NULL, ",");
		}

		UnionFind uf(countOfNodes);
		for(int i = 0; i < (int)edges.size(); ++i)
			uf.setUnion(nodes[edges[i].first], nodes[edges[i].second]);

		printf("There are %d tree(s) and %d acorn(s).\n", uf.getTrees(), uf.getAcorns());
	}
	return 0;
}
