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

bool spots[510][510];
int W, H, N, X1, X2, Y1, Y2;

int countEmptySpots()
{
	int sum = 0;
	for(int i = 1; i <= H; ++i)
		for(int j = 1; j <= W; ++j)
			sum += spots[i][j];
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> W >> H >> N && (W || H || N))
	{
		memset(spots, true, sizeof(spots));

		while(N--)
		{
			cin >> X1 >> Y1 >> X2 >> Y2;

			int startRow, startCol, endRow, endCol;
			startRow = min(Y1, Y2);
			startCol = min(X1, X2);
			endRow = max(Y1, Y2);
			endCol = max(X1, X2);

			for(int i = startRow; i <= endRow; ++i)
				for(int j = startCol; j <= endCol; ++j)
					spots[i][j] = false;

		}
		int sum = countEmptySpots();
		if (sum == 0) cout << "There is no empty spots." << endl;
		else if (sum == 1) cout << "There is one empty spot." << endl;
		else printf("There are %d empty spots.\n", sum);
	}
	return 0;
}
