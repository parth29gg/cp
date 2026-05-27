#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > adj;
vector<int> sub, vis;

void dfs(int u, int p){
    sub[u] = 1;

    for(auto v : adj[u]){
        if(v == p) continue;

        dfs(v, u);
        sub[u] += sub[v];
    }
}

void solve(){
    int n;
    cin >> n;

    adj.assign(n + 1, {});
    sub.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);   // root at 1

    // sub[x] = subtree size of node x
}