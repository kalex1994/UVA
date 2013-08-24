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

string simplifiy(string &s)
{
	if (s == "AA") return "A";
	if (s == "AO") return "A";
	if (s == "BB") return "B";
	if (s == "BO") return "B";
	if (s == "AB") return "AB";
	if (s == "OO") return "O";
}

string getAlleles(string person)
{
	if (person == "A") return "AO";
	if (person == "B") return "BO";
	if (person == "O") return "O";
	if (person == "AB") return "AB";
}

vector<string> getChild(string parent1, string parent2)
{
	set<string> possibleChild;
	bool canBeRHpositive = true;
	if (parent1[parent1.size() - 1] == '-' && parent2[parent2.size() - 1] == '-') 
		canBeRHpositive = false;
	parent1.erase(parent1.size() - 1);
	parent2.erase(parent2.size() - 1);

	parent1 = getAlleles(parent1);
	parent2 = getAlleles(parent2);

	for(int i = 0; i < (int)parent1.size(); ++i)
		for(int j = 0; j < (int)parent2.size(); ++j)
		{
			string child = "";
			child += parent1[i];
			child += parent2[j];
			if (child[0] > child[1])
				swap(child[0],child[1]);
			possibleChild.insert(simplifiy(child) + "-");
			if (canBeRHpositive)
				possibleChild.insert(simplifiy(child) + "+");
		}
	return vector<string>(possibleChild.begin(), possibleChild.end());
}

vector<string> getParent(string parent, string child)
{
	set<string> possibleParents;
	string ABO = "ABO";

	bool mustBeRHpositive = false;
	if (parent[parent.size() - 1] == '-' && child[child.size() - 1] == '+')
		mustBeRHpositive = true;

	for(int i = 0; i < (int)ABO.size(); ++i)
		for(int j = 0; j < (int)ABO.size(); ++j)
		{
			string parent2 = "";
			parent2 += ABO[i];
			parent2 += ABO[j];
			if (parent2[0] > parent2[1])
				swap(parent2[0], parent2[1]);

			vector<string> temp = getChild(parent,simplifiy(parent2) + "+");
			if (find(temp.begin(),temp.end(),child) != temp.end())
				possibleParents.insert(simplifiy(parent2) + "+");

			if (mustBeRHpositive)
				continue;
			
			temp = getChild(parent,simplifiy(parent2) + "-");
			if ( find(temp.begin(),temp.end(),child) != temp.end() )
				possibleParents.insert(simplifiy(parent2) + "-");
		}
	return vector<string>(possibleParents.begin(),possibleParents.end());
}

string convertToString(vector<string> v)
{
	if (v.empty()) return "IMPOSSIBLE";
	if (v.size() == 1) return v[0];

	ostringstream oss;
	oss << "{";
	for(int i = 0; i < (int)v.size(); ++i)
	{
		if (i > 0) oss << ", ";
		oss << v[i];
	}
	oss << "}";
	return oss.str();
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	string parent1, parent2, child;
	int caseNumber = 1;

	while(cin >> parent1 >> parent2 >> child && parent1 != "E" && parent2 != "N" && child != "D")
	{
		printf("Case %d: ",caseNumber++);
		if (parent1 == "?") cout << convertToString(getParent(parent2,child)) << " " << parent2 << " " << child << endl;
		else if (parent2 == "?") cout << parent1 << " " << convertToString(getParent(parent1,child)) << " " << child << endl;
		else if (child == "?") cout << parent1 << " " << parent2 << " " << convertToString(getChild(parent1,parent2)) << endl;
	}
	return 0;
}


