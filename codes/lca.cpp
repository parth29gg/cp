#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct LCA {
    int n, max_log;
    vector<int> depth;
    vector<vector<int>> up;

    LCA(int n, const vector<vector<int>>& adj, int root = 0) : n(n) {
        max_log = log2(n) + 1;
        depth.assign(n, 0);
        up.assign(n, vector<int>(max_log, -1));
        
        // If the graph is a forest, loop through all nodes
        for (int i = 0; i < n; i++) {
            if (i == root || (root == 0 && up[i][0] == -1)) {
                dfs(i, -1, 0, adj);
            }
        }
    }

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < max_log; i++) {
            if (up[u][i - 1] != -1)
                up[u][i] = up[up[u][i - 1]][i - 1];
            else
                up[u][i] = -1;
        }
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1, adj);
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        // 1. Bring u up to the same depth as v
        for (int i = max_log - 1; i >= 0; i--) {
            if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // 2. Lift both nodes together until they are just below the LCA
        for (int i = max_log - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int get_dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
    }
};