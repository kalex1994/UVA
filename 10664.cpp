#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D:\\hallgato\\IN.txt", "r", stdin);
	freopen("D:\\hallgato\\OUT.txt", "w", stdout);
#endif

	int tests, ch;
	int v[30];
	int n;

	scanf("%d", &tests);
	while (tests--)
	{
		n = 0;
		while (true)
		{
			scanf("%d", &v[n]);
			++n;
			ch = getchar();
			if (ch == '\n' || ch == EOF)
				break;
		}

		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += v[i];
		if (sum % 2 == 1)
		{
			puts("NO");
			continue;
		}

		int sump2 = sum / 2;
		bool flag = false;
		for (int i = 1; i + 1 < (1 << n); ++i)
		{
			int s = 0;
			for (int j = 0; j < n && s < sump2; ++j)
			if (i & (1 << j))
				s += v[j];
			if (s == sump2)
			{
				puts("YES");
				flag = true;
				break;
			}
		}
		if (!flag)
			puts("NO");
	}
}