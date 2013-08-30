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

struct InputData
{
	int contestantNumber, problemNumber, time;
	char status;

	InputData(string &raw_data)
	{
		istringstream (raw_data) >> contestantNumber >> problemNumber>> time >> status; 
	}
};

bool operator<(const InputData &a, const InputData &b)
{
	if (a.time != b.time) return a.time < b.time;
	if (a.status == 'I') return true;
	return false;
}

struct Problem
{
	bool solved;
	int incorrectRuns, penaltyTime;

	Problem() : solved(false), incorrectRuns(0), penaltyTime(0) {};

	void assign(int time, char status)
	{
		if (solved) return;
		if (status == 'C')
		{
			solved = true;
			penaltyTime = time + incorrectRuns * 20;
		}
		else if (status == 'I')
			++incorrectRuns;
	}
};

struct Contestant
{
	Problem problems[10];
	int problemsSolved, timeConsumed, contestantNumber;

	Contestant() : problemsSolved(0), timeConsumed(0), contestantNumber(0) {};

	void process()
	{
		problemsSolved = timeConsumed = 0;
		for(int i = 1; i <= 9; ++i)
			if (problems[i].solved)
			{
				++problemsSolved;
				timeConsumed += problems[i].penaltyTime;
			}
	}
};

bool operator<(const Contestant &a, const Contestant &b)
{
	if (a.problemsSolved != b.problemsSolved) return a.problemsSolved > b.problemsSolved;
	if (a.timeConsumed != b.timeConsumed) return a.timeConsumed < b.timeConsumed;
	return a.contestantNumber < b.contestantNumber;
}

map<int, Contestant> contestants;
vector<InputData> submissions;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	string line;

	cin >> tests;
	cin.ignore(100, '\n');
	cin.ignore(100, '\n');

	while(tests--)
	{
		contestants.clear();
		submissions.clear();

		while(getline(cin, line) && !line.empty())
			submissions.push_back( InputData(line) );
		sort(submissions.begin(), submissions.end());

		for(int i = 0; i < (int)submissions.size(); ++i)
		{
			contestants[ submissions[i].contestantNumber ].contestantNumber = submissions[i].contestantNumber;
			contestants[ submissions[i].contestantNumber ].problems[ submissions[i].problemNumber ].assign(submissions[i].time, 
			    submissions[i].status);
		}

		vector<Contestant> answer;
		for(map<int, Contestant>::iterator it = contestants.begin(); it != contestants.end(); ++it)
		{
			it->second.process();
			answer.push_back(it->second);
		}

		sort(answer.begin(), answer.end());

		for(int i = 0; i < (int)answer.size(); ++i)
			cout << answer[i].contestantNumber << " " << answer[i].problemsSolved << " " << answer[i].timeConsumed << endl;
		if (tests) cout << endl;
	}
	return 0;
}
