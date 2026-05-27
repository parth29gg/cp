#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

#define pb push_back
#define all(x) begin(x), end(x)

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    map<int,int> freq;   // freq[value] = count in current window
    map<int,int> cnt;    // cnt[f] = how many values appear exactly f times

    vector<int> ans;
    int maxi = 0;

    auto add = [&](int x) {
        int old = freq[x];

        if (old > 0) cnt[old]--;

        freq[x]++;
        cnt[old + 1]++;

        maxi = max(maxi, old + 1);
    };

    auto remove = [&](int x) {
        int old = freq[x];

        cnt[old]--;

        freq[x]--;

        if (freq[x] > 0)
            cnt[old - 1]++;

        while (maxi > 0 && cnt[maxi] == 0)
            maxi--;
    };

    // first window
    for (int i = 0; i < k; i++)
        add(arr[i]);

    ans.pb(maxi);

    // slide window
    for (int i = k; i < n; i++) {
        remove(arr[i - k]);
        add(arr[i]);
        ans.pb(maxi);
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    fast_io;
    solve();
    return 0;
}