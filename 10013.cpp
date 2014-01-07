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
#include <functional>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <stack>
#include <sstream>
#include <iomanip>
#include <stdint.h>
using namespace std;

inline void add(const string& a, const string& b, string& result)
{
	char carry = 0, sum;
	result.resize(a.length());
	for (size_t i = 0; i < a.length(); ++i)
	{
		sum = a[i] - '0' + b[i] - '0' + carry;
		carry = sum / 10;
		result[i] = sum % 10 + '0';
	}
}

int main()
{	
	//freopen("D:\\IN", "r", stdin);
	//freopen("D:\\OUT", "w", stdout);   10625 uva
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string a, b, result;
	int tests, m;
	char ch;

	cin >> tests;
	while (tests--)
	{
		cin >> m;
		a.resize(m);
		b.resize(m);

		for (int i = 0; i < m; ++i)
		{
			cin >> ch;
			a[i] = ch;
			cin >> ch;
			b[i] = ch;
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		add(a, b, result);
		reverse(result.begin(), result.end());

		cout << result << '\n';
		if (tests) cout << '\n';
	}

	return 0;
} 

