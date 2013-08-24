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


list<int> q;
int P, C;
char command;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	int caseNumber = 1;

	while(cin >> P >> C && (P || C) )
	{
		q.clear();

		for(int i = 1; i <= (P <= 1000 ? P : 1000); ++i)
			q.push_back(i);

		printf("Case %d:\n", caseNumber++);
		while(C--)
		{
			cin >> command;
			if (command == 'N')
			{
				cout << q.front() << endl;
				q.push_back(q.front());
				q.pop_front();
			}
			else
			{
				int k;
				cin >> k;

				for(list<int>::iterator it = q.begin(); it != q.end(); ++it)
					if (*it == k)
					{
						q.erase(it);
						break;
					}
				q.push_front(k);
			}
		}
	}
	return 0;
}
