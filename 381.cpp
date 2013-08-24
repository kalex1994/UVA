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

struct student
{
	vector<int> testResults;
	int bonusPoints, absences, grade;
	double average;

	student(vector<int> _testResults, int _bonusPoints, int _absences)
	{
		this->testResults = _testResults;
		this->bonusPoints = _bonusPoints;
		this->absences = _absences;
	}

	void computeAverage()
	{
		double sum = 0;
		for(int i = 0; i < (int)testResults.size(); ++i)
			sum += (double)testResults[i];
		average = sum / (double)testResults.size();
	}

	void adjustBonus()
	{
		int p = 3 * (bonusPoints / 2);
		average += (double)p;
	}
};

vector<student> group;

void removeMinimumTestResult()
{
	for(int i = 0; i < (int)group.size(); ++i)
		group[i].testResults.erase( min_element(group[i].testResults.begin(), group[i].testResults.end()) );
}

void computeAverages()
{
	for(int i = 0; i < (int)group.size(); ++i)
		group[i].computeAverage();
}

double groupsAverage()
{
	double sum = 0;
	for(int i = 0; i < (int)group.size(); ++i)
		sum += group[i].average;
	return sum / (double)group.size();
}

double getStandardDeviation(double mean)
{
	double sum = 0;
	for(int i = 0; i < (int)group.size(); ++i)
		sum += ( (group[i].average - mean) * (group[i].average - mean) );
	return sqrt( sum / (double)group.size() );
}

void adjustBonusPoints()
{
	for(int i = 0; i < (int)group.size(); ++i)
		group[i].adjustBonus();
}

void computeGrades(double forA, double forB, double forC)
{
	for(int i = 0; i < (int)group.size(); ++i)
	{
		double av = group[i].average;

		if (av >= forA)
			group[i].grade = 4;
		else if (av >= forB)
			group[i].grade = 3;
		else if (av >= forC)
			group[i].grade = 2;
		else
			group[i].grade = 1;

		if (group[i].absences == 0)
		{
			group[i].grade += 1;
			if (group[i].grade > 4)
				group[i].grade = 4;
		}
		else
		{
			group[i].grade -= group[i].absences / 4;
			if (group[i].grade < 0)
				group[i].grade = 0;
		}

	}
}

double getClassAverage()
{
	double sum = 0;
	for(int i = 0; i < (int)group.size(); ++i)
		sum += (double)group[i].grade;
	return sum / (double)group.size();
}


int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	int testCases, S, T;

	cout << "MAKING THE GRADE OUTPUT" << endl;

	cin >> testCases;
	while(testCases--)
	{
		group.clear();

		cin >> S >> T;
		for(int i = 0; i < S; ++i)
		{
			vector<int> results;
			int r, bonus, absense;

			for(int j = 0; j < T; ++j)
			{
				cin >> r;
				results.push_back(r);
			}
			cin >> bonus >> absense;
			group.push_back(student(results,bonus,absense));
		}

		if (T > 2)
		{
			removeMinimumTestResult();
			--T;
		}

		computeAverages();
		double mean = groupsAverage();
		double sd = getStandardDeviation(mean);
		if (sd < 1.0) sd = 1.0;

		double forA = mean + sd;
		double forB = mean;
		double forC = mean - sd;

		adjustBonusPoints();
		
		computeGrades(forA,forB,forC);

		printf("%0.1lf\n",getClassAverage());
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}


