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

#define LEFT(p) (p << 1)
#define RIGHT(p) ((p << 1) + 1)

struct ST_Node
{
	int begin, end, middle, value;
	char spell;
};

struct SegmentTree
{
	vector<ST_Node> nodes;

	SegmentTree(int _size)
	{
		nodes = vector<ST_Node>(_size << 2);
	}

	void init(int index, int left, int right, bool pirates[])
	{
		nodes[index].begin = left;
		nodes[index].middle = (left + right) >> 1;
		nodes[index].end = right;
		nodes[index].spell = ' ';

		int lt = LEFT(index), rt = RIGHT(index);
		if (nodes[index].begin != nodes[index].end)
		{
			init(lt, left, nodes[index].middle, pirates);
			init(rt, nodes[index].middle + 1, right, pirates);
			nodes[index].value = nodes[lt].value + nodes[rt].value;
		}
		else
			nodes[index].value = pirates[ nodes[index].begin ];
	}

	void preparePropagation(int index, char spell)
	{
		if (spell == 'I')
		{
			switch(nodes[index].spell)
			{
			case 'F': nodes[index].spell = 'E'; break;
			case 'E': nodes[index].spell = 'F'; break;
			case ' ': nodes[index].spell = 'I'; break;
			case 'I': nodes[index].spell = ' '; break;
			}
		}
		else nodes[index].spell = spell;
	}

	void propagate(int index)
	{
		switch(nodes[index].spell)
		{
		case 'F': nodes[index].value = nodes[index].end - nodes[index].begin + 1; break;
		case 'E': nodes[index].value = 0; break;
		case 'I': nodes[index].value = nodes[index].end - nodes[index].begin + 1 - nodes[index].value; break;
		default: return;
		}

		preparePropagation(LEFT(index), nodes[index].spell);
		preparePropagation(RIGHT(index), nodes[index].spell);
		nodes[index].spell = ' ';
	}

	void update(int index, int left, int right, char spell)
	{
		if (nodes[index].begin >= left && nodes[index].end <= right)
			preparePropagation(index, spell);
		propagate(index);

		if (right < nodes[index].begin || left > nodes[index].end)
			return;

		int lt = LEFT(index), rt = RIGHT(index);
		if (nodes[index].begin < left || nodes[index].end > right)
		{
			update(lt, left, right, spell);
			update(rt, left, right, spell);
			nodes[index].value = nodes[lt].value + nodes[rt].value;
		}
	}

	int rsq(int index, int left, int right)
	{
		propagate(index);
		int result = 0;
		if (nodes[index].begin >= left && nodes[index].end <= right)
			result = nodes[index].value;
		else if (left > nodes[index].end || right < nodes[index].begin)
			result = 0;
		else
		{
			int lt = LEFT(index), rt = RIGHT(index);
			result = rsq(lt, left, right) + rsq(rt, left, right);
			nodes[index].value = nodes[lt].value + nodes[rt].value;
		}
		return result;
	}
};

const int MAX = 1024002;
bool pirates[MAX];
SegmentTree segment_tree(MAX);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, testCase, M, t, size, length, Q, a, b;
	char buffer[100], c;

	scanf("%d", &tests);
	for(int testCase = 1; testCase <= tests; ++testCase)
	{
		size = 0;

		scanf("%d", &M);
		while(M--)
		{		
			scanf("%d", &t);
			scanf("%s", buffer);
			int length = strlen(buffer);

			while(t--)
				for(int i = 0; i < length; ++i)
				{
					pirates[size] = buffer[i] == '1';
					++size;
				}		
		}

		segment_tree.init(1, 0, size - 1, pirates);
	
		printf("Case %d:\n", testCase);
		int query = 1;

		scanf("%d", &Q);
		while(Q--)
		{
			cin >> c;
			scanf("%d%d", &a, &b);

			if (c == 'S')
				printf("Q%d: %d\n", query++, segment_tree.rsq(1, a, b));
			else
				segment_tree.update(1, a, b, c);			
		}
	}
	return 0;
}