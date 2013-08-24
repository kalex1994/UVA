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
	vector<int> money;

	UnionFind(int n)
	{
		height.assign(n, 0);
		money.assign(n, 0);
		parent.resize(n);
		for(int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int findSet(int x)
	{
		return parent[x] == x ? x : (parent[x] = findSet(parent[x]));
	}

	bool isSameSet(int x, int y)
	{
		return findSet(x) == findSet(y);
	}

	void setMoney(int index, int m)
	{
		money[index] = m;
	}

	void setUnion(int x, int y)
	{
		if (!isSameSet(x, y))
		{
			int s1 = findSet(x), s2 = findSet(y);
			if (height[s2] > height[s1])
			{
				parent[s1] = s2;
				money[s2] += money[s1];
				money[s1] = 0;
			}
			else
			{
				parent[s2] = s1;
				money[s1] += money[s2];
				money[s2] = 0;
				if (height[s1] == height[s2])
					++height[s1];
			}
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, n, m, money, friend1, friend2;

	cin >> tests;
	while(tests--)
	{
		cin >> n >> m;

		UnionFind ufds(n);

		for(int i = 0; i < n; ++i)
		{
			cin >> money;
			ufds.setMoney(i, money);
		}

		while(m--)
		{
			cin >> friend1 >> friend2;
			ufds.setUnion(friend1, friend2);
		}

		bool possible = true;
		for(int i = 0; i < (int)ufds.money.size(); ++i)
			if (ufds.money[i] != 0)
			{
				possible = false;
				break;
			}

		if (possible) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
