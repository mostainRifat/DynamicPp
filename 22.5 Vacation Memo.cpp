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

int fun(int day , int currentTask)
{
    //1. handle base case
    if(day == 1)
        return happiness[day][currentTask];

    // 2. if answer is already calculated return it 
    if(dp[day][currentTask] != -1)
        return dp[day][currentTask];

    int max_profit = 0;

    // 3. Calculate the answer from smaller sub problems
    for(int last_task = 1;last_task<= 3;last_task++)
    {
        if (last_task != currentTask)
        {
            int candidate_profit = fun (day -1 , last_task) + happiness[day][currentTask];
            max_profit = max(max_profit , candidate_profit);
        }
    }

    dp[day][currentTask]  = max_profit;
    return max_profit;
}

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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
            dp[i][j] = -1;
    }

    int ans_1= fun(n,1);
    int ans_2= fun(n,2);
    int ans_3= fun(n,3);

    cout<<max({ans_1,ans_2,ans_3})<<endl;
    return 0;
}
