#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
#endif

    string down, up, message;
    getline(cin, down);
    getline(cin, up);

    while(getline(cin, message))
    {
        bool is_down_shifted = true;
        for(int i = 0; i < (int)message.length(); i += 5)
        {
            string code = message.substr(i, 5);
            if (code == "11011")
                is_down_shifted = true;
            else if (code == "11111")
                is_down_shifted = false;
            else
            {
                char decoded;
                if (is_down_shifted)
                    decoded = down[ stoi(code, nullptr, 2) ];
                else
                    decoded = up[ stoi(code, nullptr, 2) ];
                putchar(decoded);
            }
        }
        putchar('\n');
    }
}
