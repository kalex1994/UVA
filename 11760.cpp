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

bitset<10010> row, col;
int R, C, r, c, N, caseNumber = 1;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	while(cin >> R >> C >> N)
	{
		if (!(R || C || N)) break;

		row.reset();
		col.reset();
		while(N--)
		{
			cin >> r >> c;
			row.set(r);
			col.set(c);
		}
		cin >> r >> c;

		int dr[] = {0,0,+1,-1,0};
		int dc[] = {-1,+1,0,0,0};

		bool escaped = false;
		for(int k = 0; k < 5; ++k)
		{
			int nr = r + dr[k];
			int nc = c + dc[k];

			if (nr >= 0 && nr < R && nc >= 0 && nc < C)
				if (!row.test(nr) && !col.test(nc))
					escaped = true;
		}
		printf("Case %d: %s\n",caseNumber++, escaped ? "Escaped again! More 2D grid problems!" : "Party time! Let's find a restaurant!");
	}
	return 0;
}
