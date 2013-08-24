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

int n;
bool matrix[110][110];
int rowsum[110], colsum[110];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif
	
	while(cin >> n, n)
	{
		memset(rowsum, 0, sizeof(rowsum));
		memset(colsum, 0, sizeof(colsum));

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin >> matrix[i][j];

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				rowsum[i] += matrix[i][j];
				colsum[j] += matrix[i][j];
			}

		bool isCorrupt = false;
		int corruptRows = 0, corruptCols = 0, cr, cc;


		for(int i = 0; i < n; ++i)
		{
			if (rowsum[i] % 2 != 0) ++corruptRows, cr = i;
			if (colsum[i] % 2 != 0) ++corruptCols, cc = i;
		}

		if (corruptRows == 0 && corruptCols == 0) cout << "OK" << endl;
		else if (corruptRows == 1 && corruptCols == 1) printf("Change bit (%d,%d)\n", cr + 1, cc + 1);
		else cout << "Corrupt" << endl;
	}
	return 0;
}




