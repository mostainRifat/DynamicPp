#include<bits/stdc++.h>
using namespace std;
const int N= 1e5 +5;
int dp[N],alex[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>alex[i];
    
    dp[0] = 0;
    //dp[1] = alex[1];

    for(int i=2;i<=n;i++)
    {
        int deleteit = alex[i] + dp[i-2];
        int skipit = dp[i-1];
        dp[i] = max(deleteit,skipit);
    }

    cout<<dp[n]<<endl;
}