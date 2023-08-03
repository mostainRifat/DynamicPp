// https://codeforces.com/contest/1829/problem/E
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1002;
bool visited[N][N];
int grid[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool insidethemaze(pair<int, int> src);
int Dfs(pair<int, int> src);

int dfs(pair<int, int> src)
{
    if (!visited[src.first][src.second] && grid[src.first][src.second] > 0)
    {
        return Dfs(src);
    }
    return 0;
}

int Dfs(pair<int, int> src)
{
    visited[src.first][src.second] = true;
    int x = src.first;
    int y = src.second;
    int volume = grid[x][y];
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        pair<int, int> ad_node = {new_x, new_y};
        if (insidethemaze(ad_node) && !visited[new_x][new_y] && grid[new_x][new_y] > 0)
        {
            volume += Dfs(ad_node);
        }
    }
    return volume;
}

bool insidethemaze(pair<int, int> src)
{
    if (src.first >= 0 && src.first < n && src.second >= 0 && src.second < m)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }

        int max_volume = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pair<int, int> src = {i, j};
                max_volume = max(max_volume, dfs(src));
            }
        }

        cout << max_volume << endl;
    }

    return 0;
}
