#include<bits/stdc++.h>
using namespace std;

const int MAXN = 205;

vector<int> key[MAXN];
int m[MAXN];
int n, k;
string s;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            key[x].clear();
            key[x].push_back(i);
            m[x] = i;
        }

        for (int i = 1; i <= n; ++i)
        {
            while(true)
            {
                int next = m[key[i].back()];
                if (next == key[i][0])
                    break;
                key[i].push_back(next);
            }
        }

        while(scanf("%d%*c", &k) && k)
        {
            getline(cin, s);
            s.append(n - s.length(), ' ');

            --k;
            for(int i = 1; i <= n; ++i)
            {
                int ind = k % key[i].size();
                putchar(s[ key[i][ind] - 1 ]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
}
