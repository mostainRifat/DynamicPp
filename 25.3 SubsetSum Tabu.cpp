#include <bits/stdc++.h>
using namespace std;
/*
    -state: fun(n,target) -> returns true if it is possibel to
            create a subset from numbers 1 to n and form the sum
            "target"
    - recurrance : fun(n, target ) -> fun(n-1,target) Or
                        fun(n-1, target-nums[n] if target >= nums[n])

    - base case : fun (0 , target) -> if target == 0 return 1
                                       else return 0

*/
const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    dp[0][0] = 1;

    for (int i = 1; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int target = 1; target <= m; target++)
        {
            int ans1 = dp[i - 1][target];
            if (target < nums[i])
            {
                dp[i][target] = ans1;
            }
            else
            {
                int ans2 = dp[i - 1][target - nums[i]];
                dp[i][target] = ans1 or ans2;
            }
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}