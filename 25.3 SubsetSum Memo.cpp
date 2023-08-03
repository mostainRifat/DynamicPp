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

int subset_sum(int n, int target)
{
    // Base case
    if (n == 0)
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }

    // if result calculated
    if (dp[n][target] != -1)
        return dp[n][target];

    // calculate result from smaller steps
    int ans1 = subset_sum(n - 1, target);
    if (target < nums[n])
    {
        dp[n][target] = ans1;
        return ans1;
    }
    
    int ans2 = subset_sum(n - 1, target - nums[n]);
    int ans = ans1 || ans2;
    dp[n][target] = ans;
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << subset_sum(n, target) << endl;
    return 0;
}