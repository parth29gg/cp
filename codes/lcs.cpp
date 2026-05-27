#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n) - 1; i >= 0; i--)
#define repab(i, a, b) for (int i = (a); i <= (b); i++)
#define perab(i, a, b) for (int i = (a); i >= (b); i--)
#define lb(x) __builtin_ctzll(x)
#define ub(x) (63 - __builtin_clzll(x))
#define popc(x) __builtin_popcountll(x)

#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define err cout << "err\n"
#define nl cout << endl
#define vcout(a)           \
    for (auto &it : a)     \
    {                      \
        cout << it << ' '; \
    }                      \
    nl;

using vi = vector<int>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
using vpi = vector<pair<int, int>>;
using vvpi = vector<vector<pair<int, int>>>;
using tiii = tuple<int, int, int>;

class Solution
{
public:
    /*


    */
    int lcs(string &s1, string &s2)
    {
        // code here
        int n1 = s1.size();
        int n2 = s2.size();

        vvi dp(n1 + 1, vi(n2 + 1, 0)); // lcs 0...i && lcs 0 ... j

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
