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

const int N = 32;

void createImage(int &index, int x, int y, int size, string &preorder, char image[N][N])
{
	if (index >= preorder.size()) return;

	if (preorder[index] == 'p')
	{
		++index;
		createImage(index, x + size / 2, y, size / 2, preorder, image);
		createImage(index, x, y, size / 2, preorder, image);
		createImage(index, x, y + size / 2, size / 2, preorder, image);
		createImage(index, x + size / 2, y + size / 2, size / 2, preorder, image);
	}
	else
	{
		for(int i = x; i < x + size; ++i)
			for(int j = y; j < y + size; ++j)
				image[i][j] = (preorder[index] == 'f' ? 'f' : 'e');
		++index;
	}
}

void createImage(string &preorder, char image[N][N])
{
	int index = 0;
	createImage(index, 0, 0, N, preorder, image);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	char image1[N][N], image2[N][N];
	string preorder1, preorder2;

	cin >> tests;
	while(tests--)
	{
		memset(image1, ' ', sizeof(image1));
		memset(image2, ' ', sizeof(image2));
		cin >> preorder1 >> preorder2;

		createImage(preorder1, image1);
		createImage(preorder2, image2);

		int answer = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if (image1[i][j] == 'f' || image2[i][j] == 'f')
					++answer;

		printf("There are %d black pixels.\n", answer);
	}
	return 0;
}