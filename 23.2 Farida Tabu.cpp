#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N], coin[N];

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> coin[i];
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (n == 1)
            {
                dp[i] = coin[1];
                continue;
            }

            int ans_1 = dp[n - 1];
            int ans_2 = coin[n] + dp[n - 2];

            dp[i] = max(ans_1, ans_2);
        }

        cout << "Case " << k << ": " << dp[n] << endl;
    }
    return 0;
}