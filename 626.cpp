#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX = 100 + 5;
typedef pair<int, pair<int, int> > triple;
int matrix[MAX][MAX];
int N;

inline bool isChain(int a, int b, int c)
{
	if (a == b || b == c || a == c) return false;
	return matrix[a][b] == 1 && matrix[b][c] == 1 && matrix[c][a] == 1;
}

inline bool isAscending(const triple &t)
{
	return t.first <= t.second.first && t.second.first <= t.second.second;
}

inline bool isDescending(const triple &t)
{
	return t.first >= t.second.first && t.second.first >= t.second.second;
}

int main()
{
	while (cin >> N)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> matrix[i][j];

		set<triple> cycle;
		for (int a = 0; a < N; ++a)
			for (int b = 0; b < N; ++b)
				for (int c = 0; c < N; ++c)
				{
					triple t1(a, make_pair(b, c));
					triple t2(b, make_pair(c, a));
					triple t3(c, make_pair(a, b));

					if (isChain(a, b, c))
					if (cycle.count(t1) == 0 && cycle.count(t2) == 0 && cycle.count(t3) == 0)
					{
						if (isAscending(t1) || isDescending(t1)) cycle.insert(t1);
						else if (isAscending(t2) || isDescending(t2)) cycle.insert(t2);
						else cycle.insert(t3);
					}
				}

		for (set<triple>::const_iterator it = cycle.begin(); it != cycle.end(); ++it)
			cout << (*it).first + 1 << " " << (*it).second.first + 1 << " " << (*it).second.second + 1 << endl;
		cout << "total:" << cycle.size() << endl << endl;
	}
}