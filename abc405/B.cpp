#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int,2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> cnt(m+1),a(n+1);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i<=m;i++){
        if(cnt[i] == 0){
            cout<<"0\n";
            return;
        }
    }
    int ans = 0;
    for(int i = n;i>=1;i--){
        cnt[a[i]]--;
        ans++;
        if(cnt[a[i]] == 0){
            cout<<ans<<'\n';
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
