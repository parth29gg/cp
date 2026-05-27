#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

const int MOD = 1e9 + 7;
const int INF = (long long)4e18;

/*---------------------------------------------------------------*
|                GENERAL CONTRIBUTION TEMPLATE                   |
|  Use for problems where:                                      |
|  Answer = Sum(value(item) * frequency(item))                  |
*---------------------------------------------------------------*/

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;

    /*===========================================================
      TEMPLATE 1 : ARRAY ELEMENT CONTRIBUTION TO ALL SUBARRAYS
      element a[i] appears in (i+1)*(n-i) subarrays
    ===========================================================*/

    for (int i = 0; i < n; i++)
    {
        int freq = (i + 1) * (n - i);
        ans += a[i] * freq;
    }

    cout << ans << '\n';
}

/*---------------------------------------------------------------*
|                TREE CONTRIBUTION TEMPLATE                      |
|  Each edge contributes sz * (n - sz)                          |
*---------------------------------------------------------------*/

vector<vector<int>> adj;
vector<int> sub;
vector<int> contrib;

void dfs(int u, int p, int n)
{
    sub[u] = 1;

    for (auto v : adj[u])
    {
        if (v == p) continue;

        dfs(v, u, n);

        sub[u] += sub[v];

        contrib.pb(sub[v] * (n - sub[v]));
    }
}

void solve_tree()
{
    int n;
    cin >> n;

    adj.assign(n, {});
    sub.assign(n, 0);
    contrib.clear();

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, -1, n);

    int ans = 0;
    for (auto x : contrib) ans += x;

    cout << ans << '\n';
}

/*---------------------------------------------------------------*
|                BIT CONTRIBUTION TEMPLATE                       |
|  XOR sum of all pairs                                          |
*---------------------------------------------------------------*/

void solve_bits()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;

    for (int bit = 0; bit < 61; bit++)
    {
        int one = 0, zero = 0;

        for (auto x : a)
        {
            if ((x >> bit) & 1) one++;
            else zero++;
        }

        ans += one * zero * (1LL << bit);
    }

    cout << ans << '\n';
}

/*---------------------------------------------------------------*
|                PAIR DIFFERENCE CONTRIBUTION                    |
|  Sum of |a[j]-a[i]| over all pairs                            |
*---------------------------------------------------------------*/

void solve_pairs()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(all(a));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += a[i] * i;
        ans -= a[i] * (n - i - 1);
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();   // replace with needed solve function
}