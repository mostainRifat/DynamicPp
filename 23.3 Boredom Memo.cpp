// https://codeforces.com/contest/456/problem/C

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N], alex[N];

int game(int n)
{
    if (n == 1)
        return alex[1];
    if(dp[n] != -1)
        return dp[n];
    
    int deleteit = alex[n] + game(n-2);
    int skipit = game (n-1);

    int ans = max(deleteit,skipit);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> alex[i];
        dp[i] = -1;
    }
    cout << game(n) << endl;
}