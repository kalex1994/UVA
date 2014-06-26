#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

typedef unsigned long long ull;

map<char, string> rules;
ull freq[256];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	int tests, r, q;

	scanf("%d", &tests);
	while(tests--)
	{
		rules.clear();

		scanf("%d", &r);
		while(r--)
		{
			char buffer[110];
			scanf("%s", buffer);
			rules[buffer[0]] = string(buffer + 3);
		}

		scanf("%d", &q);
		while(q--)
		{
			char s[110], ch;
			int n;

			scanf("%s %c %d", s, &ch, &n);
			memset(freq, 0, sizeof(freq));

			for(int i = 0; i < strlen(s); ++i)
				++freq[s[i]];

			while(n--)
			{
				unsigned long long new_freq[256] = {0};
	
				memcpy(new_freq, freq, sizeof(freq));
				for(map<char, string>::iterator it = rules.begin(); it != rules.end(); ++it)
					new_freq[it->first] = 0;

				for(map<char, string>::iterator it = rules.begin(); it != rules.end(); ++it)
				{
					ull f = freq[it->first];
					freq[it->first] = 0;
					for(int i = 0; i < it->second.length(); ++i)
						new_freq[it->second[i]] += f;
				}

				memcpy(freq, new_freq, sizeof(freq));			
			}

			printf("%llu\n", freq[ch]);
		}
	}
}