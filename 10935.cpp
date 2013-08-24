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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	deque<int> deck;
	int n;
	bool isFirst;

	while(cin >> n, n)
	{
		for(int i = 1; i <= n; ++i)
			deck.push_back(i);

		isFirst = true;

		cout << "Discarded cards:";
		while(deck.size() != 1)
		{
			if (isFirst) 
			{
				cout << " ";
				isFirst = false;
			}
			else cout << ", ";
			cout << deck.front();

			deck.pop_front();
			deck.push_back(deck.front());
			deck.pop_front();
		}
		cout << endl;
		cout << "Remaining card: " << deck.front() << endl;
		deck.pop_front();
	}
	return 0;
}
