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

string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
map<string, int> m;

int countLeapYears(int year)
{
	return (year / 4) - (year / 100) + (year / 400);
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	for(int i = 0; i < 12; ++i)
		m[ months[i] ] = i + 1;

	int testCases, m1, d1, y1, m2, d2, y2;
	string temp;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		cin >> temp;
		m1 = m[temp];
		scanf("%d, %d%*c",&d1,&y1);

		cin >> temp;
		m2 = m[temp];
		scanf("%d, %d%*c",&d2,&y2);

		if (m1 > 2) ++y1;
		if (m2 < 2 || (m2 == 2 && d2 < 29) )
			--y2;

		printf("Case %d: %d\n",t, countLeapYears(y2) - countLeapYears(y1) + (isLeapYear(y1) ? 1 : 0) );
	}	
	return 0;
}


