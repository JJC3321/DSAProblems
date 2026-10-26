#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); 
        in_degree[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        topo_order.push_back(curr);
        for (int neighbor : adj[curr]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    vector<int> dp(n + 1, 0);
    for (int u : topo_order) {
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    int max_len = 0;
    for (int i = 1; i <= n; i++) {
        max_len = max(max_len, dp[i]);
    }

    cout << max_len;

    return 0;
}