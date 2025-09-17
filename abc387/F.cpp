#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2030;
// 呃,因为空间不足wa了一发

const int MOD = 998244353;
/*
先tarjan缩点,然后树形dp
*/
int n, m;
vector<int> g[N];  // 原图
int f[N][N];       // 表示第i个scc,当前取值<=j时的情况总和
// 可以直接乘上所有子树的情况,但是需要前缀和累加才是真的
int low[N], dfn[N], scc[N], instk[N], in[N];
int dfi, num;
stack<int> st;
int head[N], cnt;
struct edge {
    int to, nxt;
} e[N];  // 缩点之后的图,因为是单向边所以不需要空间*2

void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++dfi;
    st.push(x);
    instk[x] = 1;
    for (int y : g[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if (dfn[x] == low[x]) {
        num++;
        while (st.top() != x) {
            int u = st.top();
            st.pop();
            scc[u] = num;
            instk[u] = 0;
        }
        scc[x] = num;
        instk[x] = 0;
        st.pop();
    }
}

void dfs(int x) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        dfs(y);
        for (int j = 1; j <= m; j++) {
            f[x][j] = f[x][j] * f[y][j] % MOD;  // 乘上所有子树的数量
        }
    }
    for (int i = 2; i <= m; i++) {  // 累加前缀和
        f[x][i] = (f[x][i] + f[x][i - 1]) % MOD;
    }
}

void solve() {
    // int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        g[t].push_back(i);  // a[i] <= a[t], 建立单向边
        for (int j = 1; j <= m; j++) {
            f[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int y : g[i]) {
            if (scc[y] == scc[i]) continue;
            add(scc[i], scc[y]);  // 方向搞反了
            in[scc[y]] = 1;       // 标记这个scc有入度
        }
    }

    int ans = 1;
    for (int i = 1; i <= num; i++) {
        if (!in[i]) {  // 是根节点
            dfs(i);
            ans = ans * f[i][m] % MOD;  // 构造的数列限制在m以下
        }
    }
    cout << ans << '\n';
}

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
