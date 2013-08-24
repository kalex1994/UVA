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

using namespace std;

int matrix[15][15];
int n;

void transpose()
{
	int temp[15][15];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			temp[j][i] = matrix[i][j];

	memcpy(matrix, temp, sizeof(matrix));
}

void swaprows(int a, int b)
{
	--a; --b;
	for(int j = 0; j < n; ++j)
		swap(matrix[a][j], matrix[b][j]);
}

void swapcols(int a, int b)
{
	--a; --b;
	for(int i = 0; i < n; ++i)
		swap(matrix[i][a], matrix[i][b]);
}

void inc()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			matrix[i][j] = ( matrix[i][j] + 1 ) % 10;
}

void dec()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			matrix[i][j] = (matrix[i][j] + 9) % 10;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	int tests, m, a, b, caseNumber = 1;
	char ch;
	string command;

	cin >> tests;
	while(tests--)
	{
		cin >> n;

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				cin >> ch;
				matrix[i][j] = ch - '0';
			}

		cin >> m;
		while(m--)
		{
			cin >> command;
			if (command[0] == 't') transpose();
			else if (command[0] == 'i') inc();
			else if (command[0] == 'd') dec();
			else
			{
				cin >> a >> b;
				if (command[0] == 'r') swaprows(a, b);
				else swapcols(a, b);
			}
		}

		printf("Case #%d\n", caseNumber++);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cout << matrix[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}




