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
	int teamNumber, hour, minute;
	char problemLetter;
	bool accapted;

	InputData(string &raw_data)
	{
		string raw_time;
		char status;
		istringstream(raw_data) >> teamNumber >> problemLetter >> raw_time >> status;
		sscanf(raw_time.c_str(), "%d:%d", &hour, &minute);
		accapted = status == 'Y';
	}
};

bool operator<(const InputData &a, const InputData &b)
{
	if (a.hour != b.hour) return a.hour < b.hour;
	if (a.minute != b.minute) return a.minute < b.minute;
	if (!a.accapted && b.accapted) return true;
	return false;
}

struct Problem
{
	bool solved;
	int recejtedRuns, timeConsumed;

	Problem() : solved(false), recejtedRuns(0), timeConsumed(0) {};

	void assign(int hour, int minute, bool accapted)
	{
		if (solved) return;
		if (accapted)
		{
			solved = true;
			timeConsumed = hour * 60 + minute + recejtedRuns * 20;
		}
		else
			++recejtedRuns;	
	}
};

struct Team
{
	int teamNumber, rank;
	int problemsSolved, timeConsumed;
	Problem problems[256];

	Team() : teamNumber(0) {};

	void process()
	{
		timeConsumed = 0;
		for(int i = 0; i < 256; ++i)
			if (problems[i].solved)
				timeConsumed += problems[i].timeConsumed;

		problemsSolved = 0;
		for(int i = 0; i < 256; ++i)
			if (problems[i].solved)
				++problemsSolved;
	}

	void clear(int _teamNumber)
	{
		this->teamNumber = _teamNumber;
		for(int i = 0; i < 256; ++i)
			problems[i] = Problem();
	}

	bool equals(Team &other)
	{
		return problemsSolved == other.problemsSolved && timeConsumed == other.timeConsumed;
	}
};

bool operator<(const Team &a, const Team &b)
{
	if (a.problemsSolved != b.problemsSolved) return a.problemsSolved > b.problemsSolved;
	if (a.timeConsumed != b.timeConsumed) return a.timeConsumed < b.timeConsumed;
	return a.teamNumber < b.teamNumber;
}

vector<InputData> submissions;
Team teams[30];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;
	string raw_data;

	cin >> tests; 
	cin.ignore(100, '\n');
	cin.ignore(100, '\n');

	while(tests--)
	{
		submissions.clear();
		for(int i = 1; i < 30; ++i)
			teams[i].clear(i);

		while(getline(cin, raw_data) && !raw_data.empty())
			submissions.push_back( InputData(raw_data) );

		sort(submissions.begin(), submissions.end());

		int maxTeamNumber = 0;
		for(int i = 0; i < (int)submissions.size(); ++i)
		{
			teams[ submissions[i].teamNumber ].problems[ submissions[i].problemLetter ].assign(submissions[i].hour,
			submissions[i].minute, submissions[i].accapted);

			if (submissions[i].teamNumber > maxTeamNumber)
				maxTeamNumber = submissions[i].teamNumber;
		}

		for(int i = 1; i <= maxTeamNumber; ++i)
			teams[i].process();

		sort(teams + 1, teams + maxTeamNumber + 1);

		cout << "RANK TEAM PRO/SOLVED TIME" << endl;
		for(int i = 1; i <= maxTeamNumber; ++i)
		{
			if (i > 1 && teams[i].equals(teams[i-1]))
				teams[i].rank = teams[i - 1].rank;
			else
				teams[i].rank = i;

			printf("%4d%5d", teams[i].rank, teams[i].teamNumber);

			if (teams[i].problemsSolved == 0)
				cout << endl;
			else
			{
				printf("%5d%11d\n", teams[i].problemsSolved, teams[i].timeConsumed);
			}
		}
		if (tests)
			cout << endl;
	}
	return 0;
}
