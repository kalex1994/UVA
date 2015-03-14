#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    freopen("E:\\OUT.txt", "w", stdout);
#endif

    string line;
    while(getline(cin, line))
    {
        int max_space_count = 0;
        int space_count = 0;

        for(char ch : line)
            if (ch == ' ')
                ++space_count;
            else
            {
                max_space_count = max(max_space_count, space_count);
                space_count = 0;
            }
        printf("%d\n", (int)ceil(log2(max_space_count)));
    }
}
