#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
同样字母对应的位置一定相同,否则不可

*/
int vis[26];
vector<int> a[26];  // 存储同一个目标的所有字母
vector<int> v[26];
int huan, need;
vector<int> cur;

void dfs(int x, int f) {  // 第一次进入的时候不是这样
    for (auto y : v[x]) {
        if (y == f) continue;
        if (vis[y]) {
            huan++;
            int flag = 0;
            for (auto t : cur) {
                if (a[t].size() > 1) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) need++;  // 需要的空闲的
            return;
        }
        vis[y] = 1;
        cur.push_back(y);
        dfs(y, x);
        cur.pop_back();
    }
}
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, char> mp;

    for (int i = 0; i < n; i++) {
        char now = s[i];
        if (!mp[now]) {
            mp[now] = t[i];
            a[t[i] - 'a'].push_back(now - 'a');
            v[s[i] - 'a'].push_back(t[i] - 'a');
            v[t[i] - 'a'].push_back(s[i] - 'a');
        } else {
            if (t[i] != mp[now]) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    int cnt = 0;  // 空闲的
    // 这里理解错误了.空闲字符应是t中没有被映射过的字符,而不是s的
    for (int i = 0; i < 26; i++) {
        char now = i + 'a';
        if (!mp[now]) cnt++;
    }

    for (int i = 0; i < 26; i++) {
        if (vis[i]) continue;
        if (vis[mp[i + 'a'] - 'a']) continue;

        vis[i] = 1, vis[mp[i + 'a'] - 'a'] = 1;
        cur.push_back(i);
        cur.push_back(mp[i + 'a'] - 'a');
        dfs(mp[i + 'a'] - 'a', i);
        cur.pop_back();
        cur.pop_back();
    }
    if (need > cnt) {
        cout << -1 << '\n';
    }

    int ans = 0;

    ans += mp.size() + huan;

    cout << ans << '\n';
}
/*
成环就要减掉,看有无空闲(s中没有出现过的),任意一个有无同类
*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
4
acbd
bbca
*/