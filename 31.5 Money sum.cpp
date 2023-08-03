//https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    set<int> sums;
    sums.insert(0);
    
    for (int i = 0; i < n; i++)
    {
        vector<int> newSum;
        for (int it : sums)
            newSum.push_back(it + coins[i]);

        for (int it : newSum)
            sums.insert(it);
    }
    sums.erase(0);
    cout << sums.size() << endl;
    for (int it : sums)
        cout << it << " ";
}
