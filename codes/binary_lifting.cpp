#include <bits/stdc++.h>
using namespace std;

struct BinaryLifting {
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;
    // vector<long long> dist_to_root; // Uncomment for weighted trees

    // Initialize dynamically to avoid TLE on multi-testcases
    BinaryLifting(int n, int root, const vector<vector<int>>& adj) {
        this->n = n;
        LOG = 32 - __builtin_clz(n);
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        dfs(root, -1, adj);
    }

    void dfs(int v, int p, const vector<vector<int>>& adj) {
        up[v][0] = p;
        for (int j = 1; j < LOG; j++) {
            if (up[v][j - 1] != -1)
                up[v][j] = up[up[v][j - 1]][j - 1];
        }

        for (int u : adj[v]) {
            if (u != p) {
                depth[u] = depth[v] + 1;
                // dist_to_root[u] = dist_to_root[v] + weight; // For weighted
                dfs(u, v, adj);
            }
        }
    }

    int kth_ancestor(int v, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                v = up[v][j];
                if (v == -1) return -1;
            }
        }
        return v;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        u = kth_ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        // return dist_to_root[u] + dist_to_root[v] - 2 * dist_to_root[lca(u,v)]; // For weighted
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Instantiating calculates everything automatically
    BinaryLifting bl(n, 1, adj);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << bl.lca(u, v) << '\n';
    }
}