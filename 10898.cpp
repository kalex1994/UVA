#include<bits/stdc++.h>
using namespace std;

const int MAXITEMS = 6;
const int MAXCOMBOS = 8;

int items, combos, orders, answer;
int item_price[MAXITEMS];
int combo[MAXCOMBOS][MAXITEMS], combo_price[MAXCOMBOS];
int order[MAXITEMS], current[MAXITEMS];

bool can_buy_combo(int quantity[], int pos)
{
    for(int i = 0; i < items; ++i)
        if (quantity[i] + combo[pos][i] > order[i])
            return false;
    return true;
}

void solve(int price)
{
    bool found_combo = false;
    for(int i = 0; i < combos; ++i)
    {
        if (can_buy_combo(current, i))
        {
            found_combo = true;
            for(int j = 0; j < items; ++j)
                current[j] += combo[i][j];

            solve(price + combo_price[i]);

            for(int j = 0; j < items; ++j)
                current[j] -= combo[i][j];
        }
    }

    if (!found_combo)
    {
        for(int i = 0; i < items; ++i)
            price += (order[i] - current[i]) * item_price[i];
        answer = min(answer, price);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:\\IN.txt", "r", stdin);
    //freopen("E:\\OUT.txt", "w", stdout);
#endif

    while(scanf("%d", &items) == 1)
    {
        for(int i = 0; i < items; ++i)
            scanf("%d", &item_price[i]);

        scanf("%d", &combos);
        for(int i = 0; i < combos; ++i)
        {
            for(int j = 0; j < items; ++j)
                scanf("%d", &combo[i][j]);
            scanf("%d", &combo_price[i]);
        }

        scanf("%d", &orders);
        for(int i = 0; i < orders; ++i)
        {
            for(int j = 0; j < items; ++j)
                scanf("%d", &order[j]);

            answer = INT_MAX;
            solve(0);
            printf("%d\n", answer);
        }
    }
}
