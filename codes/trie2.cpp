#include <bits/stdc++.h>
using namespace std;

struct Node {
    int nxt[26], cnt = 0, pass = 0;
    Node() { fill(nxt, nxt + 26, -1); }
};

struct Trie {
    vector<Node> t;

    Trie() { t.emplace_back(); }

    void insert(const string &s) {
        int cur = 0;
        t[cur].pass++;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[cur].nxt[c] == -1) {
                t[cur].nxt[c] = t.size();
                t.emplace_back();
            }
            cur = t[cur].nxt[c];
            t[cur].pass++;
        }
        t[cur].cnt++;
    }

    int cntPrefix(const string &s) {
        int cur = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[cur].nxt[c] == -1) return 0;
            cur = t[cur].nxt[c];
        }
        return t[cur].pass;
    }

    int cntEqual(const string &s) {
        int cur = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[cur].nxt[c] == -1) return 0;
            cur = t[cur].nxt[c];
        }
        return t[cur].cnt;
    }

    void erase(const string &s) {
        if (!cntEqual(s)) return;
        int cur = 0;
        t[cur].pass--;
        for (char ch : s) {
            cur = t[cur].nxt[ch - 'a'];
            t[cur].pass--;
        }
        t[cur].cnt--;
    }
};

void solve() {
    Trie trie;
    trie.insert("codeforces");
    trie.insert("coder");

    cout << trie.cntPrefix("code") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}