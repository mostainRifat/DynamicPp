#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int dp[N];

int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int minus = dp[i - 1];
        int d2 = (i % 2 == 0) ? i / 2 : INT_MAX;
        int d3 = (i % 3 == 0) ? i / 3 : INT_MAX;

        dp[i] = 1 + min(minus, min(d2, d3));
    }
    cout << dp[n] -1 << endl;
}