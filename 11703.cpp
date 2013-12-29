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
#include <sstream>
using namespace std;

const int MAX = 1000000;

int ind1[MAX + 5], ind2[MAX + 5], ind3[MAX + 5], x[MAX + 5];

int get(int i)
{
	if (x[i] == -1)
		return x[i] = ( ( get(ind1[i]) + get(ind2[i]) ) % MAX + get(ind3[i]) ) % MAX;
	else
		return x[i];
}

void preprocess()
{
	for (int i = 1; i <= MAX; ++i)
	{
		ind1[i] = (int)floor((double)i - sqrt((double)i));
		ind2[i] = (int)floor(log(double(i)));	
		double s = sin((double)i);
		ind3[i] = i * s * s;
	}

	for (int i = 1; i <= MAX; ++i)
		x[i] = -1;
	x[0] = 1;

	for (int i = 1; i <= MAX; ++i)
		if (x[i] == -1)
			x[i] = get(i);
}

int main()
{
	preprocess();
	
	int i;
	while (cin >> i && i != -1)
		cout << x[i] << endl;
}