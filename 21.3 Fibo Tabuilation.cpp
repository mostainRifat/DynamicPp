#include<bits/stdc++.h>
using namespace std;

const int N=101;
/* 
- fib(n) -> calculate the nth value
- fib(n) -> fib(n-1) + fib (n-2)
- fib(1) = 1; fib(2) = 1;
*/

int dp[N]; // dp array

int main()
{
    int n;
    cin >>n;
    //1. Base case
    dp[1] = 1;
    dp[2] = 1;

    // 2. Loop through the states
    for(int i=3;i<=n;i++)
    {
        //Calculate the answer from the smaller sub-problem
        dp[i]  = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;
}