#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;

struct braille_digit
{
	string rows[3];
	braille_digit() {}
	braille_digit(const string& r1, const string& r2, const string& r3) 
	{
		rows[0] = r1; rows[1] = r2; rows[2] = r3; 
	}
	bool operator==(const braille_digit& other) const
	{
		return rows[0] == other.rows[0] && rows[1] == other.rows[1] && rows[2] == other.rows[2];
	}
};

braille_digit braille[10] = {
	braille_digit(".*", "**", ".."), braille_digit("*.", "..", ".."), braille_digit("*.", "*.", ".."),
	braille_digit("**", "..", ".."), braille_digit("**", ".*", ".."), braille_digit("*.", ".*", ".."),
	braille_digit("**", "*.", ".."), braille_digit("**", "**", ".."), braille_digit("*.", "**", ".."), 
	braille_digit(".*", "*.", ".."),
};

void print_braille_number(const vector<braille_digit>& digits)
{
	for (int row = 0; row < 3; ++row)
	{
		for (size_t i = 0; i < digits.size(); ++i)
		{
			if (i > 0) cout << ' ';
			cout << digits[i].rows[row];
		}
		cout << endl;
	}
}

void print_decimal_number(const braille_digit& bd)
{
	for (int i = 0; i < 10; ++i)
	if (braille[i] == bd)
	{
		cout << i;
		return;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int d;
	char type;

	while (cin >> d && d)
	{
		cin >> type;

		if (type == 'S')
		{
			vector<braille_digit> digits;
			string num;

			cin >> num;
			for (size_t i = 0; i < num.length(); ++i)
				digits.push_back(braille[num[i] - '0']);
			print_braille_number(digits);
		}
		else
		{
			vector<braille_digit> digits(d);

			for (int row = 0; row < 3; ++row)
				for (int i = 0; i < d; ++i)
					cin >> digits[i].rows[row];

			for (size_t i = 0; i < digits.size(); ++i)
				print_decimal_number(digits[i]);
			cout << endl;
		}
	}
}