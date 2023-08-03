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

int stone(int n)
{
    //1. Base case
    if(n==1)
        return 0;
    
    //2. if answer is already calculated return it
    if(dp[n] != -1)
        return dp[n];
 
    //3. calculate answer from smaller sub problem
    int ans = inf;
    for(int i=1;i<=k;i++)
    {
        //Handle corner case
        if(n-i<= 0)
            break;

        int candidate_ans = stone(n-i) + abs(h[n]-h[n-i]);
        ans = min (ans , candidate_ans);
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>h[i];

    for(int i=1;i<= n;i++)
            dp[i] =-1 ;

    cout<<stone(n)<<endl;
    return 0;
}