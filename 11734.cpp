#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

string remove_spaces(string s)
{
	vector<string> tokens;
	istringstream iss(s);
	string token;

	while(iss >> token)
		tokens.push_back(token);

	string result = "";
	for(size_t i = 0; i < tokens.size(); ++i)
		result += tokens[i];
	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests;

	cin >> tests; 
	cin.ignore(100, '\n');

	for(int test = 1; test <= tests; ++test)
	{
		string team, judge;
		getline(cin, team);
		getline(cin, judge);

		if (team == judge)
			printf("Case %d: Yes\n", test);
		else if (remove_spaces(team) == judge)
			printf("Case %d: Output Format Error\n", test);
		else 
			printf("Case %d: Wrong Answer\n", test);
	}

}