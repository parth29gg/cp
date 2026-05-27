#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// order_of_key(x): number of elements strictly smaller than x
// find_by_order(k): iterator to k-th smallest element (0-indexed)
template <class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ordered_set<int> s;

    // Insert elements
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    // order_of_key(x): number of elements strictly smaller than x
    cout << "order_of_key(25) = " << s.order_of_key(25) << "\n"; // 2
    cout << "order_of_key(30) = " << s.order_of_key(30) << "\n"; // 2

    // find_by_order(k): iterator to k-th smallest element (0-indexed)
    cout << "find_by_order(0) = " << *s.find_by_order(0) << "\n"; // 10
    cout << "find_by_order(2) = " << *s.find_by_order(2) << "\n"; // 30

    // Normal set operations also work
    if (s.find(20) != s.end()) cout << "20 is present\n";
}
