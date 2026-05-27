#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define all(x) begin(x), end(x)

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ===============================
    // 1. Basic Lambda
    // ===============================
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << add(2, 3) << "\n";

    // ===============================
    // 2. Capture Variables
    // ===============================
    int x = 10;

    // Capture by value
    auto f1 = [x]() {
        return x + 5;
    };

    // Capture by reference
    auto f2 = [&x]() {
        x += 5;
    };

    f2();
    cout << x << "\n"; // 15

    // ===============================
    // 3. Lambda inside sort
    // ===============================
    vector<pair<int,int>> v = {{1,5}, {2,3}, {1,2}};

    sort(all(v), [](auto &a, auto &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    // ===============================
    // 4. Custom comparator (priority_queue)
    // ===============================
    auto cmp = [](int a, int b) {
        return a > b; // min heap
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    pq.push(5);
    pq.push(2);
    pq.push(8);

    // ===============================
    // 5. Recursive Lambda (IMPORTANT)
    // ===============================
    function<int(int)> fact = [&](int n) {
        if(n <= 1) return 1LL;
        return n * fact(n - 1);
    };

    cout << fact(5) << "\n";

    // ===============================
    // 6. DFS Lambda (Graph)
    // ===============================
    int n = 5;
    vector<vector<int>> adj(n);

    function<void(int,int)> dfs = [&](int u, int p) {
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
        }
    };

    dfs(0, -1);

    // ===============================
    // 7. Inline Lambda (one-time use)
    // ===============================
    cout << [](int a, int b) {
        return a * b;
    }(3, 4) << "\n";

    // ===============================
    // 8. Lambda with auto return (C++14+)
    // ===============================
    auto maxx = [](auto a, auto b) {
        return a > b ? a : b;
    };

    cout << maxx(5, 9) << "\n";

    // ===============================
    // 9. Modify container with lambda
    // ===============================
    vector<int> a = {1,2,3,4};

    for_each(all(a), [](int &x) {
        x *= 2;
    });

    // ===============================
    // 10. Binary search condition lambda
    // ===============================
    int target = 10;

    auto check = [&](int mid) {
        return mid * mid >= target;
    };

    int l = 0, r = 100, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << "\n";

    return 0;
}