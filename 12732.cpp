#include<bits/stdc++.h>
using namespace std;

int query(int left, int right)
{
    printf("%s", "Test");
    for(int i = left; i <= right; ++i)
        printf(" %d", i);
    putchar('\n');
    fflush(stdout);

    int result;
    scanf("%d", &result);
    return result;
}

int get_fake_coin(int left, int right)
{
    int n = right - left + 1;

    if (n == 1)
        return left;
    if (n == 2)
        return query(left, right) > 0 ? left : right;
    if (n == 3)
    {
        int result = query(left, right - 1);
        return result > 0 ? left : (result < 0 ? right - 1 : right);
    }

    int result = query(left, left + 2 * (n / 3) - 1);
    if (result > 0)
        return get_fake_coin(left, left + n / 3 - 1);
    else if (result < 0)
        return get_fake_coin(left + n / 3, left + 2 * (n / 3) - 1);
    else
        return get_fake_coin(left + 2 * (n / 3), right);
}

void solve(int n)
{
    printf("Answer %d\n", get_fake_coin(1, n));
    fflush(stdout);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    int tests, n;

    scanf("%d", &tests);
    while(tests--)
    {
        scanf("%d", &n);
        solve(n);
    }
}
