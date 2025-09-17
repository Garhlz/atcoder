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
    int r,x;
    cin>>r>>x;
    if(x == 1){
        if(r >= 1600 && r <= 2999)cout<<"Yes\n";
        else cout<<"No\n";
    }
    else{
        if(r >= 1200 && r <= 2399)cout<<"Yes\n";
        else cout<<"No\n";
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
