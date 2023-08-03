// Problem Link- http://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 2e9;
/*
-state: stone(n) -> cost of n-th stone from 1st stone

- recurrance: stone(n) = for i=1 to k
                    min (
                        stone(n-i) + abs(h[n]-h[n-i]) )

- Base case: Stone(1) = 0
*/ 
int h[N], dp[N];
int n,k;

int main()
{
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
        cin>>h[i];

    //1. Base case
    dp[1]= 0;

    //2. Loop over the states
    for(int i=2;i<=n;i++)
    {
        dp[i] = inf;
        //2.1 Calculate answer from smaller subproblem
        for(int j=1;j<=k;j++)
        {
            // from stone (i-j)
            // to stone i
            if(i-j <= 0)
                break;
            
            
            int candidate_ans = dp[i-j] + abs(h[i]-h[i-j]);
            dp[i] = min (dp[i] , candidate_ans);
        }
    }

    cout<<dp[n]<<endl;
}