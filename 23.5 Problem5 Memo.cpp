#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int dp[N];

int step(int n)
{
    if(n==1)
        return 1;
    if(dp[n] != -1)
        return dp[n];

    int minus = step(n-1);
    int d2 = (n% 2== 0) ? step(n/2) : INT_MAX;
    int d3 = (n% 3 ==0 ) ? step(n/3) : INT_MAX;

    dp[n] = 1+ min(minus,min(d2,d3));
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<= n;i++)
        dp[i]= -1;

    cout<<step(n)<<endl;
    return 0;
}