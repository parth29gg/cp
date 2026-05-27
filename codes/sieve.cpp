#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

using vi = vector<int>;

///////////////////////////////////////////////////////////////
// ⭐ STANDARD SIEVE — O(n log log n)
// Best for: prime checking, prime list
///////////////////////////////////////////////////////////////

vector<bool> is_prime;
vector<int> primes_basic;

void sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes_basic.push_back(i);
            if ((long long)i * i <= n) {
                for (long long j = 1LL * i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }
}

///////////////////////////////////////////////////////////////
// ⭐ LINEAR SIEVE (SPF) — O(n)
// Best for: fast factorization
///////////////////////////////////////////////////////////////

vector<int> spf;      // smallest prime factor
vector<int> primes;   // prime list

void linear_sieve(int n) {
    spf.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > spf[i] || 1LL * p * i > n) break;
            spf[p * i] = p;
        }
    }
}

///////////////////////////////////////////////////////////////
// ⭐ FACTORIZATION using SPF — O(log n)
///////////////////////////////////////////////////////////////

vector<int> factorize(int x) {
    vector<int> f;
    while (x > 1) {
        f.push_back(spf[x]);
        x /= spf[x];
    }
    return f;
}

///////////////////////////////////////////////////////////////
// ⭐ Example solve()
///////////////////////////////////////////////////////////////

void solve() {
    int n;
    cin >> n;

    // Example: check prime using standard sieve
    if (n < (int)is_prime.size()) {
        cout << (is_prime[n] ? "Prime\n" : "Not Prime\n");
    }

    // Example: factorize using linear sieve
    if (n < (int)spf.size()) {
        vector<int> f = factorize(n);
        cout << "Factors: ";
        for (int x : f) cout << x << ' ';
        cout << '\n';
    }
}

///////////////////////////////////////////////////////////////

int32_t main() {
    fast_io;

    int MAXN = 1e6;   // 🔧 change as needed

    sieve(MAXN);          // comment if not needed
    linear_sieve(MAXN);   // comment if not needed

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}