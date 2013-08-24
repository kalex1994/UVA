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
string f[] = {"F", "G", "A", "Bb", "C", "D", "E", "F"};
string g[] = {"G", "A", "B", "C", "D", "E", "F#", "G"};
string a[] = {"A", "B", "C#", "D", "E", "F#", "G#", "A"};
string b[] = {"B", "C#", "D#", "E", "F#", "G#", "A#", "B"};
string db[] = {"Db", "Eb", "F", "Gb", "Ab", "Bb", "C", "Db"};
string eb[] = {"Eb", "F", "G", "Ab", "Bb", "C", "D", "Eb"};
string gb[] = {"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F", "Gb"};
string ab[] = {"Ab", "Bb", "C", "Db", "Eb", "F", "G", "Ab"};
string bb[] = {"Bb", "C", "D", "Eb", "F", "G", "A", "Bb"};

vector<string> split(string s)
{
	vector<string> ret;
	while(true)
	{
		int i = s.find_first_of(";");
		if (i == string::npos)
		{
			ret.push_back(s);
			break;
		}
		ret.push_back(s.substr(0,i));
		s.erase(0,i + 1);
	}
	return ret;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	string key, line;
	while( getline(cin,key) )
	{
		getline(cin,line);
		vector<string> intervals = split(line);

		string *act = NULL;
		if (key == "C") act = c;
		if (key == "D") act = d;
		if (key == "E") act = e;
		if (key == "F") act = f;
		if (key == "G") act = g;
		if (key == "A") act = a;
		if (key == "B") act = b;
		if (key == "Db") act = db;
		if (key == "Eb") act = eb;
		if (key == "Gb") act = gb;
		if (key == "Ab") act = ab;
		if (key == "Bb") act = bb;

		cout << "Key of " << key << endl;

		for(int i = 0; i < (int)intervals.size(); ++i)
		{
			istringstream iss(intervals[i]);
			string note, direction, count;
			iss >> note >> direction >> count;
			cout << note << ": ";

			int index = -1;
			for(int j = 0; j < 8; ++j)
				if (act[j] == note)
				{
					index = j;
					break;
				}

			if (index == -1) 
			{
				cout << "invalid note for this key" << endl;
				continue;
			}
			if (count == "OCTAVE")
			{
				cout << direction << " " << count << " > " << note << endl;
				continue;
			}

			int number;
			if (count == "SECOND") number = 1;
			if (count == "THIRD") number = 2;
			if (count == "FOURTH") number = 3;
			if (count == "FIFTH") number = 4;
			if (count == "SIXTH") number = 5;
			if (count == "SEVENTH") number = 6;

			if (direction == "UP" && index + number >= 8) ++number;
			if (direction == "DOWN" && index - number < 0) ++number;

			cout << direction << " " << count << " > " 
				<< (direction == "UP" ? act[(index + number) % 8] : act[(index + 8 - number) % 8 ] ) << endl;
		}
		cout << endl;
	}
	return 0;
}


