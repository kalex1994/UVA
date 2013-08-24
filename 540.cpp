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

list< queue<int> > teamQueue;
vector< set<int> > teams;
string command;
int t, teamCount, num, scenario = 1;

void enqueue(int x)
{
	int i;
	for(i = 0; i < (int)teams.size(); ++i)
		if (teams[i].count(x))
			break;

	bool found = false;
	for(list< queue<int> >::iterator it = teamQueue.begin(); it != teamQueue.end(); ++it)
		if (teams[i].count(it->front()))
		{
			found = true;
			it->push(x);
			break;
		}

	if (!found)
	{
		teamQueue.push_back(queue<int>());
		teamQueue.back().push(x);
	}
}

int dequeue()
{
	if (teamQueue.front().empty()) teamQueue.pop_front();
	int ret = teamQueue.front().front();
	teamQueue.front().pop();
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> t && t)
	{
		teams.clear();
		teamQueue.clear();

		while(t--)
		{
			set<int> team;	
			cin >> teamCount;
			while(teamCount--)
			{
				cin >> num;
				team.insert(num);
			}
			teams.push_back(team);
		}

		printf("Scenario #%d\n",scenario++);
		while(cin >> command && command[0] != 'S')
		{
			if (command[0] == 'E')
			{
				cin >> num;
				enqueue(num);
			}
			else
				cout << dequeue() << endl;
		}
		cout << endl;
	}
	return 0;
}




