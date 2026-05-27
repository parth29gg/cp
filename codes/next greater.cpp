#include <bits/stdc++.h>
using namespace std;

#define int long long

/* =========================================================
   MONOTONIC STACK TEMPLATES
   ========================================================= */

// Next Greater to Right (strictly greater)
vector<int> next_greater_right(vector<int>& a) {
    int n = a.size();
    vector<int> next(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return next;
}

// Next Greater to Left
vector<int> next_greater_left(vector<int>& a) {
    int n = a.size();
    vector<int> prev(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            prev[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return prev;
}

// Next Smaller to Right
vector<int> next_smaller_right(vector<int>& a) {
    int n = a.size();
    vector<int> next(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return next;
}

/* =========================================================
   JUMP POINTER (DP JUMPING)
   ========================================================= */

// Next Greater to Right (strictly greater)
vector<int> next_greater_jump(vector<int>& a) {
    int n = a.size();
    vector<int> next(n, n);

    for (int i = n - 1; i >= 0; --i) {
        next[i] = i + 1;

        while (next[i] != n && a[i] >= a[next[i]]) {
            next[i] = next[next[i]];
        }
    }
    return next;
}

// Next Smaller to Right
vector<int> next_smaller_jump(vector<int>& a) {
    int n = a.size();
    vector<int> next(n, n);

    for (int i = n - 1; i >= 0; --i) {
        next[i] = i + 1;

        while (next[i] != n && a[i] <= a[next[i]]) {
            next[i] = next[next[i]];
        }
    }
    return next;
}

/* =========================================================
   USAGE EXAMPLE
   ========================================================= */

int32_t main() {
    vector<int> a = {5, 3, 8, 2, 7};

    auto ngr = next_greater_right(a);
    auto ngl = next_greater_left(a);
    auto nsr = next_smaller_right(a);

    auto ngr_jump = next_greater_jump(a);
    auto nsr_jump = next_smaller_jump(a);

    // Print example
    cout << "Next Greater Right:\n";
    for (auto x : ngr) cout << x << " ";
    cout << "\n";

    cout << "Next Greater Right (Jump):\n";
    for (auto x : ngr_jump) cout << x << " ";
    cout << "\n";

    return 0;
}