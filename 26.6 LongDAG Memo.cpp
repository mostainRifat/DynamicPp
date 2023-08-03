#include <bits/stdc++.h>
using namespace std;
/*
- state: f(n) -> longest distance from root to node n
- recurance: f(n) -> max{f(p_1),f(p_2),....f(p_m)} +1
                    where p_i is an immediate parent of node n
-base case: f(root) = 0;

node ------> child 1, child 2.....
child -----> [parent1,parent2.....]

*/
const int N = 1e5 + 5;
vector<int> parent_list[N];
int dp[N];
int root, target_node;

int max_distance(int node)
{
    if (node == root)
        return 0;
    if(dp[node] != -1)
        return dp[node];

    int ans = 0;
    for(int parent: parent_list[node])
    {
        int parent_distance = max_distance(parent);
        ans = max(ans, parent_distance);
    }
    dp[node] = ans+1;
    return dp[node];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for(int i=1;i<= n;i++)
        dp[i]=-1;

    cin>>root>>target_node;
    cout<<max_distance(target_node)<<endl;

    return 0;
}