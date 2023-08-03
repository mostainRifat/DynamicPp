//https://leetcode.com/problems/perfect-squares/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int inf = 1e9;
int dp[N] , per[N];

int perfect(int n)
{
    if (n<=0)
        return 0;
    if(dp[n] != -1)
        return dp[n];

    int ans = inf;

    for (int i = 1; i * i <= n; i++)
    {
        int perfectSquare = i * i;
        ans = min(ans, perfect(n - perfectSquare) + 1);
    }
    return dp[n] = ans;  
}

int main()
{
    int n;
    cin>> n;
    for(int i=0;i<= n;i++)
        dp[i] = -1;
    cout<<perfect(n)<<endl;
    return 0;
}