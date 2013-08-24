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
	UnionFind(int N)
	{
		height.assign(N, 0);
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
				parent[r2] = r1;
			else
			{
				parent[r1] = r2;
				if (height[r1] == height[r2])
					++height[r2];
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

	int tests, N, computer1, computer2, successfull, unsuccessfull;
	char ch;
	string line;

	cin >> tests; cin.ignore(100, '\n'); getline(cin, line);
	while(tests--)
	{
		cin >> N; cin.ignore(100, '\n');
		UnionFind ufsd(N);

		successfull = unsuccessfull = 0;
		while(getline(cin, line) && !line.empty())
		{
			istringstream iss(line);
			iss >> ch >> computer1 >> computer2;

			if (ch == 'c')
				ufsd.setUnion(computer1 - 1, computer2 - 1);
			else 
			{
				if (ufsd.isSameSet(computer1 - 1, computer2 - 1)) 
					++successfull;
				else 
					++unsuccessfull;
			}
		}
		cout << successfull << "," << unsuccessfull << endl;
		if (tests) cout << endl;
	}
	return 0;
}
