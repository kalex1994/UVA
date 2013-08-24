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

int n, k;
queue< pair<int,int> > students;
vector<int> leavers;
int outputStore, nextStore;

void init()
{
	queue< pair<int,int> > empty;
	swap(empty,students);

	leavers.clear();

	for(int i = 0; i < n; ++i)
		students.push(make_pair(i+1,0));

	outputStore = 1;
	nextStore = 1;
}

void nextAmount()
{
	++nextStore;
	if (nextStore == k + 1)
		nextStore = 1;
	outputStore = nextStore;
}

bool simulateProcess()
{
	if (students.empty() == true)
		return false;

	pair<int,int> firstStudent = students.front();
	students.pop();

	if (firstStudent.second + outputStore < 40)
	{
		firstStudent.second += outputStore;
		students.push(firstStudent);
		outputStore = 0;
	}
	else if (firstStudent.second + outputStore == 40)
	{
		leavers.push_back(firstStudent.first);
		outputStore = 0;
	}
	else
	{
		leavers.push_back(firstStudent.first);
		outputStore = (outputStore + firstStudent.second) - 40;
	}
	if (outputStore == 0)
		nextAmount();
	return true;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	while(cin >> n >> k && (n || k))
	{
		init();
		while(simulateProcess())
			;
	
		for(int i = 0; i < (int)leavers.size(); ++i)
			printf("%3d",leavers[i]);
			
		cout << endl;
	}
	return 0;
}


