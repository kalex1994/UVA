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

bitset<1000010> calendar;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n, m, start, end, period;

	while(cin >> n >> m, (n || m))
	{
		calendar.reset();

		bool hasConflict = false;
		while(n--)
		{
			cin >> start >> end;

			if (hasConflict) continue;
			
			for(int i = start + 1; i <= end; ++i)
			{
				if (calendar.test(i)) hasConflict = true;
				else calendar.set(i);
			}
		}
		while(m--)
		{
			cin >> start >> end >> period;

			if (hasConflict) continue;

			while(true)
			{
				for(int i = start + 1; i <= end; ++i)
				{
					if (calendar.test(i)) hasConflict = true;
					else calendar.set(i);
				}

				start += period;
				end += period;

				if (start > 1000000 && end > 1000000) break;
				else if (end > 1000000) end = 1000000;
			}
		}

		if (hasConflict) cout << "CONFLICT" << endl;
		else cout << "NO CONFLICT" << endl;
	}
	return 0;
}




