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
	
long long N, M, k;
vector<long long> numbers;

bool comp(long long a, long long b)
{
	long long am = a % M, bm = b % M;

	if (am < bm) return true;
	else if (am > bm) return false;
	else
	{
		if (abs(a) % 2 == 1 && abs(b) % 2 == 1 && a > b) return true;
		else if (abs(a) % 2 == 0 && abs(b) % 2 == 0 && a < b) return true;
		else if (abs(a) % 2 == 1 && abs(b) % 2 == 0) return true;
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	while(cin >> N >> M && (N || M))
	{
		numbers.clear();
		for(long long i = 0; i < N; ++i)
		{
			cin >> k;
			numbers.push_back(k);
		}
		sort(numbers.begin(), numbers.end(), comp);

		cout << N << " " << M << endl;
		for(long long i = 0; i < (long long)numbers.size(); ++i)
			cout << numbers[i] << endl;
	}
	cout << "0 0" << endl;
	return 0;
}


