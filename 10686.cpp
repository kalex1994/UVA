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

vector<string> categoryNames;
map<string, int> wordsNeed;
map<string, int> wordsFound;
map<string, set<string> > keyWords;
set<string> problemDescription;

void tokenize(string &word, vector<string> &tokens)
{
	for(int i = 0; i < (int)word.size(); ++i)
		if (!isalpha(word[i]))
			word[i] = ' ';
	istringstream iss(word);
	string s;
	while(iss >> s)
		tokens.push_back(s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	int tests, C, W, P;
	string name, word;

	cin >> tests;
	while(tests--)
	{
		categoryNames.clear();
		wordsNeed.clear();
		wordsFound.clear();
		keyWords.clear();
		problemDescription.clear();

		cin >> C;
		while(C--)
		{
			cin >> name >> W >> P;
			categoryNames.push_back(name);
			wordsNeed[name] = P;

			while(W--)
			{
				cin >> word;
				keyWords[name].insert(word);
			}
		}

		cin.ignore(100, '\n');
		string line, token;
		while(getline(cin, line) && !line.empty())
		{
			istringstream iss(line);
			while(iss >> token)
			{
				vector<string> temp;
				tokenize(token, temp);
				for(int i = 0; i < (int)temp.size(); ++i)
					problemDescription.insert(temp[i]);
			}
		}

		for(int i = 0; i < (int)categoryNames.size(); ++i)
			wordsFound[ categoryNames[i] ] = 0;

		for(map<string, set<string> >::iterator it = keyWords.begin(); it != keyWords.end(); ++it)
			for(set<string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
				if (problemDescription.count(*jt))
					++wordsFound[it->first];

		bool isFirst = true;
		for(int i = 0; i < (int)categoryNames.size(); ++i)
			if (wordsFound[ categoryNames[i] ] >= wordsNeed[ categoryNames[i] ])
			{
				if (isFirst) 
					isFirst = false;
				else
					cout << ',';
				cout << categoryNames[i];
			}
		if (isFirst) cout << "SQF Problem.";
		cout << endl;
	}
	return 0;
}
