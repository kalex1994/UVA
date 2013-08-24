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

string c[] = {"C", "D", "E", "F", "G", "A", "B", "C"};
string d[] = {"D", "E", "F#", "G", "A", "B", "C#", "D"};
string e[] = {"E", "F#", "G#", "A", "B", "C#", "D#", "E"};
string f[] = {"F", "G", "A", "A#", "C", "D", "E", "F"};
string g[] = {"G", "A", "B", "C", "D", "E", "F#", "G"};
string a[] = {"A", "B", "C#", "D", "E", "F#", "G#", "A"};
string b[] = {"B", "C#", "D#", "E", "F#", "G#", "A#", "B"};
string cs[] = {"C#","D#", "F", "F#" ,"G#", "A#", "C", "C#"};
string ds[] = {"D#","F", "G", "G#" ,"A#", "C", "D", "D#"};
string fs[] = {"F#","G#", "A#", "B" ,"C#", "D#", "F", "F#"};
string gs[] = {"G#","A#", "C", "C#" ,"D#", "F", "G", "G#"};
string as[] = {"A#","C", "D", "D#" ,"F", "G", "A", "A#"};

string notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

int main()
{
	freopen("c:\in.txt","r",stdin);
	freopen("c:\out.txt","w",stdout);

	map<string, vector<string> > majorScales;
	majorScales["C"] = vector<string>(c, c + 8);
	majorScales["D"] = vector<string>(d, d + 8);
	majorScales["E"] = vector<string>(e, e + 8);
	majorScales["F"] = vector<string>(f, f + 8);
	majorScales["G"] = vector<string>(g, g + 8);
	majorScales["A"] = vector<string>(a, a + 8);
	majorScales["B"] = vector<string>(b, b + 8);
	majorScales["C#"] = vector<string>(cs, cs + 8);
	majorScales["D#"] = vector<string>(ds, ds + 8);
	majorScales["F#"] = vector<string>(fs, fs + 8);
	majorScales["G#"] = vector<string>(gs, gs + 8);
	majorScales["A#"] = vector<string>(as, as + 8);

	string line;

	while(getline(cin,line) && line != "END")
	{
		set<string> possible;
		for(int i = 0; i < 12; ++i)
			possible.insert(notes[i]);

		istringstream iss(line);
		string note;
		while(iss >> note)
		{
			set<string> newSet;
			for(set<string>::iterator it = possible.begin(); it != possible.end(); ++it)
			{
				bool found = false;
				for(int i = 0; i < (int)majorScales[*it].size(); ++i)
					if (majorScales[*it][i] == note)
						found = true;
				if (found)
					newSet.insert(*it);
			}
			possible.clear();
			possible.insert(newSet.begin(), newSet.end());
		}

		bool isfirst = true;
		for(int i = 0; i < 12; ++i)
			if (possible.count(notes[i]))
			{
				if (isfirst) isfirst = false;
				else cout << " ";
				cout << notes[i];
			}
		cout << endl;
	}
	return 0;
}


