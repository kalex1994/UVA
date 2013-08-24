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

	int tests;
	
	cin >> tests;
	while(tests--)
	{
		vector<int> prices;
		int price;

		while(cin >> price && price)
			prices.push_back(price);
		sort(prices.rbegin(), prices.rend());

		int answer = 0;
		for(int i = 0; i < (int)prices.size(); ++i)
		{
			answer += 2 * (int)pow((double)prices[i], i + 1);
			if (answer > 5000000)
				break;
		}

		if (answer > 5000000) cout << "Too expensive" << endl;
		else cout << answer << endl;
	}
	return 0;
}




