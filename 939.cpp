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

enum GENE {UNDETERMINED, RECESSIVE, DOMINANT, NON_EXISTENT};

struct Node
{
	GENE gene;
	vector<string> parents;

	Node() : gene(UNDETERMINED) {};
	Node(GENE _gene) : gene(_gene) {};
};

map<string, Node> m;

GENE determineGene(string parent1, string parent2)
{
	if (m[parent1].gene == UNDETERMINED) m[parent1].gene = determineGene(m[parent1].parents[0], m[parent1].parents[1]);
	if (m[parent2].gene == UNDETERMINED) m[parent2].gene = determineGene(m[parent2].parents[0], m[parent2].parents[1]);

	if (m[parent1].gene == DOMINANT && m[parent2].gene == DOMINANT) 
		return DOMINANT;
	else if ( ( m[parent1].gene == DOMINANT && m[parent2].gene == RECESSIVE ) || (m[parent1].gene == RECESSIVE && m[parent2].gene == DOMINANT) )
		return DOMINANT;
	else if (m[parent1].gene == DOMINANT || m[parent2].gene == DOMINANT)
		return RECESSIVE;
	else if (m[parent1].gene != NON_EXISTENT && m[parent2].gene != NON_EXISTENT)
		return RECESSIVE;
	else
		return NON_EXISTENT;
}

GENE getGene(string name)
{
	if (m[name].gene == UNDETERMINED) return determineGene(m[name].parents[0], m[name].parents[1]);
	else return m[name].gene;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int N;
	string s1, s2;

	cin >> N;
	while(N--)
	{
		cin >> s1 >> s2;

		if (s2 == "non-existent") m[s1] = Node(NON_EXISTENT);
		else if (s2 == "recessive") m[s1] = Node(RECESSIVE);
		else if (s2 == "dominant") m[s1] = Node(DOMINANT);
		else
		{
			m[s2].gene = UNDETERMINED;
			m[s2].parents.push_back(s1);
		}
	}

	for(map<string, Node>::iterator it = m.begin(); it != m.end(); ++it)
	{
		GENE g = getGene(it->first);
		string gene;
		if (g == NON_EXISTENT) gene = "non-existent";
		else if (g == RECESSIVE) gene = "recessive";
		else if (g == DOMINANT) gene = "dominant";

		cout << it->first << " " << gene << endl;
	}
	return 0;
}




