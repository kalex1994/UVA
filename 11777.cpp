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

int term1, term2, final, attendance, grade;
int classTests[3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests;

	cin >> tests;
	for(int t = 1; t <= tests; ++t)
	{
		cin >> term1 >> term2 >> final >> attendance;
		for(int i = 0; i < 3; ++i)
			cin >> classTests[i];

		sort(classTests, classTests + 3);

		grade = term1 + term2 + final + attendance + (classTests[1] + classTests[2]) / 2;

		printf("Case %d: ",t);
		if (grade >= 90) cout << "A" << endl;
		else if (grade >= 80) cout << "B" << endl;
		else if (grade >= 70) cout << "C" << endl;
		else if (grade >= 60) cout << "D" << endl;
		else cout << "F" << endl;
	}

	return 0;
}


