//https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 105;
const int X = 1e5;

int dp[X];
int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= coins[j])
            {
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}
