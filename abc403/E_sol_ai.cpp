#include <bits/stdc++.h>
using namespace std;

struct Trie {
    vector<int> ch;
    int zt, ans, fa;
    Trie() : ch(26, 0), zt(0), ans(0), fa(0) {}
};

vector<Trie> t(1);

void insert(int d, const string& s) {
    int p = 0;
    for (char c : s) {
        if (t[p].zt == 1) return;
        int idx = c - 'a';
        if (!t[p].ch[idx]) {
            t.emplace_back();
            t[p].ch[idx] = t.size() - 1;
            t.back().fa = p;
        }
        p = t[p].ch[idx];
    }
    if (t[p].zt == 1) return;
    if (d == 1) {
        t[p].zt = 1;
        if (t[p].ans > 0) {
            int del = t[p].ans;
            t[p].ans = 0;
            while (p) {
                p = t[p].fa;
                t[p].ans -= del;
            }
        }
    } else {
        t[p].ans++;
        while (p) {
            p = t[p].fa;
            t[p].ans++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int opt;
        string s;
        cin >> opt >> s;
        insert(opt, s);
        cout << t[0].ans << '\n';
    }
    return 0;
}