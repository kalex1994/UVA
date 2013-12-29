#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

void draw_wave(int amplitude)
{
	for (int i = 1; i <= amplitude; ++i)
	{
		for (int j = 0; j < i; ++j)
			printf("%d", i);
		putchar('\n');
	}
	for (int i = amplitude - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
			printf("%d", i);
		putchar('\n');
	}
}

int main()
{
	int tests, amplitude, frequency;

	cin >> tests;
	while (tests--)
	{
		cin >> amplitude >> frequency;

		for (int i = 0; i < frequency; ++i)
		{
			if (i > 0) putchar('\n');
			draw_wave(amplitude);
		}

		if (tests) putchar('\n');
	}

	return 0;
}
