#include <bits/stdc++.h>
using namespace std;
const int N = 3003;
/*
- state: LCS (i ,j ) -> Length of longest common subsequence
                        between strings s[i..n] ans t[j..m]

- Recurrance: LCS(i,j) = 1+LCS(i+1 , j+2) if(s[i] == t[j])
                        else max{LCS(i+1,j) , LCS(i , j+1)}

- base : LCS (i,m)  = 0
         LCS (n, j) = 0

*/
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

    for(int i= n-1 ; i>=0 ; i--)
    {
        for(int j= m-1 ;j >= 0 ; j--)
        {
            if(s[i] == t[j])
                dp[i][j] = 1+ dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            
        }
    }
    cout<<dp[0][0]<<endl;

    return 0;
}