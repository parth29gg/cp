#include <bits/stdc++.h>
using namespace std;

struct item {
    int x;
    item(int val = 0) {
        x = val;
    }
    item operator+(const item &other) const {
        return item(x + other.x);
    }
};

class SegTree {
public:
    vector<item> seg;
    vector<int> lazy; // Stores pending updates

    SegTree(int n) {
        seg.assign(4 * n, item());
        lazy.assign(4 * n, 0);
    }

    // Pushes pending lazy updates to the current node and its children
    void push(int ind, int l, int r) {
        if (lazy[ind] != 0) {
            // Apply update to current node (multiplier needed for range sum)
            seg[ind].x += lazy[ind] * (r - l + 1); 
            if (l != r) { 
                // Pass the lazy tag to children
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0; // Clear the tag
        }
    }

    void build(int ind, int l, int r, const vector<int>& a) {
        if(l == r) {
            seg[ind] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * ind + 1, l, mid, a);
        build(2 * ind + 2, mid + 1, r, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    item query(int ind, int l, int r, int ql, int qr) {
        push(ind, l, r); // Resolve pending updates before querying
        if(qr < l || r < ql) return item();
        if(ql <= l && r <= qr) return seg[ind];
        
        int mid = (l + r) >> 1;
        return query(2 * ind + 1, l, mid, ql, qr) + 
               query(2 * ind + 2, mid + 1, r, ql, qr);
    }

    // Upgraded to range update (ql to qr) instead of point update
    void update(int ind, int l, int r, int ql, int qr, int val) {
        push(ind, l, r); // Resolve pending updates before going deeper
        if(qr < l || r < ql) return;
        
        if(ql <= l && r <= qr) {
            lazy[ind] += val; // Stage the update and apply it
            push(ind, l, r);
            return;
        }
        
        int mid = (l + r) >> 1;
        update(2 * ind + 1, l, mid, ql, qr, val);
        update(2 * ind + 2, mid + 1, r, ql, qr, val);
        
        // Recalculate current node based on updated children
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; 
    }
};