#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    bool found = false;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == n){
            found = true;
            break;
        }

        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(!found){
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> route;

    for(int v  = n; v != -1; v = parent[v]){
        route.push_back(v);
    }
    
    reverse(route.begin(), route.end());

    cout << route.size() << endl;

    for(int node : route){
        cout << node << " ";
    }

    return 0;
}