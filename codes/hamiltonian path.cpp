#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using vi = std::vector<int>;
using vvi = std::vector<vi>;
const int INF = 1e9;

// 1. Traveling Salesperson Problem (Min Cost Hamiltonian Path/Cycle)
// adj[i][j] holds edge weight. Use INF if no edge exists.
int tsp(int n, const vvi& adj, bool require_cycle = false) {
    vvi dp(1LL << n, vi(n, INF));
    rep(i, n) dp[1LL << i][i] = 0; 

    for (int mask = 1; mask < (1LL << n); mask++) {
        int curr = mask;
        while (curr > 0) {
            int u = __builtin_ctzll(curr);
            curr &= curr - 1; 

            int unset = ((1LL << n) - 1) ^ mask;
            while (unset > 0) {
                int v = __builtin_ctzll(unset);
                unset &= unset - 1; 
                
                // Transition to unvisited node v
                if (adj[u][v] != INF) {
                    dp[mask | (1LL << v)][v] = min(dp[mask | (1LL << v)][v], dp[mask][u] + adj[u][v]);
                }
            }
        }
    }

    int ans = INF, full_mask = (1LL << n) - 1;
    rep(i, n) {
        if (require_cycle) {
            if (adj[i][0] != INF) ans = min(ans, dp[full_mask][i] + adj[i][0]);
        } else {
            ans = min(ans, dp[full_mask][i]);
        }
    }
    return ans;
}

// 2. Hamiltonian Path / Cycle Existence (or Longest Path)
// adj[i][j] = 1 if edge exists, 0 otherwise.
bool has_hamiltonian(int n, const vvi& adj, bool require_cycle = false) {
    vvi dp(1LL << n, vi(n, 0));
    // For cycles, fix start node 0 to avoid duplicates
    if (require_cycle) dp[1][0] = 1;
    else rep(i, n) dp[1LL << i][i] = 1;

    for (int mask = 1; mask < (1LL << n); mask++) {
        int curr = mask;
        while (curr > 0) {
            int u = __builtin_ctzll(curr);
            curr &= curr - 1;

            if (!dp[mask][u]) continue;

            int unset = ((1LL << n) - 1) ^ mask;
            while (unset > 0) {
                int v = __builtin_ctzll(unset);
                unset &= unset - 1;
                
                // Transition to unvisited connected node
                if (adj[u][v]) dp[mask | (1LL << v)][v] = 1;
            }
        }
    }

    int full_mask = (1LL << n) - 1;
    rep(i, n) {
        if (dp[full_mask][i]) {
            if (!require_cycle || adj[i][0]) return true;
        }
    }
    return false;
}

// 3. Counting Total Valid Hamiltonian Paths
// Returns total paths. Modulo logic can be added inside the inner loop.
int count_hamiltonian_paths(int n, const vvi& adj) {
    vvi dp(1LL << n, vi(n, 0));
    rep(i, n) dp[1LL << i][i] = 1;

    for (int mask = 1; mask < (1LL << n); mask++) {
        int curr = mask;
        while (curr > 0) {
            int u = __builtin_ctzll(curr);
            curr &= curr - 1;

            if (!dp[mask][u]) continue;

            int unset = ((1LL << n) - 1) ^ mask;
            while (unset > 0) {
                int v = __builtin_ctzll(unset);
                unset &= unset - 1;
                
                // Add paths leading up to u to the new state ending at v
                if (adj[u][v]) dp[mask | (1LL << v)][v] += dp[mask][u];
            }
        }
    }

    int total_paths = 0, full_mask = (1LL << n) - 1;
    rep(i, n) total_paths += dp[full_mask][i];
    
    return total_paths;
}
