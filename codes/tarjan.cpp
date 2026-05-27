#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpi = vector<pii>;
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); ++i)

vvi adj;
vi tin, low, vis, cut;
vpi bridge;
int timer;

void dfs(int u,int p){

    vis[u]=1;
    tin[u]=low[u]=timer++;
    int child=0;

    for(auto v:adj[u]){

        if(v==p) continue;

        if(vis[v]){
            low[u]=min(low[u],tin[v]);
        }
        else{

            dfs(v,u);

            low[u]=min(low[u],low[v]);

            // bridge
            if(low[v] > tin[u])
                bridge.pb({u,v});

            // articulation point (non-root)
            if(p!=-1 && low[v] >= tin[u])
                cut[u]=1;

            child++;
        }
    }

    // articulation point (root)
    if(p==-1 && child>1)
        cut[u]=1;
}

void tarjan(int n){

    tin.assign(n,0);
    low.assign(n,0);
    vis.assign(n,0);
    cut.assign(n,0);
    bridge.clear();
    timer=0;

    rep(i,n)
        if(!vis[i])
            dfs(i,-1);
}