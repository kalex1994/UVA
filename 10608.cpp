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
	vector<int> height, parent;
public:
	vector<int> size;

	UnionFind(int N)
	{
		height.assign(N, 0);
		size.assign(N, 1);
		parent.resize(N);
		for(int i = 0; i < N; ++i)
			parent[i] = i;
	}

	inline int findSet(int x)
	{
		return parent[x] == x ? x : (parent[x] = findSet(parent[x]));
	}

	inline bool isSameSet(int x, int y)
	{
		return findSet(x) == findSet(y);
	}

	void setUnion(int x, int y)
	{
		if (!isSameSet(x, y))
		{
			int r1 = findSet(x);
			int r2 = findSet(y);

			if (height[r1] > height[r2])
			{
				parent[r2] = r1;
				size[r1] += size[r2];
			}
			else
			{
				parent[r1] = r2;
				if (height[r1] == height[r2])
					++height[r2];
				size[r2] += size[r1];
			}
		}
	}

	int getSize(int x)
	{
		return size[findSet(x)];
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, N, M, A, B;

	cin >> tests;
	while(tests--)
	{
		cin >> N >> M;
		UnionFind ufds(N);

		while(M--)
		{
			cin >> A >> B;
			ufds.setUnion(A - 1, B - 1);
		}

		int max = 0;
		for(int i = 0; i < N; ++i)
			if (ufds.size[i] >  max)
				max = ufds.size[i];

		cout << max << endl;
	}
	return 0;
}
