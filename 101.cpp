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

enum ACTION {ONTO, OVER};
vector< vector<int> > blockworld;
vector< int > currentBlock;
int N, a, b;
string s1, s2;

void init()
{
	for(int i = 0; i < N; ++i)
	{
		blockworld.push_back( vector<int>() );
		blockworld.back().push_back(i);

		currentBlock.push_back(i);
	}
}

void moveToInitialPositionAboveBlock(int block)
{
	int curr_block = currentBlock[block];

	while(blockworld[curr_block].back() != block)
	{
		int temp = blockworld[curr_block].back();
		blockworld[curr_block].pop_back();
		currentBlock[temp] = temp;
		blockworld[temp].push_back(temp);
	}
}

void move(int a, int b, ACTION action)
{
	int blockof_a = currentBlock[a], blockof_b = currentBlock[b];
	if (blockof_a == blockof_b)
		return;

	moveToInitialPositionAboveBlock(a);
	if (action == ONTO)
		moveToInitialPositionAboveBlock(b);

	blockworld[ blockof_b ].push_back(a);
	currentBlock[a] = blockof_b;
	blockworld[ blockof_a ].pop_back();
}

void pile(int a, int b, ACTION action)
{
	int blockof_a = currentBlock[a], blockof_b = currentBlock[b];
	if (blockof_a == blockof_b)
		return;

	if (action == ONTO)
		moveToInitialPositionAboveBlock(b);
	stack<int> blocks;

	while(blockworld[blockof_a].back() != a)
	{
		int temp = blockworld[blockof_a].back();
		blockworld[blockof_a].pop_back();
		blocks.push(temp);
	}
	blocks.push(a);
	blockworld[blockof_a].pop_back();

	while(!blocks.empty())
	{
		int temp = blocks.top();
		blocks.pop();
		currentBlock[temp] = blockof_b;
		blockworld[blockof_b].push_back(temp);
	}
}

void print()
{
	for(int i = 0; i < (int)blockworld.size(); ++i)
	{
		cout << i << ":";
		for(int j = 0; j < (int)blockworld[i].size(); ++j)
			cout << " " << blockworld[i][j];
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	cin >> N;
	init();

	while(cin >> s1 && s1 != "quit")
	{
		cin >> a >> s2 >> b;

		if (s1 == "move")
		{
			if (s2 == "onto") move(a, b, ONTO);
			else move(a, b, OVER);
		}
		else
		{
			if (s2 == "onto") pile(a, b, ONTO);
			else pile(a, b, OVER);
		}
	}
	print();
	return 0;
}