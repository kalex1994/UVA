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

class FootballTeam
{
public:
	int points, wins, draws, losses, goalsScored, goalsReceived, gamesPlayed;
	char name[50];

	FootballTeam()
	{
		strcpy(name,"");
		points = wins = draws = losses = goalsScored = goalsReceived = gamesPlayed = 0;
	}

	FootballTeam(char _name[])
	{
		strcpy(name, _name);
		points = wins = draws = losses = goalsScored = goalsReceived = gamesPlayed = 0;
	}

	FootballTeam(const FootballTeam &other)
	{
		points = other.points;
		wins = other.wins;
		draws = other.draws;
		losses = other.losses;
		goalsScored = other.goalsScored;
		goalsReceived = other.goalsReceived;
		gamesPlayed = other.gamesPlayed;
		strcpy(name, other.name);
	}

	int getGoalDifference() const
	{
		return goalsScored - goalsReceived;
	}

	friend bool cmp (FootballTeam a, FootballTeam b);
	friend ostream& operator<< (ostream &os, const FootballTeam &FT);
};

bool cmp (FootballTeam a, FootballTeam b)
{
	if (a.points > b.points) return true;
	else if (a.points < b.points) return false;

	if (a.wins > b.wins) return true;
	else if (a.wins < b.wins) return false;

	if (a.getGoalDifference() > b.getGoalDifference()) return true;
	else if (a.getGoalDifference() < b.getGoalDifference()) return false;

	if (a.goalsScored > b.goalsScored) return true;
	else if (a.goalsScored < b.goalsScored) return false;

	if (a.gamesPlayed < b.gamesPlayed) return true;
	else if (a.gamesPlayed > b.gamesPlayed) return false;

	for(int i = 0; i < strlen(a.name); ++i)
		a.name[i] = toupper(a.name[i]);
	for(int i = 0; i < (strlen(b.name)); ++i)
		b.name[i] = toupper(b.name[i]);

	return strcmp(a.name, b.name) < 0;
}

ostream &operator<< (ostream &os, const FootballTeam &FT)
{
	os << FT.name << " " << FT.points << "p, " << FT.gamesPlayed << "g (" << FT.wins << "-" << FT.draws << "-" << FT.losses << "), " <<
		FT.getGoalDifference() << "gd (" << FT.goalsScored << "-" << FT.goalsReceived << ")";
	return os;
}

char buffer[110];
char tournament[110];
vector<FootballTeam> teams;
int teamCount, matchCount;

int findTeam(char team[])
{
	for(int i = 0; i < (int)teams.size(); ++i)
		if (strcmp(team, teams[i].name) == 0)
			return i;
}

void Win(char team[], int goalsScored, int goalsReceived)
{
	int index = findTeam(team);

	teams[index].gamesPlayed++;
	teams[index].goalsScored += goalsScored;
	teams[index].goalsReceived += goalsReceived;
	teams[index].wins++;
	teams[index].points += 3;
}

void Draw(char team[], int goalsScored, int goalsReceived)
{
	int index = findTeam(team);

	teams[index].gamesPlayed++;
	teams[index].goalsScored += goalsScored;
	teams[index].goalsReceived += goalsReceived;
	teams[index].draws++;
	teams[index].points += 1;
}

void Lose(char team[], int goalsScored, int goalsReceived)
{
	int index = findTeam(team);

	teams[index].gamesPlayed++;
	teams[index].goalsScored += goalsScored;
	teams[index].goalsReceived += goalsReceived;
	teams[index].losses++;
}

void processGame(char game[])
{
	char team1[40], team2[40];
	int goals1, goals2;

	sscanf(game, "%[^#]#%d@%d#%[^\n]%*c", team1, &goals1, &goals2, team2);
	if (goals1 == goals2)
	{
		Draw(team1, goals1, goals2);
		Draw(team2, goals2, goals1);
	}
	else if (goals1 > goals2)
	{
		Win(team1, goals1, goals2);
		Lose(team2, goals2, goals1);
	}
	else
	{
		Lose(team1, goals1, goals2);
		Win(team2, goals2, goals1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	gets(buffer);
	int tests = atoi(buffer);

	while (tests--)
	{
		teams.clear();

		gets(tournament);
		gets(buffer);
		teamCount = atoi(buffer);

		while(teamCount--)
		{
			gets(buffer);
			teams.push_back(FootballTeam(buffer));
		}

		gets(buffer);
		matchCount = atoi(buffer);

		while(matchCount--)
		{
			gets(buffer);
			processGame(buffer);
		}

		sort(teams.begin(), teams.end(), cmp);
		cout << tournament << endl;
		for(int i = 0; i < (int)teams.size(); ++i)
			cout << i + 1 << ") " << teams[i] << endl;
		if (tests) cout << endl;
	}
	return 0;
}




