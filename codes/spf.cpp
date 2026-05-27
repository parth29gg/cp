#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define nl cout << endl

using vi = vector<int>;
using vvi = vector<vector<int>>;

const int INF = (int)4e18;
const int MOD = 1e9 + 7;

/* ---------------- SPF ---------------- */

const int MAXA = 1000005;
int spf[MAXA];

void build_spf() {
    for (int i = 1; i < MAXA; i++) spf[i] = i;

    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

/* -------- Factorization helpers -------- */

// unique primes
vi get_primes(int x) {
    vi primes;
    while (x > 1) {
        int p = spf[x];
        primes.pb(p);
        while (x % p == 0) x /= p;
    }
    return primes;
}

// all primes (with repetition)
vi get_all_primes(int x) {
    vi primes;
    while (x > 1) {
        primes.pb(spf[x]);
        x /= spf[x];
    }
    return primes;
}

// map: prime -> count
map<int,int> get_factorization(int x) {
    map<int,int> mp;
    while (x > 1) {
        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
}

/* ---------------- Solve ---------------- */

void solve() {
    int x;
    cin >> x;

    // unique primes
    vi primes = get_primes(x);

    // all primes
    vi allp = get_all_primes(x);

    // map
    auto mp = get_factorization(x);

    // print (demo)
    cout << "Unique primes: ";
    for (auto p : primes) cout << p << ' ';
    nl;

    cout << "All primes: ";
    for (auto p : allp) cout << p << ' ';
    nl;

    cout << "Factorization: ";
    for (auto [p, cnt] : mp) {
        cout << p << "^" << cnt << ' ';
    }
    nl;
}

/* ---------------- Main ---------------- */

int32_t main() {
    fast_io;

    build_spf(); // IMPORTANT

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}