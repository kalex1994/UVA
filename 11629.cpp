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

int parties, guesses, integerPart, fractionalPart;
char buffer[10000], partsName[50];
map<string , int> electionResults;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	scanf("%d %d%*c", &parties, &guesses);	

	while(parties--)
	{
		gets(buffer);
		sscanf(buffer, "%s %d.%d", partsName, &integerPart, &fractionalPart);
		electionResults[partsName] = integerPart * 10 + fractionalPart;
	}
	for(int guessNumber = 1; guessNumber <= guesses; ++guessNumber)
	{
		gets(buffer);
		for(int i = 0; i < strlen(buffer); ++i)
			if (buffer[i] == '+')
				buffer[i] == ' ';

		istringstream iss(buffer);
		vector<string> tokens;
		string token;

		while(iss >> token)
			tokens.push_back(token);

		int sum = 0;
		for(int i = 0; i < (int)tokens.size() - 2; ++i)
			sum += electionResults[ tokens[i] ];

		string relation = tokens[ (int)tokens.size() - 2 ];
		int guess = atoi(tokens.back().c_str()) * 10;

		printf("Guess #%d was ", guessNumber);
		if (relation == "<")
		{
			if (sum < guess) cout << "correct.";
			else cout << "incorrect.";
		}
		else if (relation == ">")
		{
			if (sum > guess) cout << "correct.";
			else cout << "incorrect.";
		}
		else if (relation == "<=")
		{
			if (sum <= guess) cout << "correct.";
			else cout << "incorrect.";
		}
		else if (relation == ">=")
		{
			if (sum >= guess) cout << "correct.";
			else cout << "incorrect.";
		}
		else
		{
			if (sum == guess) cout << "correct.";
			else cout << "incorrect.";
		}
		cout << endl;
	}
	return 0;
}
