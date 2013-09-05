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

const int MAX = 100005;
const int ZERO = 0;
const int POSITIVE = 1;
const int NEGATIVE = -1;
const int NONE = 2;

inline int leftChild(int node) { return node << 1; }
inline int rightChild(int node) { return (node << 1) + 1; }

struct Node
{
	int begin, end, middle, value;
};

struct SegmentTree
{
	vector<Node> tree;

	SegmentTree(int size)
	{
		tree = vector<Node>(size << 2);
	}

	int getSign(int value)
	{
		if (value == 0) return ZERO;
		if (value > 0) return POSITIVE;
		return NEGATIVE;
	}

	int determineSign(int sign1, int sign2)
	{
		if (sign1 == NONE) return sign2;
		if (sign2 == NONE) return sign1;
		if (sign1 == ZERO || sign2 == ZERO) return ZERO;
		if (sign1 == NEGATIVE && sign2 == NEGATIVE) return POSITIVE;
		if (sign1 == NEGATIVE || sign2 == NEGATIVE) return NEGATIVE;
		return POSITIVE;
	}

	void buildTree(int vertex, int left, int right, int values[])
	{
		tree[vertex].begin = left;
		tree[vertex].middle = (left + right) >> 1;
		tree[vertex].end = right;

		if (left == right)
			tree[vertex].value = getSign(values[left]);
		else
		{
			int left_child = leftChild(vertex), right_child = rightChild(vertex);
			buildTree(left_child, left, tree[vertex].middle, values);
			buildTree(right_child, tree[vertex].middle + 1, right, values);
			tree[vertex].value = determineSign(tree[left_child].value, tree[right_child].value);
		}
	}

	void update(int vertex, int left, int right, int value)
	{
		if (tree[vertex].begin > right || tree[vertex].end < left)
			return;

		if (tree[vertex].begin >= left && tree[vertex].end <= right)
			tree[vertex].value = getSign(value);
		else
		{
			int left_child = leftChild(vertex), right_child = rightChild(vertex);
			update(left_child, left, right, value);
			update(right_child, left, right, value);
			tree[vertex].value = determineSign(tree[left_child].value, tree[right_child].value);
		}
	}

	int query(int vertex, int left, int right)
	{
		if (tree[vertex].begin > right || tree[vertex].end < left)
			return NONE;
		if (tree[vertex].begin >= left && tree[vertex].end <= right)
			return tree[vertex].value;

		int q1 = query(leftChild(vertex), left, right);
		int q2 = query(rightChild(vertex), left, right);
		return determineSign(q1, q2);
	}
};

int values[MAX], N, K, a, b;
char command;
SegmentTree segment_tree(MAX);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while( scanf("%d %d", &N, &K) == 2 )
	{
		for(int i = 0; i < N; ++i)
			cin >> values[i];

		segment_tree.buildTree(1, 0, N - 1, values);

		while(K--)
		{
			cin >> command;
			scanf("%d%d", &a, &b);
			if (command == 'C')
				segment_tree.update(1, a - 1, a - 1, b);
			else
			{
				int result = segment_tree.query(1, a - 1, b- 1);
				if (result == ZERO) putchar('0');
				else if (result == POSITIVE) putchar('+');
				else putchar('-');
			}
		}
		putchar('\n');
	}
	return 0;
}