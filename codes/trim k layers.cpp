#include <vector>
#include <queue>

using namespace std;

vector<int> trimTree(int n, vector<vector<int>>& edges, int k) {
    vector<int> degree(n, 0);
    vector<vector<int>> adj(n);

    // Build adjacency list and calculate initial degrees
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    queue<int> leaves;
    // Push all initial leaves into the queue
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) leaves.push(i);
    }

    // Peel off leaves layer by layer, k times
    while (k-- > 0 && !leaves.empty()) {
        int size = leaves.size();
        for (int i = 0; i < size; i++) {
            int u = leaves.front(); leaves.pop();
            degree[u]--; // Mark current leaf as removed
            
            // Decrease degree of neighbors and queue new leaves
            for (int v : adj[u]) {
                if (--degree[v] == 1) leaves.push(v);
            }
        }
    }

    vector<int> remainingNodes;
    // Collect all nodes that survived the trimming
    for (int i = 0; i < n; i++) {
        if (degree[i] > 0 || (n == 1 && k < 0)) remainingNodes.push_back(i);
    }
    
    return remainingNodes;
}