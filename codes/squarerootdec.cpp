#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Sqrt {
    int n, B;
    vector<int> a, blk;

    Sqrt(vector<int> v) : a(v) {
        n = a.size();
        B = sqrt(n) + 1;
        blk.assign(B + 1, 0);

        for(int i = 0; i < n; i++)
            blk[i / B] += a[i];
    }

    int query(int l, int r) {
        int sum = 0;

        while(l <= r) {
            if(l % B == 0 && l + B - 1 <= r)
                sum += blk[l / B], l += B;
            else
                sum += a[l++];
        }

        return sum;
    }

    void update(int i, int val) {
        blk[i / B] += val - a[i];
        a[i] = val;
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    Sqrt sq(a);

    while(q--) {
        int t; cin >> t;

        if(t == 1) {
            int i, v;
            cin >> i >> v;
            sq.update(i, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << sq.query(l, r) << '\n';
        }
    }
}