// link -> https://lightoj.com/problem/coin-change-i

#include <bits/stdc++.h>
using namespace std;
/*
-state: dp(n,k) -> number of ways to make sum = K from coins 1 to n without crossing limit
_recurrance: dp(n,k) -> dp(n-1 , k):
                        dp(n-1 , k - coin[n])
                        dp(n-1 , k-2 * coin[n])
                        ......
                        dp(n-1 , k-limit[n] * coin[n])
- base-case: dp(0,0) = 1;

*/
const int N = 60;
const int M = 1001;
const int MOD = 10000007;

int dp[N][M];
int coin[N], limit[N];

int main()
{
    int t, tst = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            cin >> coin[i];

        for (int i = 1; i <= n; i++)
            cin >> limit[i];

        for(int i=0 ;i<=n;i++)
        {
            for(int target = 0 ; target <= k;target ++)
            dp[i][target] = 0;

        }

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int target = 0; target <= k; target++)
            {
                dp[i][target] = dp[i - 1][target];
                for (int j = 1; j <= limit[i]; j++)
                {
                    if (target < j * coin[i])
                        break;
 
                    int ret = dp[i - 1][target - j * coin[i]];
                    dp[i][target] = (dp[i][target] + ret) % MOD;
                }
            }
        }

        cout << "Case " << ++tst << ": " << dp[n][k] << endl;
    }
    return 0;
}