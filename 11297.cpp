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
#include<climits>

using namespace std;

const int MAX_N = 505;

struct Node
{
	int begin, middle, end, minPopulation, maxPopulation;
};

struct SegmentTree
{
	vector<Node> tree;

	inline int leftChild(int node) { return node << 1; }
	inline int rightChild(int node) { return (node << 1) + 1; }

	SegmentTree(int size)
	{
		tree = vector<Node>(size << 2);
	}

	void buildTree(int vertex, int left, int right, int population[])
	{
		tree[vertex].begin = left;
		tree[vertex].middle = (left + right) >> 1;
		tree[vertex].end = right;

		if (left == right)
			tree[vertex].minPopulation = tree[vertex].maxPopulation = population[left];
		else
		{
			int left_child = leftChild(vertex), right_child = rightChild(vertex);
			buildTree(left_child, left, tree[vertex].middle, population);
			buildTree(right_child, tree[vertex].middle + 1, right, population);
			tree[vertex].minPopulation = min(tree[left_child].minPopulation, tree[right_child].minPopulation);
			tree[vertex].maxPopulation = max(tree[left_child].maxPopulation, tree[right_child].maxPopulation);
		}
	}

	void update(int vertex, int left, int right, int value)
	{
		if (tree[vertex].begin > right || tree[vertex].end < left)
			return;

		if (tree[vertex].begin >= left && tree[vertex].end <= right)
			tree[vertex].minPopulation = tree[vertex].maxPopulation = value;
		else
		{
			int left_child = leftChild(vertex), right_child = rightChild(vertex);
			update(left_child, left, right, value);
			update(right_child, left, right, value);
			tree[vertex].minPopulation = min(tree[left_child].minPopulation, tree[right_child].minPopulation);
			tree[vertex].maxPopulation = max(tree[left_child].maxPopulation, tree[right_child].maxPopulation);
		}
	}

	pair<int, int> query(int vertex, int left, int right)
	{
		if (tree[vertex].begin > right || tree[vertex].end < left)
			return make_pair(INT_MAX, INT_MIN);
		if (tree[vertex].begin >= left && tree[vertex].end <= right)
			return make_pair(tree[vertex].minPopulation, tree[vertex].maxPopulation);
		else
		{
			int left_child = leftChild(vertex);
			int right_child = rightChild(vertex);

			pair<int, int> q1 = query(left_child, left, right);
			pair<int, int> q2 = query(right_child, left, right);

			return make_pair(min(q1.first, q2.first), max(q1.second, q2.second)); 
		}
	}
};

struct SegmentTree2D
{
	vector<SegmentTree> trees;

	SegmentTree2D(int N)
	{
		trees.assign(N, SegmentTree(N));
	}

	void buildTree(int N, int population[MAX_N][MAX_N])
	{
		for(int i = 0; i < N; ++i)
			trees[i].buildTree(1, 0, N - 1, population[i]);
	}

	void update(int x, int y, int value)
	{
		trees[x - 1].update(1, y - 1, y - 1, value);
	}

	pair<int, int> query(int x1, int y1, int x2, int y2)
	{
		pair<int, int> answer(INT_MAX, INT_MIN);

		for(int i = x1 - 1; i <= x2 - 1; ++i)
		{
			pair<int, int> result = trees[i].query(1, y1 - 1, y2 - 1);
			answer.first = min(answer.first, result.first);
			answer.second = max(answer.second, result.second);
		}
		return answer;
	}
};

int N, Q, X1, Y1, X2, Y2, x, y, v;
char command;
int population[MAX_N][MAX_N];
SegmentTree2D segment_tree2d(MAX_N);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	scanf("%*d %d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &population[i][j]);

	segment_tree2d.buildTree(N, population);

	scanf("%d", &Q);
	while(Q--)
	{
		cin >> command;
		if (command == 'q')
		{
			scanf("%d%d%d%d",&X1, &Y1, &X2, &Y2);
			pair<int, int> answer = segment_tree2d.query(X1, Y1, X2, Y2);
			printf("%d %d\n", answer.second, answer.first);
		}
		else
		{
			scanf("%d%d%d", &x, &y, &v);
			segment_tree2d.update(x, y, v);
		}
	}
	return 0;
}