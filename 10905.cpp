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
	
int N;
vector<string> numbers;
string temp;

bool compare(const string &a, const string &b)
{
	string x1 = a + b, x2 = b + a;
	if (x1 > x2) return true;
	else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> N, N)
	{
		numbers.clear();
		for(int i = 0; i < N; ++i)
		{
			cin >> temp;
			numbers.push_back(temp);
		}

		sort(numbers.begin(), numbers.end(), compare);

		for(int i = 0; i < (int)numbers.size(); ++i)
			cout << numbers[i];
		cout << endl;
	}
	return 0;
}


