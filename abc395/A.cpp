#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    for(auto &i : a)cin>>i;
    for(int i = 1;i<n;i++){
        if(a[i] <= a[i-1]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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
