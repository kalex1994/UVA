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
#include<cfloat>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	map<string, int> subjects;
	string subject;
	int tests, n, days, deadLine, caseNumber = 1;

	cin >> tests;
	while(tests--)
	{
		subjects.clear();
		cin >> n;
		while(n--)
		{
			cin >> subject >> days;
			subjects[subject] = days;
		}
		cin >> deadLine >> subject;

		printf("Case %d: ", caseNumber++);
		if (!subjects.count(subject)) cout << "Do your own homework!" << endl;
		else if (subjects[subject] > deadLine + 5) cout << "Do your own homework!" << endl;
		else if (subjects[subject] > deadLine) cout << "Late" << endl;
		else cout << "Yesss" << endl;
	}
	return 0;
}
