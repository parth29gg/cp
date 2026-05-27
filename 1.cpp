#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
struct SRD {
    int n, B;
    string s;
    vvi blk;
    SRD(string s1) {
        s = s1;
        n = s.size();
        B = sqrt(n) + 1;
        blk.assign(B + 1, vi(26, 0));
        rep(i,n) {
            blk[i / B][s[i] - 'a']++;
        }
    }
    int query(int l, int r, char ch) {
        int ans = 0;
        while(l <= r) {
            if(l % B == 0 && l + B - 1 <= r) {
                ans += blk[l / B][ch - 'a'];
                l += B;            }
            else {
                ans += (s[l] == ch);
                l++;            }        }
        return ans;
    }
    void update(int i, char c) {
        blk[i / B][s[i] - 'a']--;
        blk[i / B][c - 'a']++;
        s[i] = c;    }};
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    int q;
    cin>>q;
    SRD srd(s);
    rep(i,q){
        int type;
        cin>>type;
        if(type==1){
            int pos;
            char c;
            pos--;
            cin>>pos>>c;
            srd.update(pos,c);
        }
        else{
            int l,r;
            char c;
            cin>>l>>r>>c;
            l--;r--;
            cout<<srd.query(l,r,c)<<endl;
        }
    }
}

int32_t main() {
    fast_io;
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}