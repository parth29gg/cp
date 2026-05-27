#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>> &adj)
{
    vector<int> indeg(n,0);

    // compute indegree
    for(int u=0;u<n;u++)
        for(int v:adj[u])
            indeg[v]++;

    queue<int> q;

    // push nodes with indegree 0
    for(int i=0;i<n;i++)
        if(indeg[i]==0)
            q.push(i);

    vector<int> topo;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        topo.push_back(u);

        for(int v:adj[u])
        {
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }

    return topo;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);   // u -> v
    }

    vector<int> ans = topoSort(n,adj);

    for(int x:ans)
        cout<<x<<" ";
}