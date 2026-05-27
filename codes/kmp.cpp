#include <bits/stdc++.h>
using namespace std;

void constructLps(string &pat, vector<int> &lps) {
    int len = 0, i = 1, m = pat.size();
    lps[0] = 0;
    while (i < m) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.size(), m = pat.size();
    vector<int> lps(m), res;
    constructLps(pat, lps);
    for (int i = 0, j = 0; i < n;) {
        if (txt[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else if (j) j = lps[j - 1];
        else i++;
    }
    return res;
}

int main() {
    string txt = "aabaacaadaabaaba", pat = "aaba";
    for (int x : search(pat, txt)) cout << x << " ";
}
