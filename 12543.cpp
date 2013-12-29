#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <list>
#include <sstream>
using namespace std;


int main()
{
	string text, s;

	while (getline(cin, s))
		text += s;

	for (size_t i = 0; i < text.length(); ++i)
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || text[i] == '-')
			text[i] = tolower(text[i]);
		else
			text[i] = ' ';

	istringstream iss(text);
	string longest = "";

	while (iss >> s)
	{
		if (s != "e-n-d")
			if (s.length() > longest.length())
				longest = s;
	}
	
	cout << longest << endl;

	return 0;
}
