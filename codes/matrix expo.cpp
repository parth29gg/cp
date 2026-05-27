#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define perab(i,a,b) for(int i=(a);i>=(b);i--)
#define lb(x) __builtin_ctzll(x)
#define ub(x) (63 - __builtin_clzll(x))
#define popc(x) __builtin_popcountll(x)

#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define err cout << "err\n"
#define nl cout <<endl
#define vcout(a) for(auto &it:a){cout<<it<<' ';}nl;

using vi = vector<int>;
using pi = pair<int,int>;
using vvi = vector<vector<int>>;
using vpi = vector<pair<int,int>>;
using vvpi = vector<vector<pair<int,int>>>;
using tiii = tuple<int,int,int>;

template<class T> using max_pq = priority_queue<T>;
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

const int INF = (int)4e18;
//const int MOD = 1e9+7;
//const int MOD = 998244353;
/*

*/
struct Matrix {
    vvi a;
    int n;
    vector<int>& operator[](int i) {
        return a[i];
    }
    Matrix(int sz, bool ident = false) {
        n = sz;
        a.assign(n, vector<int>(n, 0));

        if(ident)
            rep(i,n) a[i][i] = 1;
    }
    Matrix operator*(const Matrix& o) const {
        Matrix res(n);
        rep(i,n) {
            rep(j,n) {
                rep(k,n) {
                    res.a[i][j] += a[i][k] * o.a[k][j];

                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix base, int exp) {
    Matrix res(base.n, true);
    while(exp) {
        if(exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}
void solve() {
    
    
    
}

int32_t main() {
    fast_io;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}