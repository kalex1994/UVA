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

vector<string> cards;
string card, word;
int N;

void inc(int &i)
{
	i = (i + 1) % N;
	if (cards[i] != "")
		while(cards[i] != "")
			i = (i + 1) % N;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> N && N)
	{
		cards.assign(N, "");
		int pos = 0;

		for(int i = 0; i < N; ++i)
		{
			cin >> card >> word;

			for(int j = 0; j < (int)word.size() - 1; ++j)
				inc(pos);

			cards[pos] = card;
			if (i != N - 1)
				inc(pos);
		}
		for(int i = 0; i < (int)cards.size(); ++i)
		{
			if (i > 0) cout << " ";
			cout << cards[i];
		}
		cout << endl;
	}
	return 0;
}




