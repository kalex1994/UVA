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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string trash;
	int Q_num, Period, K;
	priority_queue< pair<int,int> > queries;
	map<int, int> initial;

	while(cin >> trash && trash[0] != '#')
	{
		cin >> Q_num >> Period;
		initial[Q_num] = Period;
		queries.push( make_pair(-Period, -Q_num) );
	}

	cin >> K;
	while(K--)
	{
		pair<int, int> top = queries.top(); queries.pop();
		queries.push( make_pair(top.first - initial[-top.second], top.second) );
		cout << -top.second << endl;
	}
	return 0;
}
