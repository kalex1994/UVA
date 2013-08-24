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

struct sheet
{
	pair<int,int> front, back;

	sheet()
	{
		front.first = front.second = -1;
		back.first = back.second = -1;
	}
};

vector<sheet> book;

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int n;
	while(cin >> n && n)
	{
		int pageCount = n / 4 + (n % 4 != 0);
		book.clear();
		book.resize(pageCount);

		int number = 1;
		for(int i = 0; i < pageCount; ++i)
		{
			if (number <= n)
				book[i].front.second = number++;
			if (number <= n)
				book[i].back.first = number++;
		}
		for(int i = pageCount - 1; i >= 0; --i)
		{
			if (number <= n)
				book[i].back.second = number++;
			if (number <= n)
				book[i].front.first = number++;
		}

		printf("Printing order for %d pages:\n",n);
		for(int i = 0; i < pageCount; ++i)
		{
			if (book[i].front.first != 0 || book[i].front.second != 0)
			{
				if (book[i].front.first == -1)
					printf("Sheet %d, front: Blank, %d\n", i + 1, book[i].front.second);
				else
					printf("Sheet %d, front: %d, %d\n",i + 1, book[i].front.first, book[i].front.second);
			}

			if (book[i].back.first == -1 && book[i].back.second == -1) continue;
			if (book[i].back.second == -1)
				printf("Sheet %d, back : %d, Blank\n", i + 1, book[i].back.first);
			else
				printf("Sheet %d, back : %d, %d\n", i + 1, book[i].back.first, book[i].back.second);
		}
	}	
	return 0;
}


