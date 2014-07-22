#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void split(string& s, char delim, vector<string>& formulas)
{
	for (size_t i = 0; i < s.length(); ++i)
		if (s[i] == delim)
			s[i] = ' ';

	istringstream iss(s);
	string token;

	formulas.clear();
	while (iss >> token)
		formulas.push_back(token);
}

bool is_satisfiable(const vector<string>& formulas)
{
	int arr[26];

	for (size_t i = 0; i < formulas.size(); ++i)
	{
		fill(arr, arr + 26, 0);
		bool satisfiable = true;

		for (int j = 1; j + 1 < formulas[i].length(); ++j)
		{
			if (formulas[i][j] == '~')
			{
				++j;
				if (arr[formulas[i][j] - 'a'] == 1)
					satisfiable = false;
				arr[formulas[i][j] - 'a'] = -1;
			}
			else if (formulas[i][j] >= 'a' && formulas[i][j] <= 'z')
			{
				if (arr[formulas[i][j] - 'a'] == -1)
					satisfiable = false;
				arr[formulas[i][j] - 'a'] = 1;
			}
		}

		if (satisfiable) return true;
	}
	return false;
}

int main()
{
	vector<string> formulas;
	string s;
	int tests;

	cin >> tests;
	while (tests--)
	{
		cin >> s;
		split(s, '|', formulas);
		if (is_satisfiable(formulas))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}