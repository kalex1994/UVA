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
#include<climits>

using namespace std;

struct Job
{
	int priority;
	bool myJob;

	Job(int _priority, bool _myJob)
	{
		this->priority = _priority;
		this->myJob = _myJob;
	}
};

list<Job> jobs;
int n, m, priority, minutes;

int getMaxPriority()
{
	int max = 0;
	for(list<Job>::iterator it = jobs.begin(); it != jobs.end(); ++it)
	{
		if(it->priority > max)
			max = it->priority;
	}
	return max;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;

	cin >> tests;
	while(tests--)
	{
		jobs.clear();
		cin >> n >> m;

		for(int i = 0; i < n; ++i)
		{
			cin >> priority;
			jobs.push_back(Job(priority, i == m));
		}

		minutes = 0;
		while(true)
		{
			if (jobs.front().priority == getMaxPriority())
			{
				++minutes;			
				if (jobs.front().myJob)
					 break;			
			}
			else		
				jobs.push_back(jobs.front());

			jobs.pop_front();		
		}
		cout << minutes << endl;
	}	
	return 0;
}