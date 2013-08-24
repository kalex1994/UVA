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

int candidates;
vector<string> names;
vector< vector<int> > ballots;
bool isEliminated[25];
int votes[25];

int hasWinner()
{
	for(int i = 1; i <= candidates; ++i)
		if (!isEliminated[i] && votes[i] > ballots.size() / 2)
			return i;
	return 0;
}

bool allCandidatesTied(int minVotes)
{
	for(int i = 1; i <= candidates; ++i)
		if (!isEliminated[i])
			if (votes[i] != minVotes)
				return false;
	return true;
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	int tests;
	string line;

	cin >> tests;
	while(tests--)
	{
		names.clear(); ballots.clear();

		cin >> candidates; getline(cin,line);
		for(int i = 0; i < candidates; ++i)
		{
			string name;
			getline(cin,name);
			names.push_back(name);
		}

		while(getline(cin,line) && !line.empty())
		{
			vector<int> ballot;
			int vote;
			istringstream iss(line);
			while(iss >> vote)
				ballot.push_back(vote);
			ballots.push_back(ballot);
		}

		memset(votes,0,sizeof(votes));
		for(int i = 0; i < ballots.size(); ++i)
			++votes[ ballots[i].front() ];

		if (hasWinner())
			cout << names[hasWinner() - 1] << endl;
		else
		{
			memset(isEliminated,false,sizeof(isEliminated));
			while(true)
			{
				int minVotes = 9999999;
				for(int i = 1; i <= candidates; ++i)
					if (!isEliminated[i] && votes[i] < minVotes)
						minVotes = votes[i];
				if (hasWinner())
				{
					cout << names[hasWinner() - 1] << endl;
					break;
				}
				if (allCandidatesTied(minVotes))
				{
					for(int i = 1; i <= candidates; ++i)
						if (!isEliminated[i])
							cout << names[i-1] << endl;
					break;
				}

				for(int i = 1; i <= candidates; ++i)
					if (!isEliminated[i] && votes[i] == minVotes)
					{
						isEliminated[i] = true;
						for(int j = 0; j < ballots.size(); ++j)
							if (ballots[j].front() == i)
							{
								while(isEliminated[ballots[j].front()] || votes[ballots[j].front()] == minVotes)
									ballots[j].erase(ballots[j].begin());
								if (!isEliminated[ ballots[j].front() ])
									++votes[ ballots[j].front() ];
							}
					}
			}
		}
		if (tests) cout << endl;
	}
	return 0;
}


