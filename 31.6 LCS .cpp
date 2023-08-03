#include <bits/stdc++.h>
using namespace std;
const int N = 3003;

int dp[N][N];
int n, m;
string s, t;

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for (int i = 0; i <= n; i++)
        dp[i][m] = 0;

    for (int j = 0; j <= m; j++)
        dp[n][j] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    string lcs = "";
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            lcs += s[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] >= dp[i][j + 1])
            i++;
        else
            j++;
    }
    cout << lcs << endl;

    return 0;
}
