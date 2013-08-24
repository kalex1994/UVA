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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int N, M;
	string line1, line2;
	map<string, string> m;

	cin >> N; cin.ignore(100, '\n');
	while(N--)
	{
		getline(cin, line1);
		getline(cin, line2);
		m[line1] = line2;
	}
	cin >> M; cin.ignore(100, '\n');
	while(M--)
	{
		getline(cin, line1);
		cout << m[line1] << endl;
	}
	return 0;
}
