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

enum MATCH_TYPE {WIN, DRAW, LOSE};

struct FootballTeam
{
	string name;
	int points, gamesPlayed, goalsScored, goalsSuffered;

	FootballTeam(string _name)
	{
		name = _name;
		points = gamesPlayed = goalsScored = goalsSuffered = 0;
	}

	int getGoalDifference() const
	{
		return goalsScored - goalsSuffered;
	}

	double getPercentageOfEarnedPoints() const
	{
		return (points * 100.0) / (gamesPlayed * 3.0); 
	}

	void update(int scored, int suffered, MATCH_TYPE mtype)
	{
		if (mtype == WIN) points += 3;
		else if (mtype == DRAW) points += 1;
		++gamesPlayed;
		goalsScored += scored;
		goalsSuffered += suffered;
	}

	bool equals(const FootballTeam &other) const
	{
		return points == other.points && getGoalDifference() == other.getGoalDifference() && goalsScored == other.goalsScored;
	}
};

bool cmpFootballTeams(const FootballTeam &a, const FootballTeam &b)
{
	if (a.points > b.points) return true;
	else if (a.points < b.points) return false;

	if (a.getGoalDifference() > b.getGoalDifference()) return true;
	else if (a.getGoalDifference() < b.getGoalDifference()) return false;

	if (a.goalsScored > b.goalsScored) return true;
	else if (a.goalsScored < b.goalsScored) return false;

	string a_name = a.name, b_name = b.name;
	for(int i = 0; i < (int)a_name.size(); ++i) a_name[i] = toupper(a_name[i]);
	for(int i = 0; i < (int)b_name.size(); ++i) b_name[i] = toupper(b_name[i]);

	return a_name < b_name;
}

int teams, games;
vector<FootballTeam> tournament;

int findTeam(string &team)
{
	for(int i = 0; i < (int)tournament.size(); ++i)
		if (tournament[i].name == team)
			return i;
}

void processMatch(string &team1, int goals1, string &team2, int goals2)
{
	int team1Pos = findTeam(team1), team2Pos = findTeam(team2);

	if (goals1 == goals2)
	{
		tournament[team1Pos].update(goals1, goals2, DRAW);
		tournament[team2Pos].update(goals2, goals1, DRAW);
	}
	else if (goals1 > goals2)
	{
		tournament[team1Pos].update(goals1, goals2, WIN);
		tournament[team2Pos].update(goals2, goals1, LOSE);
	}
	else
	{
		tournament[team1Pos].update(goals1, goals2, LOSE);
		tournament[team2Pos].update(goals2, goals1, WIN);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	bool isFirst = true;

	while(cin >> teams >> games && (teams || games))
	{
		tournament.clear();

		string name;
		for(int i = 0; i < teams; ++i)
		{
			cin >> name;
			tournament.push_back(FootballTeam(name));
		}

		string team1, team2;
		int goals1, goals2;
		char dash;

		for(int i = 0; i < games; ++i)
		{
			cin >> team1 >> goals1 >> dash >> goals2 >> team2;
			processMatch(team1, goals1, team2, goals2);
		}
		sort(tournament.begin(), tournament.end(), cmpFootballTeams);

		if (isFirst) isFirst = false;
		else cout << endl;
		for(int i = 0; i < (int)tournament.size(); ++i)
		{
			if (i > 0 && tournament[i].equals(tournament[i-1])) cout << "   ";
			else printf("%2d.", i + 1);

			printf("%16s%4d%4d%4d%4d%4d", tournament[i].name.c_str(), tournament[i].points, tournament[i].gamesPlayed, 
				tournament[i].goalsScored, tournament[i].goalsSuffered, tournament[i].getGoalDifference());

			if (tournament[i].gamesPlayed > 0)
				printf("%7.2lf\n", tournament[i].getPercentageOfEarnedPoints());
			else
				printf("%7s\n","N/A");
		}
	}
	return 0;
}




