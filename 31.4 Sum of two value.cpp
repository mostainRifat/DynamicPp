//https://cses.fi/problemset/task/1640/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1;i<= n ; i++)
    {
        for(int j = i+1 ; j<= n;j++)
        {
            if(arr[i]+arr[j]==x && arr[i] != arr[j])
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
