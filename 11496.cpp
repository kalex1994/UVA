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

vector<int> peaks;

inline bool isLocalMaximum(int i)
{
	int left = (i == 0 ? peaks.back() : peaks[i - 1]);
	int right = (i + 1 == peaks.size() ? peaks[0] : peaks[i + 1]);
	return left < peaks[i] && right < peaks[i];
}

inline bool isLocalMinimum(int i)
{
	int left = (i == 0 ? peaks.back() : peaks[i - 1]);
	int right = (i + 1 == peaks.size() ? peaks[0] : peaks[i + 1]);
	return left > peaks[i] && right > peaks[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int n;

	while(cin >> n && n)
	{
		peaks.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> peaks[i];

		int answer = 0;
		for(int i = 0; i < n; ++i)
			if (isLocalMinimum(i) || isLocalMaximum(i))
				++answer;

		cout << answer << endl;
	}
	return 0;
}




