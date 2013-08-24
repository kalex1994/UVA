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

int candidates, voters;
vector< vector<int> > ballots;
int invalidBallots;
bool isEliminated[10];
int votes[10];

int getMinVotes()
{
	int minVotes = 999999999;
	for(int i = 1; i <= candidates; ++i)
		if (!isEliminated[i])
			if (votes[i] < minVotes)
				minVotes = votes[i];
	return minVotes;
}

int hasWinner()
{
	for(int i = 1; i <= candidates; ++i)
		if (!isEliminated[i])
			if (votes[i] > ballots.size() / 2)
				return i;
	return 0;
}

bool isAllCandidatesTied()
{
	int minVotes = getMinVotes();
	for(int i = 1; i <= candidates; ++i)
		if (!isEliminated[i])
			if(votes[i] != minVotes)
				return false;
	return true;
}

bool isValidBallot(vector<int> &ballot)
{
	set<int> votes;
	for(int i = 0; i < (int)ballot.size(); ++i)
	{
		if (ballot[i] < 1 || ballot[i] > candidates) return false;
		if (votes.count(ballot[i]))
			return false;
		votes.insert(ballot[i]);
	}
	return true;
}

int removeInvalidBallots()
{
	int count = 0;
	for(int i = ballots.size() - 1; i >= 0; --i)
		if (!isValidBallot(ballots[i]))
		{
			ballots.erase(ballots.begin() + i);
			++count;
		}
	return count;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int election = 1;

	while(cin >> candidates >> voters && (candidates || voters))
	{
		ballots.clear();

		printf("Election #%d\n",election++);

		for(int i = 0; i < voters; ++i)
		{
			vector<int> ballot;
			for(int j = 0; j < candidates; ++j)
			{
				int vote;
				cin >> vote;
				ballot.push_back(vote);
			}
			ballots.push_back(ballot);
		}

		invalidBallots = removeInvalidBallots();
		if (invalidBallots > 0)
			printf("   %d bad ballot(s)\n",invalidBallots);

		memset(votes,0,sizeof(votes));
		for(int i = 0; i < (int)ballots.size(); ++i)
			++votes[ ballots[i].front() ];

		memset(isEliminated,false,sizeof(isEliminated));
		while(true)
		{
			int minVotes = getMinVotes();

			for(int i = 1; i <= candidates; ++i)
				if (!isEliminated[i] && votes[i] == minVotes)
				{
					isEliminated[i] = true;

					for(int j = 0; j < (int)ballots.size(); ++j)
						if (!ballots[j].empty() && ballots[j].front() == i)
						{
							while(!ballots[j].empty() && isEliminated[ballots[j].front()])
								ballots[j].erase(ballots[j].begin());
							if (!ballots[j].empty())
								++votes[ ballots[j].front() ];
						}

					break;
				}

			if (hasWinner()) 
			{
				printf("   Candidate %d is elected.\n", hasWinner());
				break;
			}
			if (isAllCandidatesTied())
			{
				cout << "   The following candidates are tied:";
				for(int i = 1; i <= candidates; ++i)
					if (!isEliminated[i])
						cout << " " << i;
				cout << endl;
				break;
			}
		}
	}
	return 0;
}


