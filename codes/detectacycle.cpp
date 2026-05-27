#include <bits/stdc++.h>
using namespace std;

void detectacycleingraph() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(N, 0);
    bool ok = false;

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;

        for (int v : g[u]) {
            if (vis[v] == 0) dfs(v);
            else if (vis[v] == 1) ok = true;
            if (ok) return;
        }

        vis[u] = 2;
    };

    for (int city = 0; city < N; city++) {
        if (vis[city] == 0) dfs(city);
        if (ok) break;
    }

    cout << (ok ? "Yes" : "No") << "\n";
}