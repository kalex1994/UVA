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

struct person
{
	string name;
	int day, month, year;

	person(string Name, int Day, int Month, int Year)
	{
		this->name = Name;
		this->day = Day;
		this->month = Month;
		this->year = Year;
	}
};

bool operator<(const person &a, const person &b)
{
	if (a.year < b.year) return true;
	else if (a.year > b.year) return false;

	if (a.month < b.month) return true;
	else if (a.month > b.month) return false;

	if (a.day < b.day) return true;
	else if (a.day > b.day) return false;
}

vector<person> persons;
string name;
int day, month, year;
int N;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	cin >> N;
	while(N--)
	{
		cin >> name >> day >> month >> year;
		persons.push_back( person(name, day, month, year) );
	}

	sort(persons.begin(), persons.end());
	cout << persons.back().name << endl;
	cout << persons.front().name << endl;
	return 0;
}


