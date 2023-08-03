#include<bits/stdc++.h>
using namespace std;
const int N = 3003;

/*  
-state: lcs(i,j) -> Length of the longest common subsequnece
                    between strings s[0..i] and t[0...i]
- Recurrance : lcs(i,j) -> 1+lcs(i-1) if s[i] == t[j]
                        else max{lcs(i-1,j) , lcs(i,j-1)}
- Base: lcs(i,0) = 0
        lcs(0,j) = 0

*/

int dp[N][N];
int n ,m;
string s,t;

int main()
{
    cin>>s>>t;
    
    n=s.size();
    m=t.size();

    for(int i=0 ;i<= n;i++)
        dp[i][0] = 0 ;
    
    for(int j=0; j<= m ; j++)
        dp[0][j] = 0;

    for(int i=1 ;i<=n ; i++)
    {
        for(int j=1;j<=m ; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);          
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}