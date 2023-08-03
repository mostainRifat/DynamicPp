// Problem Link- http://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
/*
- State: fun(n,x) -> maximum happiness till day -n
                    if we pick task - x on day -n

- Recurrance: fun(n,x) = max{
                            fun (n-1 , y) where x!= y
                            + happiness[n][x] }

- Base case: Fun (1,x) = happiness[n][x]
*/ 

int happiness[N][4], dp[N][4];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> happiness[i][j];
        }
    }
    // 1. handle base case
    for (int task = 1; task <= 3; task++)
    {
        dp[1][task] = happiness[1][task];
    }

    // 2. Loop over the steps
    for (int day = 1; day <= n; day++)
    {
        for (int cTask = 1; cTask <= 3; cTask++)
        {
            // Calculate answer from smaller sub problem
            int max_profit = -1;
            for (int lTask = 1; lTask <= 3; lTask++)
            {
                if (lTask != cTask)
                {
                    int cProfit = dp[day - 1][lTask] + happiness[day][cTask];
                    max_profit = max(max_profit, cProfit);
                }
            }
            dp[day][cTask] = max_profit;
        }
    }
    
    int ans = max({dp[n][1],dp[n][2],dp[n][3]});
    cout<<ans << endl;
    return 0;
}