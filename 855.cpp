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

int S, A, F;
vector< int > street, avenue;

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
		street.clear();
		avenue.clear();

		cin >> S >> A >> F;

		int r, c;
		for(int i = 0; i < F; ++i)
		{
			cin >> r >> c;
			street.push_back(r);
			avenue.push_back(c);
		}

		sort(street.begin(), street.end());
		sort(avenue.begin(), avenue.end());

		if (F % 2 == 0)
			printf("(Street: %d, Avenue: %d)\n", street[F / 2 - 1], avenue[F / 2 - 1]);
		else
			printf("(Street: %d, Avenue: %d)\n", street[F / 2], avenue[F / 2]);
	}
	return 0;
}




