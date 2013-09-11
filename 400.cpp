#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <iterator>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("d:\\in.txt", "r", stdin);
	freopen("d:\\out.txt", "w", stdout);
#endif

	const string dash = "------------------------------------------------------------";
	vector<string> words;
	int N;

	while(cin >> N)
	{
		int maxLength = 0;
		words.resize(N);
		for(int i = 0; i < N; ++i)
		{
			cin >> words[i];
			if ((int)words[i].size() > maxLength)
				maxLength = (int)words[i].size();
		}

		sort(words.begin(), words.end());

		int columnCount = 1 + (60 - maxLength) / (maxLength + 2);
		int rowCount = N % columnCount == 0 ? N / columnCount : N / columnCount + 1;

		vector< vector<string> > output(columnCount);
		int index = 0;
		for(int i = 0; i < columnCount; ++i)
			for(int j = 0; j < rowCount; ++j)
			{
				if (index >= N) break;
				output[i].push_back(words[index++]);
			}

		cout << dash << endl;
		for(int i = 0; i < rowCount; ++i)
		{
			for(int j = 0; j < columnCount; ++j)
				if (i < (int)output[j].size())
					printf("%*s", j == columnCount - 1 ? -maxLength : -(maxLength + 2), output[j][i].c_str());
			cout << endl;
		}
	}
	return 0;
}