#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

struct morphing
{
	char word[10000];
	int diff;
};

int wdiff(char *w, char *s)
{
	int diff = 0;
	int len = strlen(w);

	for(int i = 0; i < len; ++i)
		if (w[i] != s[i])
			++diff;

	return diff;
}

bool cmp(const morphing *a, const morphing *b)
{
	if (a->diff < b->diff)
		return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int n, l;
	char buffer[1000];
	vector<morphing*> m;

	while(scanf("%d %d", &n, &l) == 2)
	{
		for(size_t i = 0; i < m.size(); ++i)
			delete m[i];
		m.clear();

		while(n--)
		{
			scanf("%s", buffer);
			morphing *mor = new morphing;
			strcpy(mor->word, buffer);
			m.push_back(mor);
		}

		for(size_t i = 0; i < m.size(); ++i)
			m[i]->diff = wdiff(m[0]->word, m[i]->word);

		sort(m.begin(), m.end(), cmp);

		for(size_t i = 0; i < m.size(); ++i)
			puts(m[i]->word);
	}
}