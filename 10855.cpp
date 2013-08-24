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

struct square
{
	int size;
	char **matrix;

	square(int n)
	{
		this->size = n;
		matrix = new char*[size];
		for(int i = 0; i < size; ++i)
			matrix[i] = new char[size];
	}

	void rotate()
	{
		char **temp = new char*[size];
		for(int i = 0; i < size; ++i)
			temp[i] = new char[size];

		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
				temp[i][j] = matrix[size - j - 1][i];

		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
				matrix[i][j] = temp[i][j];

		for(int i = 0; i < size; ++i)
			delete [] temp[i];
		delete [] temp;
	}

	~square()
	{
		for(int i = 0; i < size; ++i)
			delete [] matrix[i];
		delete [] matrix;
	}	
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int N, n;
	char ch;

	while(cin >> N >> n && (N || n))
	{
		square big(N);
		square small(n);

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
			{
				cin >> ch;
				big.matrix[i][j] = ch;
			}
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				cin >> ch;
				small.matrix[i][j] = ch;
			}

		int rotations[4] = {0};
		for(int rotation = 0; rotation < 4; ++rotation)
		{
			if (rotation > 0)
				small.rotate();

			for(int i = 0; i <= N - n; ++i)
				for(int j = 0; j <= N - n; ++j)
				{
					bool equal = true;
					for(int k = 0; k < n && equal; ++k)
						for(int m = 0; m < n && equal; ++m)
							if (big.matrix[i + k][j + m] != small.matrix[k][m])
								equal = false;
					if (equal)
						++rotations[rotation];
				}
		}

		for(int i = 0; i < 4; ++i)
		{
			if (i > 0) putchar(' ');
			printf("%d", rotations[i]);
		}
		putchar('\n');
	}
	return 0;
}
