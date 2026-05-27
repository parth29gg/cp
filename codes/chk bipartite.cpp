#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int> adj[], vector<int> &color) {
    color[node] = col;

    for (auto it : adj[node]) {
        if (color[it] == -1) {
            if (!dfs(it, 1 - col, adj, color))
                return false;
        }
        else if (color[it] == col) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0, adj, color))
                return false;
        }
    }

    return true;
}

int main() {
    int V = 4;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    if (isBipartite(V, adj))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is Not Bipartite";
}