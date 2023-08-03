//https://www.spoj.com/problems/FARIDA/en/

#include<bits/stdc++.h>
using namespace std;
const int N= 1e5;
int dp[N];
int coin[N];

int mons(int n)
{
    if (n<= 0)
        return 0;
    
    int ans=0;

    if(dp[n] != -1)
    {
        return dp[n]; 
    }
    
    int ans_1 = mons(n-1);
    int ans_2 = coin[n] + mons(n-2);

    ans= max(ans_1, ans_2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>coin[i];
        for(int i=1;i<=n;i++)
        dp[i] =-1; 

        int ans = mons(n);
        cout<<"Case "<<k<<": "<< ans<<endl;
    }
    return 0;
}