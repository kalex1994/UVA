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

#define rep(i,n) for(int i = 0; i < (int)n; ++i)

int tests;
int card[5][5];
int numbers[75];
bool isChecked[5][5];
bool hadFreeNumber;

bool mark(int n)
{
	rep(i,5)
		rep(j,5)
		    if (card[i][j] == n)
			{
				isChecked[i][j] = true;
				return true;
			}
	return false;
}

bool isBingo()
{
	rep(i,5)
	{
		int count = 0;
		rep(j,5)
			if (isChecked[i][j])
				++count;
		if (count == 5)
			return true;
	}
	rep(j,5)
	{
		int count = 0;
		rep(i,5)
			if (isChecked[i][j])
				++count;
		if (count == 5)
			return true;
	}
	int count = 0;
	rep(i,5)
		rep(j,5)
		    if(i == j)
			{
				if (isChecked[i][j])
					++count;
			}
	if (count == 5)
		return true;
	count = 0;
	rep(i,5)
		rep(j,5)
		    if (i + j == 4)
			{
				if (isChecked[i][j])
					++count;
			}
	if (count == 5)
		return true;

	return false;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	cin >> tests;
	while(tests--)
	{
		memset(isChecked,false,sizeof(isChecked));

		card[2][2] = 0;
		rep(i,5)
			if (i == 2)
				cin >> card[i][0] >> card[i][1] >> card[i][3] >> card[i][4];
			else rep(j,5)
				cin >> card[i][j];

		rep(i,75)
			cin >> numbers[i];

		int num = 0;
		rep(i,75)
		{
			if (!mark(numbers[i]))
				isChecked[2][2] = true;
			++num;

			if (isBingo())
			{
				printf("BINGO after %d numbers announced\n",num);
				break;
			}
		}
	}
	return 0;
}


