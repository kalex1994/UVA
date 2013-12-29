#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s && s != "~")
	{
		string bits; char flag;
		do
		{
			if (s != "#")
			{
				if (s.length() == 1) flag = '1';
				else if (s.length() == 2) flag = '0';
				else bits.append(s.length() - 2, flag);
			}
		} while (cin >> s && s != "#");

		reverse(bits.begin(), bits.end());
		int power = 1, answer = 0;
		for (int i = 0; i < (int)bits.length(); ++i)
		{
			answer += bits[i] == '1' ? power : 0;
			power *= 2;
		}
		cout << answer << endl;
	}
	return 0;
}