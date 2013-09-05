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
#include<climits>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int row, col, size, actual, position, ring, prev_ring;

	while(cin >> size >> position && (size || position) )
	{
		if (position <= 9)
		{
			row = col = size / 2 + 1;
			if (position == 2) ++row;
			else if (position == 3) ++row, --col;
			else if (position == 4) --col;
			else if (position == 5) --row, --col;
			else if (position == 6) --row;
			else if (position == 7) --row, ++col;
			else if (position == 8) ++col;
			else if (position == 9) ++row, ++col;

			printf("Line = %d, column = %d.\n", row, col);
			continue;
		}

		ring = (int)ceil(sqrt((double)position));
		if ( !(ring & 1) )
			++ring;
		prev_ring = ring - 2;

		row = col = (size / 2) + ((ring - 1) / 2) + 1;
	
		int p = prev_ring * prev_ring + 1;	
		if (position <= p + prev_ring)
		{
			col -= (position + 1) - p;
			goto answer;
		}

		p += prev_ring;
		if (position <= p + prev_ring + 1)
		{
			row -= position - p;
			col -= prev_ring + 1;
			goto answer;
		}

		p += prev_ring + 1;
		if (position <= p + prev_ring + 1)
		{
			row -= prev_ring + 1;
			col -= (ring - 1) - (position - p);
			goto answer;
		}

		p += prev_ring + 1;
		if (position <= p + prev_ring)
		{
			row -= (ring - 1) - (position - p);
			goto answer;
		}

answer:
		printf("Line = %d, column = %d.\n", row, col);
	}
	return 0;
}