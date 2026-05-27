#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int n, m;
vector<vector<int>> adj, rev_adj;
vector<int> vis, order;
vector<vector<int>> sccs;

// 1st DFS -> store finish order
void dfs1(int u)
{
    vis[u] = 1;

    for (auto v : adj[u])
    {
        if (!vis[v])
            dfs1(v);
    }

    order.pb(u);
}

// 2nd DFS on reversed graph -> collect SCC
void dfs2(int u, vector<int> &comp)
{
    vis[u] = 1;
    comp.pb(u);

    for (auto v : rev_adj[u])
    {
        if (!vis[v])
            dfs2(v, comp);
    }
}

void kosaraju()
{
    vis.assign(n + 1, 0);
    order.clear();

    // Step 1: Topological finishing order
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }

    // Step 2: Reverse finishing order
    vis.assign(n + 1, 0);
    reverse(all(order));

    // Step 3: DFS on reversed graph
    for (auto node : order)
    {
        if (!vis[node])
        {
            vector<int> comp;
            dfs2(node, comp);
            sccs.pb(comp);
        }
    }
}

void solve()
{
    cin >> n >> m;

    adj.assign(n + 1, {});
    rev_adj.assign(n + 1, {});

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        rev_adj[v].pb(u);
    }

    kosaraju();

    cout << "Number of SCCs = " << sccs.size() << "\n";

    for (int i = 0; i < (int)sccs.size(); i++)
    {
        cout << "SCC " << i + 1 << ": ";
        for (auto node : sccs[i])
            cout << node << " ";
        cout << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}