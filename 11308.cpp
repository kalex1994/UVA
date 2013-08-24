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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, M, N, k, budget, price, amount;
	string title, ingredient, name;

	map<string, int> ingredients;
	vector< pair<int, string> > answer;

	cin >> tests; 
	while(tests--)
	{
		ingredients.clear();
		answer.clear();

		cin.ignore(100, '\n');
		getline(cin, title);

		for(int i = 0; i < (int)title.size(); ++i)
			title[i] = static_cast<char>(toupper(title[i]));

		cin >> M >> N >> budget;

		while(M--)
		{
			cin >> ingredient >> price;
			ingredients[ingredient] = price;
		}
		while(N--)
		{
			cin.ignore(100, '\n');
			getline(cin, name);

			int recipesPrice = 0;

			cin >> k;
			while(k--)
			{
				cin >> ingredient >> amount;
				recipesPrice += amount * ingredients[ingredient];
			}

			if (recipesPrice <= budget)
				answer.push_back( make_pair(recipesPrice, name) );
		}

		cout << title << endl;
		if (answer.empty()) cout << "Too expensive!" << endl;
		else
		{
			sort(answer.begin(), answer.end());
			for(int i = 0; i < (int)answer.size(); ++i)
				cout << answer[i].second << endl;
		}
		cout << endl;
	}
	return 0;
}
