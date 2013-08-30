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

class SegmentTree
{
private:
	vector<int> data, tree;
	int n;

	inline int leftChild(int parent)
	{
		return parent << 1;
	}

	inline int rightChild(int parent)
	{
		return (parent << 1) + 1;
	}

	void build(int parent, int left, int right)
	{
		if (left == right)
			tree[parent] = data[left];
		else
		{
			build(leftChild(parent), left, (left + right) / 2);
			build(rightChild(parent), (left + right) / 2 + 1, right);
			tree[parent] = tree[leftChild(parent)] + tree[rightChild(parent)];
		}
	}

	int RSQ(int parent, int left, int right, int i, int j)
	{
		if (right < i || left > j) return -1;
		if (left >= i && right <= j) return tree[parent];

		int sum1 = RSQ(leftChild(parent), left, (left + right) / 2, i , j);
		int sum2 = RSQ(rightChild(parent), (left + right) / 2 + 1, right, i , j);

		if (sum1 == -1) return sum2;
		if (sum2 == -1) return sum1;

		return sum1 + sum2;
	}

	void update(int parent, int left, int right, int index, int new_value)
	{
		if (left == index && index == right)
		{
			data[index] = new_value;
			tree[parent] = new_value;
			return;
		}

		if (index <= (left + right) / 2)
			update(leftChild(parent), left, (left + right) / 2, index, new_value );
		else
			update(rightChild(parent), (left + right) / 2 + 1, right, index, new_value );

		tree[parent] = tree[leftChild(parent)] + tree[rightChild(parent)];	
	}

public:
	SegmentTree(vector<int> &_data)
	{
		this->data = _data;
		n = _data.size();
		tree.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	int RSQ(int i, int j)
	{
		return RSQ(1, 0, n - 1, i, j);
	}

	void update(int index, int new_value)
	{
		update(1, 0, n - 1, index, new_value);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int N, x, y, caseNumber = 1;
	bool isFirst = true;
	char action[100];
	vector<int> potmeters;

	while(scanf("%d", &N) && N)
	{
		potmeters.resize(N);
		for(int i = 0; i < N; ++i)
			scanf("%d", &potmeters[i]);

		SegmentTree st(potmeters);

		if (isFirst) isFirst = false;
		else putchar('\n');
		printf("Case %d:\n", caseNumber++);

		while(scanf("%s", action) && action[0] != 'E' )
		{
			scanf("%d %d", &x, &y);

			if (action[0] == 'S')
				st.update(x - 1, y);
			else
				printf("%d\n", st.RSQ(x - 1, y - 1));
		}
	}
	return 0;
}
