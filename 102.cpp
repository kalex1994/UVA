#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

enum { BROWN, CLEAR, GREEN };

int main()
{
	int bins[3][3];

	while (cin >> bins[0][BROWN] >> bins[0][GREEN] >> bins[0][CLEAR] >>
		bins[1][BROWN] >> bins[1][GREEN] >> bins[1][CLEAR] >>
		bins[2][BROWN] >> bins[2][GREEN] >> bins[2][CLEAR])
	{
		int indexes[] = { BROWN, CLEAR, GREEN };
		int answer[3];

		int minimalMovements = INT_MAX;
		copy(indexes, indexes + 3, answer);

		do
		{
			int movements = 0;

			if (indexes[0] == BROWN) movements += bins[1][BROWN] + bins[2][BROWN];
			else if (indexes[0] == CLEAR) movements += bins[1][CLEAR] + bins[2][CLEAR];
			else movements += bins[1][GREEN] + bins[2][GREEN];

			if (indexes[1] == BROWN) movements += bins[0][BROWN] + bins[2][BROWN];
			else if (indexes[1] == CLEAR) movements += bins[0][CLEAR] + bins[2][CLEAR];
			else movements += bins[0][GREEN] + bins[2][GREEN];

			if (indexes[2] == BROWN) movements += bins[0][BROWN] + bins[1][BROWN];
			else if (indexes[2] == CLEAR) movements += bins[0][CLEAR] + bins[1][CLEAR];
			else movements += bins[0][GREEN] + bins[1][GREEN];

			if (movements < minimalMovements)
			{
				minimalMovements = movements;
				copy(indexes, indexes + 3, answer);
			}

		} while (next_permutation(indexes, indexes + 3));

		for (int i = 0; i < 3; ++i)
			switch (answer[i])
		{
			case BROWN:
				cout << 'B'; break;
			case CLEAR:
				cout << 'C'; break;
			case GREEN:
				cout << 'G'; break;
		}
		cout << ' ' << minimalMovements << endl;
	}
	return 0;
}