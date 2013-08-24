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

vector<string> players[2], faceCards;

int getCardsNeedToCover(string &card)
{
	int cardsNeed = 0;
	if (card[1] == 'A') cardsNeed = 4;
	if (card[1] == 'K') cardsNeed = 3;
	if (card[1] == 'Q') cardsNeed = 2;
	if (card[1] == 'J') cardsNeed = 1;
	return cardsNeed;
}

int main()
{
	//freopen("c:\\in.txt","r",stdin);
	//freopen("c:\\out.txt","w",stdout);

	while(true)
	{
		players[0].clear();
		players[1].clear();
		faceCards.clear();

		for(int i = 0; i < 52; ++i)
		{
			string card;
			cin >> card;
			if (card == "#") return 0;

			if (i & 1)
				players[1].push_back(card);
			else 
				players[0].push_back(card);
		}

		int current = 0;
		while(players[current].empty() == false)
		{
			string card = players[current].back();
			players[current].pop_back();
			faceCards.push_back(card);

			if ( (card[1] >= '2' && card[1] <= '9') || card[1] == 'T')
			{
				current = !current;
				continue;
			}

			int cardsNeed = getCardsNeedToCover(card);
			while(true)
			{
				bool isCovered = true;
				current = !current;
				for(int i = 0; i < cardsNeed; ++i)
				{
					if (players[current].empty())
						goto hasWinner;

					card = players[current].back();
					players[current].pop_back();
					faceCards.push_back(card);

					if (card[1] == 'A' || card[1] == 'K' || card[1] == 'Q' || card[1] == 'J')
					{
						isCovered = false;
						cardsNeed = getCardsNeedToCover(card);
						break;
					}
				}

				if (isCovered)
					break;
			}
			current = !current;
			players[current].insert(players[current].begin(), faceCards.rbegin(), faceCards.rend());
			faceCards.clear();
		}

hasWinner:
		int winner = (players[0].empty() ? 1 : 0);
		printf("%d%3d\n",winner == 0 ? 2 : 1, players[winner].size());
	}
	return 0;
}


