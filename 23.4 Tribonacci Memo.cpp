//https://leetcode.com/problems/n-th-tribonacci-number/

#include<bits/stdc++.h>
using namespace std;
const int N= 1e5;
int dp[N];

int tib(int n)
{
    if (n == 2 || n==1) return 1;
    if (n == 0) return 0;
    
    if(dp[n] != -1)
    {
        return dp[n]; 
    }
    int ans = tib(n-1) + tib(n-2) + tib(n-3);
    dp [n] = ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n ;i++)
        dp[i] = -1;
    
    cout<<tib(n)<<endl;
}