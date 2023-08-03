#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int level[N];
vector<pair<int, int>> ad_jcen[N];
bool visited[N];

int dijkstra(int n, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    pq.push({0, k});
    dist[k] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : ad_jcen[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            return -1; // It is impossible for all nodes to receive the signal
        }
        max_time = max(max_time, dist[i]);
    }
    return max_time;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ad_jcen[u].push_back({v, w});
    }

    int k;
    cin >> k;

    int result = dijkstra(n, k);
    cout << result << endl;

    return 0;
}
