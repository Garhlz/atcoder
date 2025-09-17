#include <bits/stdc++.h>
using namespace std;
char mp[128];  // 映射：x -> y
bool f[128];   // 标记 T 中出现的字符
bool v[128];   // DFS 访问标记
int n;
string s, t;
int rt, ans;          // rt：当前连通分量根，ans：操作次数
vector<int> in[128];  // 反向边：y -> {x1, x2, ...}

void dfs(int x) {
    if (x == 0) return;      // 无映射，终止
    if (v[x]) {              // 已访问
        if (x == rt) ans++;  // 回到起点，形成环，操作数+1
        return;
    }
    v[x] = 1;
    dfs(mp[x]);  // 递归访问下一个字符
}

signed main() {
    cin >> n;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;  // 1-based 索引
    for (int i = 1; i <= n; i++) {
        if (mp[s[i]] && mp[s[i]] != t[i]) {  // 映射冲突
            cout << -1;
            return 0;
        }
        mp[s[i]] = t[i];  // 建立映射
        f[t[i]] = 1;      // 标记 T 中字符
    }
    int cnt = 0;
    for (int i = 'A'; i <= 'z'; i++) cnt += f[i];  // 统计 T 中字符种类
    if (cnt == 26 && s != t) {                     // 所有字母占用且 S != T
        cout << -1;
        return 0;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (mp[i] == i) mp[i] = 0;  // 自环清零
        ans += (bool)(mp[i]);       // 有映射，初始操作+1
        in[mp[i]].push_back(i);     // 反向边
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (in[i].size() >= 2) {  // 入度 >= 2，先处理合并点
            if (!v[i]) dfs(i);
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (!v[i]) {  // 未访问的点
            rt = i;
            dfs(i);
        }
    }
    cout << ans;
}