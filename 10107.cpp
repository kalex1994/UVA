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

list<int> numbers;
int x;

void insert()
{
	list<int>::iterator it = numbers.begin();
	while(it != numbers.end() && x > *it)
		++it;	
	numbers.insert(it,x);
}

int getMedian()
{
	int median = 0;
	int current = 0;
	int count = (int)numbers.size() / 2 - (numbers.size() % 2 == 0 ? 1 : 0) ;
	list<int>::iterator it = numbers.begin();

	while(current != count)
	{
		++current;
		++it;
	}

	median = *it;
	if (numbers.size() % 2 == 0)
	{
		++it;
		median += *it;
		median /= 2;
	}
	return median;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> x)
	{
		insert();
		cout << getMedian() << endl;
	}
	return 0;
}


