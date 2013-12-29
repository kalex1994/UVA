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
#include <cctype>
#include <cstdio>
#include <limits>
#include <list>
#include <sstream>
using namespace std;

const int MAX_LEN = 100 + 5;

void read_until(char s[], char d)
{
	int ch, index = 0;
	while ((ch = getchar()) != d)
		s[index++] = ch;
	s[index] = '\0';
}

void read(char s1[], char s2[], char s3[], char s4[], char s5[], char line2[])
{
	read_until(s1, '<');
	read_until(s2, '>');
	read_until(s3, '<');
	read_until(s4, '>');
	read_until(s5, '\n');
	read_until(line2, '.');
	char temp[MAX_LEN];
	read_until(temp, '\n');
}

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("D:\\IN", "r", stdin);
	freopen("D:\\OUT", "w", stdout);
#endif

	char s1[MAX_LEN], s2[MAX_LEN], s3[MAX_LEN], s4[MAX_LEN], s5[MAX_LEN], line2[MAX_LEN];
	int n;

	scanf("%d%*c", &n);
	while (n--)
	{
		read(s1, s2, s3, s4, s5, line2);
		printf("%s%s%s%s%s\n", s1, s2, s3, s4, s5);
		printf("%s%s%s%s%s\n", line2, s4, s3, s2, s5);
	}

	return 0;
} 

