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

vector< set<int> > friends;
set<int> multipleStamps;

int getExhibitionSize()
{
	int size = 0;
	for(int i = 0; i < (int)friends.size(); ++i)
		for(set<int>::iterator it = friends[i].begin(); it != friends[i].end(); ++it)
			if (!multipleStamps.count(*it))
				++size;
	return size;
}

double getPercentage(int f, int size)
{
	int uniqueStamps = 0;
	for(set<int>::iterator it = friends[f].begin(); it != friends[f].end(); ++it)
		if (!multipleStamps.count(*it))
			++uniqueStamps;
	return (double)uniqueStamps * 100.0 / (double)size;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, N, M, stamp, caseNumber = 1;

	cin >> tests;
	while(tests--)
	{
		friends.clear();
		multipleStamps.clear();

		cin >> N;
		while(N--)
		{
			set<int> stamps;

			cin >> M;
			while(M--)
			{
				cin >> stamp;
				stamps.insert(stamp);
			}			
			friends.push_back(stamps);
		}

		for(int i = 0; i < (int)friends.size(); ++i)
			for(set<int>::iterator j = friends[i].begin(); j != friends[i].end(); ++j)
			{
				int count = 0;
				for(int k = 0; k < (int)friends.size(); ++k)
					if (friends[k].count(*j))
						++count;

				if (count > 1)
					multipleStamps.insert(*j);
			}

		int exhibitionSize = getExhibitionSize();

		printf("Case %d:",caseNumber++);
		for(int i = 0; i < (int) friends.size(); ++i)
			printf(" %0.6lf%c", getPercentage(i, exhibitionSize), '%');
		cout << endl;	
	}
	return 0;
}
