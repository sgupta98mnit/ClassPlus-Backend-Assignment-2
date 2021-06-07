#include<bits/stdc++.h>
using namespace std;
void dfs(int v, int dist, vector<vector<int>>& adj, vector<int>& count, vector<bool>& visited) {
    if(dist < 0 || visited[v] == true)
        return;

    visited[v] = true;
    ++count[v];
    for(auto x : adj[v]) {
        dfs(x, dist - 1, adj, count, visited);
    }
}


int main() {
    int n;
    int h;
    int x;

    cin >> n >> h >> x;

    vector<int> hotspots(h);

    for(int i = 0; i < h; ++i)
        cin >> hotspots[i];

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; ++i) {
        int x;
        int y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> count(n + 1);
    for(int i = 0; i < h; ++i) {
        vector<bool> visited(n + 1);
        dfs(hotspots[i], x, adj, count, visited);
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        if(count[i] == h)
            ++ans;
    }
    cout << ans << "\n";
}

