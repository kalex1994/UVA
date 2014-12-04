#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	unsigned long long m[65];
	m[0] = m[1] = m[2] = 1lu;
	for(int i = 3; i <= 61; ++i)
		m[i] = m[i - 1] + m[i - 2] + m[i - 3];
	int n;
	for(int n, test = 1; cin >> n && n; ++test)
		printf("Case %d: %llu\n", test, m[n - 1]);
}