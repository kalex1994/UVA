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

struct Sygnal
{
	int _cycleTime, red, yellow, green;
	enum COLOR {GREEN, YELLOW, RED} current;

	Sygnal(int cycleTime)
	{
		this->_cycleTime = cycleTime;
		green = yellow = red = 0;
		current = GREEN;
	}

	void next()
	{
		if (current == GREEN)
		{
			++green;
			if (green == _cycleTime - 5)
			{
				current = YELLOW;
				green = 0;
			}
		}
		else if (current == YELLOW)
		{
			++yellow;
			if (yellow == 5)
			{
				current = RED;
				yellow = 0;
			}
		}
		else
		{
			++red;
			if (red == _cycleTime)
			{
				current = GREEN;
				red = 0;
			}
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	string line;
	int caseNumber = 1;

	while (getline(cin, line) )
	{
		vector<Sygnal> tokens;
		int token;
		istringstream iss(line);

		while(iss >> token)
			tokens.push_back(Sygnal(token));

		bool turnedToYellow = false;
		bool isAllGreen = false;
		int seconds = 0;

		while(true)
		{
			if (seconds > 3600) 
			{
				printf("Set %d is unable to synch after one hour.\n", caseNumber++);
				break;
			}

			if (turnedToYellow)
			{
				isAllGreen = true;
				for(int i = 0; i < (int)tokens.size(); ++i)
					if (tokens[i].current != Sygnal::GREEN)
						isAllGreen = false;
			}		

			if (isAllGreen)
			{
				printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", 
					caseNumber++, seconds / 60, seconds % 60);
				break;
			}

			++seconds;

			for(int i = 0; i < (int)tokens.size(); ++i)
			{
				tokens[i].next();
				if (tokens[i].current == Sygnal::YELLOW)
					turnedToYellow = true;
			}
		}
	}

	return 0;
}
